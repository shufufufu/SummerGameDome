#include "stdafx.h"

// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

#define HEIGHT 720  // ��Ϸ����ߴ�
#define WIDTH 1280
#define PI 3.1415926

//����ɻ��Ľṹ��
struct aircraft
{
    int x ;
	int y;
	int width;
	int height;
	int speed;
	int life;
	int new_born_flg;
};
aircraft plane, ufoa, ufob, ufoc;

//�����Ľṹ��
struct vector
{
    float x, y;
};
//�����εĽṹ��
struct triangle
{
    float ax, ay, bx, by, cx, cy;
};

//�����ӵ��Ľṹ��, �������
typedef struct bullet
{
    float x, y;
    float vx, vy;
    int damage;//�˺�
	int isExist;//�ж��ӵ��Ƿ���Ҫɾ��
    struct bullet* pnext;//ָ����һ���ӵ��ڵ��ָ��
}list;//���ṹ����һ������list,ͷ�����Ա�ʾ�б����Ϣ

list* plane_bullet_list = NULL; // �ɻ��ӵ��б��ͷ�ڵ�
list* ufob_bullet_list = NULL;  //UFOB���ӵ��б�Ŀ�ͷ
list* ufoa_bullet_list = NULL;  //UFOA���ӵ��б�Ŀ�ͷ

IMAGE img_bk, img_plane,temp_img,
	img_ufoa,img_ufob,img_ufoc,
	img_plane_bullet,img_ufoa_bullet,img_ufob_bullet;

int PLANE_LIFE = 100;
int UFOA_LIFE = 1500;
int UFOB_LIFE = 150;
int UFOC_LIFE = 100;


//���������ö���б�
enum GAMEINPUT
{
	NOINPUT = 0X0,
	UPINPUT = 0X1,
	DOWNINPUT = 0X2,
	LEFTINPUT = 0X4,
	RIGHTINPUT = 0X8,
	FIREINPUT = 0X10
};
int input = NOINPUT;//�ж��������
int speed = 10;
int score = 0;//�洢��õķ���
int game_over = 0;//���ֽ�����־

void dataInit();
void loadRes();
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
void showAircraft();
void getInput();
void dealInput();
void ctrlFps(int start_time);
void ufoaMove();
void ufobMove();
void ufocMove();
void showBullet();
void listPushBack(list** pplist, list* newNode);
list* creatPlaneBullet(float vx, float vy);
list* creatUFOA_Bullet(float vx, float vy);
list* creatUFOB_Bullet(float vx, float vy);
void listChangeXY(list** pplist);
void listRemoveNode(list** pplist);

void aircraftReborn(aircraft* tmp, int life);
void aircraftLifeJudge();

//������������غ���
vector getVector(float x1, float y1, float x2, float y2);//��������
float crossProduct(vector a, vector b);//2�������Ĳ��
int isPointInTriangle(triangle tri, float x, float y);//�жϵ�(x,y)�Ƿ�����������
triangle getPlaneTriangle();//����һ�������Σ�������ײ�ж�

//��ײ��غ���
void bulletHitPlane(list* bullet_list);//�ж�UFO���ӵ��Ƿ���зɻ�
void bulletHitUFO(aircraft* tmp);//�жϷɻ����ӵ��Ƿ����UFO
void ufoCrash(aircraft* tmp);//UFO�Ƿ���ɻ���ײ
void ufosCrashJudge();//����UFO�Ƿ���ɻ���ײ

void showScore(int x, int y, int score);//��ʾ����
void showLife(int x, int y, int life);
void showBeginPicture();//��������
void showGameOver();//��������

//������Ч����
void playBgmMusic();
void playBoomMusic();
void playBoom2Music();
void playBoom3Music();
void playShootMusic();

int _tmain(int argc, _TCHAR* argv[])
{
	dataInit();//��ʼ�����зɻ������÷ɻ�����
	initgraph(WIDTH, HEIGHT);// ������ͼ����
	loadRes();
	clock_t start_time;
	showBeginPicture();
	BeginBatchDraw();
	srand(time(NULL));
	while(1)
	{
		ufoaMove();
		ufobMove();
		ufocMove();
		start_time = clock();
		getInput(); //��ȡ����
		dealInput();//�����ɻ�λ��
		showAircraft();//��ʾ�ɻ�
		showBullet();
		putimage(0, 0, &temp_img);
		showScore(550, 0, score);//��ʾ����
		aircraftLifeJudge();//�ɻ������ж�
		ufosCrashJudge();//�ɻ��л���ײ�ж�
		ctrlFps(start_time);//����Fps��60����
		showLife(1000, 0, plane.life);//��ʾ����
		FlushBatchDraw();
		if (game_over)
            showGameOver();
	}
	EndBatchDraw();
    char ch = _getch();
    closegraph();

	return 0;
}

//�ɻ����ݳ�ʼ��
void dataInit()
{
	//VS 2010 ������C11�����ԶԽṹ������帳ֵֻ���ڱ�����ʼ��ʱ
	plane.x = 150;
	plane.y = 150;
	plane.width = 80;
	plane.height = 80;
	plane.speed = 10;
	plane.new_born_flg = 1;
	plane.life = PLANE_LIFE;

	ufoa.x = 0;
	ufoa.y = 0;
	ufoa.width = 300;
	ufoa.height = 150;
	ufoa.speed = 1;
	ufoa.new_born_flg = 1;
	ufoa.life = UFOA_LIFE;

	ufob.x = 300;
	ufob.y = 0;
	ufob.width = 150;
	ufob.height = 50;
	ufob.speed = 4;
	ufob.new_born_flg = 1;
	ufob.life = UFOB_LIFE;

	ufoc.x = 450;
	ufoc.y = 0;
	ufoc.width = 100;
	ufoc.height = 60;
	ufoc.speed = 8;
	ufoc.new_born_flg = 1;
	ufoc.life = UFOC_LIFE;
	/*
	// VS2019 ����ʹ��������䣬�Խṹ�����帳ֵ
	plane = { 150,150 };
    ufoa = { 0,0 };
    ufob = { 300,0 };
    ufoc = { 450,0 };
	*/
}

//�����·�����������ز�
void loadRes()
{
    loadimage(&img_bk, _T("res\\background.png"));
	loadimage(&temp_img, _T("res\\background.png"));
    loadimage(&img_plane, _T("res\\plane.png"));
	loadimage(&img_ufoa, _T("res\\ufoa.png"));
	loadimage(&img_ufob, _T("res\\ufob.png"));
	loadimage(&img_ufoc, _T("res\\ufoc.png"));
	loadimage(&img_plane_bullet, _T("res\\plane_bullet.png"));
	loadimage(&img_ufoa_bullet, _T("res\\ufoa_bullet.png"));
	loadimage(&img_ufob_bullet, _T("res\\ufob_bullet.png"));
}

// ����͸���Ȼ�ͼ
void drawAlpha(IMAGE *dstimg, int x, int y, IMAGE *srcimg)
{
	// ������ʼ��
	DWORD *dst = GetImageBuffer(dstimg);
	DWORD *src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// ������ͼ��ʵ�ʳ���
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// �������ұ߽�
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// �������±߽�
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// ��������߽�
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// �������ϱ߽�

	// ������ͼ��ʼλ��
	dst += dst_width * y + x;
	// ʵ��͸����ͼ
	for (int iy = 0; iy < iheight; ++iy)
	{
		for (int i = 0; i < iwidth; ++i)
		{
			int sa = ((src[i] & 0xff000000) >> 24);//��ȡ������ֵ
			if (sa != 0)//��������ȫ͸���Ͳ�����
			if (sa == 255)//������ȫ��͸����ֱ�ӿ���
			dst[i] = src[i];
			else//������Ҫ��������ϼ����ͼ��߽�Ž��л��
			dst[i] = ((((src[i] & 0xff0000) >> 16) + ((dst[i] & 0xff0000) >> 16) * (255 - sa) / 255) << 16) |((((src[i] & 0xff00) >> 8) + ((dst[i] & 0xff00) >> 8) * (255 - sa) / 255) << 8) | ((src[i] & 0xff) + (dst[i] & 0xff) * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}
//�������еķɻ�
void showAircraft()
{
	drawAlpha(&temp_img,0, 0, &img_bk);
    drawAlpha(&temp_img,plane.x, plane.y, &img_plane);
	drawAlpha(&temp_img,ufoa.x, ufoa.y, &img_ufoa);
	drawAlpha(&temp_img,ufob.x, ufob.y, &img_ufob);
	drawAlpha(&temp_img,ufoc.x, ufoc.y, &img_ufoc);
}

//ͬʱ��ȡ������룬�����ɻ�
void getInput()
{
	int reload_time = 100;//�ɻ����ӵ��ļ��ʱ�䣬��λms
    static int fire_start = 0;//��̬���������濪���ʱ��
    int tmp = clock();
	if (GetAsyncKeyState('W') & 0x8000)
	{
		input |= UPINPUT;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		input |= DOWNINPUT;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		input |= LEFTINPUT;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		input |= RIGHTINPUT;
	}
	if (GetAsyncKeyState('K') & 0x8000)
	{
        if (tmp - fire_start >= reload_time)
        {
            input |= FIREINPUT;
            fire_start = tmp;
        }
	}
}

//ͬʱ���������룬�����ɻ���λ��
void dealInput()
{
    if ((input & UPINPUT) && (plane.y >= 0))
    {
        plane.y -= speed;
    }
    if ((input & DOWNINPUT) && (plane.y <= HEIGHT - 120))
    {
        plane.y += speed;
    }
    if ((input & LEFTINPUT) && (plane.x >= 0))
    {
        plane.x -= speed;
    }
    if ((input & RIGHTINPUT) && (plane.x <= WIDTH - 120))
    {
        plane.x += speed;
    }
	if (input & FIREINPUT)
    {
		playShootMusic();
		listPushBack(&plane_bullet_list, creatPlaneBullet(0, -20));//ˮƽ�������ٶȣ���ֱ�����ٶ�20
        listPushBack(&plane_bullet_list, creatPlaneBullet(-10, -17.32));//30��ɢ�� 20*cos30Լ����17.32
        listPushBack(&plane_bullet_list, creatPlaneBullet(10, -17.32));
    }

    input = NOINPUT;
}

//���ݴӿ�ʼ�����ڵ�ʱ�䣬�������ߵ�ʱ��
void ctrlFps(int start_time)
{
    clock_t running_time = clock() - start_time;
    if((13 - running_time) >= 0)//��ֹ˯�ߺ���ʹ�ø���
      Sleep(13 - running_time);//��̬˯��
    TCHAR time_text[50];
    int FPS = 1000 / (clock() - start_time);
    _stprintf_s(time_text, _T("FPS:%d"), FPS);
    settextstyle(60, 0, _T("����")); //Ϊ����ʾ����ʾfps�����С����̫��
    outtextxy(0, 0, time_text);
}

//UFOA������ǰ�ƶ�������һ����λ�û�ȥ,תȦ�����ӵ�
void ufoaMove()
{
	static int cnt = 0;
    static int dir = 1;//ǰ��
	int ufoa_reload_cnt = 80;//�����ӵ��ļ���������ֵԽС�����ӵ�Խ��
    int ufoa_fire_num = 20;  //UFOA���������·�ӵ�
    if (1 == ufoa.new_born_flg)//�³�����ufoa ������x,y������
    {
        ufoa.new_born_flg = 0;
        ufoa.x = rand() % (WIDTH - ufoa.width);
		ufoa.y = -50 ;
    }	
	if(ufoa.y > 200)//���������300����Ϊ����
	{
		dir = 0; //����
		
	}
	else if(ufoa.y < -150)
	{
		dir = 1;
		ufoa.new_born_flg = 1;	
	}

	if(dir == 1) //ǰ��
		ufoa.y += ufoa.speed;
	else  //����
		ufoa.y -= ufoa.speed;

	//cnt����ָ���ļ���Ժ�תȦ�����ӵ�
    if (++cnt % ufoa_reload_cnt == 0)
    {
        for (int i = 0; i < ufoa_fire_num; i++)
        {
            float angle = i * 2 * PI / ufoa_fire_num;
            float vx = 4 * sin(angle);
            float vy = 4 * cos(angle);
            listPushBack(&ufoa_bullet_list, creatUFOA_Bullet(vx, vy));
        }
    }
    if (cnt > 999999) cnt = 0;
}


//UFOB���ҿ����ƶ������������ƶ�
void ufobMove()
{
    static int step = ufob.speed;//spep��ʾ�������ٶ�
	static int cnt = 0;
	int ufob_reload_cnt = 60;//UFOb  �����ӵ��ļ���������ֵԽС�����ӵ�Խ��
    if (1 == ufob.new_born_flg)//�³�����ufob ������x,y������
    {
        ufob.new_born_flg = 0;
        ufob.x = rand() % (WIDTH - ufob.width);
        ufob.y = -ufob.height;
    }
    //ˮƽײǽ����
    if ((ufob.x <= 0) || (ufob.x + ufob.width >= WIDTH))
        step = -step;
    ufob.x += step;
    ufob.y++;
    //�����±߽磬������y�������ã�x�������
    if (ufob.y >= HEIGHT)
        ufob.new_born_flg = 1;
    if (++cnt % ufob_reload_cnt == 0)
    {
        listPushBack(&ufob_bullet_list, creatUFOB_Bullet(0, 5));
    }
    if (cnt > 999999) cnt = 0;//������������999999 ��������
}

//ufocײ��ɻ�
void ufocMove()
{
    static float dist_x = 0, dist_y = 0;//ufoc����ʱ����¼��ɻ��ĺ�������
    static float tmp_x = 0, tmp_y = 0; //����x,y�������ʱ�����������ͷ������
    static float vx = 0, vy = 0;
    float step = 1000 / ufoc.speed;      //����UFO�ٶ�
    if (1 == ufoc.new_born_flg)
    {
        ufoc.new_born_flg = 0;
        tmp_x = rand() % (WIDTH - ufoc.width);
        tmp_y = -ufoc.height;
        dist_x = plane.x - tmp_x;
        dist_y = plane.y - tmp_y;
        vx = dist_x / step;
        vy = dist_y / step;
    }
    tmp_x += vx;
    tmp_y += vy;
    ufoc.x = (int)(tmp_x + 0.5);
    ufoc.y = (int)(tmp_y + 0.5);
    //�߽��жϣ����Գ������棬��������̫��
    if (ufoc.x < -ufoc.width)
        ufoc.new_born_flg = 1;
    else if (ufoc.x > WIDTH+ufoc.width)
        ufoc.new_born_flg = 1;
    //�����±߽磬������y�������ã�x�������
    if (ufoc.y >= HEIGHT)
        ufoc.new_born_flg = 1;
}


//��ĳ����β������һ������
void listPushBack(list** pplist, list* newNode)
{
    if (*pplist == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
    {
        *pplist = newNode;
        return;
    }
    list* cur = *pplist;
    while (cur->pnext != NULL)//�ҵ����һ���ڵ�
    {
        cur = cur->pnext;
    }
    cur->pnext = newNode;//�����µĽڵ�
}

//�ɻ�������ӵ�������һ���ڵ�
list* creatPlaneBullet(float vx, float vy)
{
    list* p = (list*)malloc(sizeof(list));
    p->x = plane.x + plane.width / 2+10;//�ɻ�ͷ����λ��
    p->y = plane.y;
    p->vx = vx;
    p->vy = vy;//�ٶ�
	p->damage = 50;
    p->isExist = 1;
    p->pnext = NULL;
    return p;
}

//ufoa������ӵ�������һ���ڵ�
list* creatUFOA_Bullet(float vx, float vy)
{
    list* p = (list*)malloc(sizeof(list));
    p->x = ufoa.x + ufoa.width / 2;//�м�
    p->y = ufoa.y + ufoa.height;   //�·�
    p->vx = vx;
    p->vy = vy;//�ٶ�
	p->damage = 10;
    p->isExist = 1;
    p->pnext = NULL;
    return p;
}

//ufoB������ӵ�������һ���ڵ�
list* creatUFOB_Bullet(float vx, float vy)
{
    list* p = (list*)malloc(sizeof(list));
    p->x = ufob.x + ufob.width / 2;//�м�
    p->y = ufob.y + ufob.height;   //�·�
    p->vx = vx;
    p->vy = vy;//�ٶ�
	p->damage = 20;
    p->isExist = 1;
    p->pnext = NULL;
    return p;
}
//�޸�ĳ�������нڵ�����ꡣ
void listChangeXY(list** pplist)
{
    if (*pplist == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
        return;
    list* cur = *pplist;//curretָ���һ���ڵ�
    while (cur != NULL)//��������
    {
        cur->x += cur->vx;
        cur->y += cur->vy;
        //�ж��ӵ��Ƿ��뿪��Ұ
        if ((cur->y < -20)||(cur->y > HEIGHT)||(cur->x > WIDTH)||(cur->y < -20))
            cur->isExist = 0;
        cur = cur->pnext;//ָ����һ���ڵ�
    }
}
//ɾ��������isExistΪ0�Ľڵ�
void listRemoveNode(list** pplist)
{
    if (*pplist == NULL)//�������Ϊ�գ���û�п�ɾ���Ľڵ���
        return;
    list* cur = *pplist;//curret��ָ���һ���ڵ�
    list* prev = NULL;  //previousָ����һ���ڵ��ָ��
    while (cur != NULL)//��������
    {
        if (cur->isExist == 0)//�жϽڵ��Ƿ���Ҫɾ��
        {
            if (*pplist == cur)//���ɾ�����ǵ�һ���ڵ�
            {
                *pplist = cur->pnext;  //��������ĵ�ַ������һ���ڵ���Ϊͷ��� �����û�нڵ㣬������Ϊ��
                free(cur);             //�ͷŵ�ǰ�ڵ㣨��һ���ڵ�ģ��ռ�
                cur = *pplist;         //��curָ����һ���ڵ�
            }
            else
            {
                prev->pnext = cur->pnext;  //��¼��һ���ڵ�ĵ�ַ
                free(cur);                 //�ͷŵ�ǰ�ڵ�ռ�
                cur = prev;                //��ǰ�ڵ���ǰһ���ڵ�
            }
        }
        else //�������Ҫɾ���ڵ㣬���浱ǰ�ڵ�Ϊǰһ���ڵ㣬Ȼ��ָ����һ���ڵ�
        {
            prev = cur;
            cur = cur->pnext;
        }
    }
}

//���Ʒ��������ӵ�
void showBullet()
{
	    //�жϷɻ��ӵ��Ƿ���У����ĵл��������ӵ�״̬
    bulletHitUFO(&ufoa);
    bulletHitUFO(&ufob);
    bulletHitUFO(&ufoc);

	//�жϵл��ӵ��Ƿ���У����ķɻ��������ӵ�״̬
    bulletHitPlane(ufoa_bullet_list);
    bulletHitPlane(ufob_bullet_list);

	//�ɻ�������ӵ�
    listChangeXY(&plane_bullet_list);//�����ӵ��µ�λ��
    listRemoveNode(&plane_bullet_list);//������Ұ���߻��з��������ӵ�ɾ����
    for (list* cur = plane_bullet_list; cur != NULL; cur = cur->pnext)
    {
		drawAlpha(&temp_img,cur->x, cur->y, &img_plane_bullet);
    }

    //ufoa�������ӵ�
    listChangeXY(&ufoa_bullet_list);//�����ӵ��µ�λ��
    listRemoveNode(&ufoa_bullet_list);//������Ұ���߻��з��������ӵ�ɾ����
    for (list* cur = ufoa_bullet_list; cur != NULL; cur = cur->pnext)
    {
        drawAlpha(&temp_img,cur->x-10, cur->y-10, &img_ufoa_bullet);
    }

    //ufob�������ӵ�
    listChangeXY(&ufob_bullet_list);//�����ӵ��µ�λ��
    listRemoveNode(&ufob_bullet_list);//������Ұ���߻��з��������ӵ�ɾ����
    for (list* cur = ufob_bullet_list; cur != NULL; cur = cur->pnext)
    {
        drawAlpha(&temp_img,cur->x-15, cur->y-30, &img_ufob_bullet);
    }

}

//�жϷɻ����ӵ��Ƿ����UFO��ִ����Ӧ�ļӷ�������Ĳ���
void bulletHitUFO(aircraft* tmp)
{
    for (list* cur = plane_bullet_list; cur != NULL; cur = cur->pnext)
    {
        //�ӵ���UFO�ľ���ͼƬ��ʱ����Ϊ����
        if ((cur->x > tmp->x) && (cur->x < tmp->x + tmp->width))
        {
            if ((cur->y > tmp->y) && (cur->y < tmp->y + tmp->height))
            {
                tmp->life -= cur->damage;//����������ֵ - �ӵ����˺�
                cur->isExist = 0;  //����ӵ��Ĵ��ڱ��
            }
        }
    }
}

//����������  ����Ϊ�������ĵ�ַ���Լ�������Ѫ��
void aircraftReborn(aircraft* tmp, int life)
{
    tmp->new_born_flg = 1;
    tmp->life = life;
}
//�����������ж�
void aircraftLifeJudge()
{
    if (ufoa.life <= 0)
    {
        //aircraftReborn(&ufoa, ufoa.life);//���Ǵ���д��
		aircraftReborn(&ufoa, UFOA_LIFE);
		score += UFOA_LIFE;
    }
    if (ufob.life <= 0)
    {
        aircraftReborn(&ufob, UFOB_LIFE);
		score += UFOB_LIFE;
    }
    if (ufoc.life <= 0)
    {
        aircraftReborn(&ufoc, UFOC_LIFE);
		score += UFOC_LIFE;
    }
	if (plane.life <= 0)
    {
       game_over = 1;
    }
}
//UFO�Ƿ���ɻ���ײ  �ж�UFO�·��м�ĵ�,�м�ƫ�����м�ƫ�ҵĵ㣬�Ƿ��ڷ������ķ�Χ��
void ufoCrash(aircraft* tmp)
{
    triangle tri = getPlaneTriangle();//��ȡ�ɻ��������β���
    if (isPointInTriangle(tri, tmp->x + tmp->width / 2, tmp->y + tmp->height)
        || isPointInTriangle(tri, tmp->x + tmp->width / 4, tmp->y + tmp->height / 2)
        || isPointInTriangle(tri, tmp->x + tmp->width - tmp->width / 4, tmp->y + tmp->height / 2))
    {
        plane.life -= PLANE_LIFE / 2;//�ɴ���һ����������ֵ
        tmp->life = 0;//����ײ����UFO����
    }
}
//�ɻ���ײ���ж�
void ufosCrashJudge()
{
    ufoCrash(&ufoa);
    ufoCrash(&ufob);
    ufoCrash(&ufoc);
}
//2�������Ĳ�ˣ������Ȼ���������������Ա�ʾ����
float crossProduct(vector a, vector b)
{
    float tmp = a.x * b.y - a.y * b.x;
    return tmp;
}
//�жϵ�(x,y)�Ƿ�����������
int isPointInTriangle(triangle tri, float x, float y)
{
    vector pa = getVector(tri.ax, tri.ay, x, y);//����pa����a-p
    vector pb = getVector(tri.bx, tri.by, x, y);//����pb����b-p
    vector pc = getVector(tri.cx, tri.cy, x, y);//����pc����c-p
    float t1 = crossProduct(pa, pb);
    float t2 = crossProduct(pb, pc);
    float t3 = crossProduct(pc, pa);
    return t1 * t2 >= 0 && t1 * t3 >= 0 && t2 * t3 >= 0;
}
//����2�����꣬��������
vector getVector(float x1, float y1, float x2, float y2)
{
    vector tmp;
    tmp.x = x2 - x1;
    tmp.y = y2 - y1;
    return tmp;
}
//���ݷɻ�ͼƬ��x �� y���� ������һ�������Σ�������ײ�ж�
triangle getPlaneTriangle()
{
    triangle tmp;
    //a �����ϱߵĵ㣬b �����£� c�����¡�
    tmp.ax = plane.x + plane.width / 2;
    tmp.ay = plane.y;
    tmp.bx = plane.x + plane.width;
    tmp.by = plane.y + plane.height;
    tmp.cx = plane.x;
    tmp.cy = plane.y + plane.height;
    return tmp;
}


//�ж�UFO���ӵ��Ƿ���зɻ���ִ����Ӧ�ļӷ�������Ĳ���,������UFO���ӵ�����
void bulletHitPlane(list* bullet_list)
{
    for (list* cur = bullet_list; cur != NULL; cur = cur->pnext)
    {
        //�ӵ��ڷɻ��ľ���ͼƬ��ʱ�����ж��Ƿ��ڷɻ����������ڣ����ټ�����
        if ((cur->x > plane.x) && (cur->x < plane.x + plane.width))
        {
            if ((cur->y > plane.y) && (cur->y < plane.y + plane.height))
            {
                triangle tri = getPlaneTriangle();//��ȡ�ɻ��������β���
                if (isPointInTriangle(tri, cur->x, cur->y))//�ӵ���ɻ���ײ
                {
                    plane.life -= cur->damage;
                    cur->isExist = 0;
                }
            }
        }
    }
}

//��ָ����λ����ʾ����
void showScore(int x, int y, int score)
{
    TCHAR time_text[50];
    _stprintf_s(time_text, _T("Score:%d"), score);
    outtextxy(x, y, time_text);
}


//��ʾ��������
void showBeginPicture()
{
    playBgmMusic();

	drawAlpha(&temp_img,0, 0, &img_bk);
    drawAlpha(&temp_img,220, 400, &img_plane);
	drawAlpha(&temp_img,100, 100, &img_ufoa);
	putimage(0, 0, &temp_img);

    setbkmode(TRANSPARENT);// ����͸��
    settextcolor(BGR(0xFFEC8B));
    settextstyle(80, 0, _T("΢���ź�"));
    outtextxy(WIDTH / 2 - 100, 100, _T("���ȴ������"));
    settextstyle(40, 0, _T("����"));
    settextcolor(0xFFA500);
    outtextxy(WIDTH / 2 - 100, 280, _T("W��S��A��D �ƶ�"));
    outtextxy(WIDTH / 2 - 100, 340, _T("K �����ӵ�"));
    outtextxy(WIDTH / 2 - 100, 400, _T("�����������"));
    FlushBatchDraw();
    _getch();
}
//�����ӵ�����ʵ��
void clearBullet(list** pplist)
{
    if (*pplist == NULL)
        return;
    list* cur = *pplist;//curretָ���һ���ڵ�
    while (cur != NULL)//��������
    {
        cur->isExist = 0;//���е��ӵ�ȫ�����
        cur = cur->pnext;//ָ����һ���ڵ�
    }
    listRemoveNode(pplist);
}
//���������ڳ����ӵ�
void clearAllBullet()
{
    clearBullet(&plane_bullet_list);
    clearBullet(&ufoa_bullet_list);
    clearBullet(&ufob_bullet_list);
}
//��������
void showGameOver()
{
    settextcolor(BGR(0xFFEC8B));
    settextstyle(80, 0, _T("΢���ź�"));
    outtextxy(WIDTH / 2 - 160, 280, _T("GAME OVER"));
    outtextxy(WIDTH / 2 - 160, 360, _T("���ո������"));
    FlushBatchDraw();
    while (' ' != _getch());//�ȴ��û�����ո�
    score = 0;//���÷���
    game_over = 0;//���ñ��
    dataInit();//���÷�����������
    clearAllBullet();//����ڳ����ӵ�
    showBeginPicture();//���ؿ����������¿�ʼ
}
//�������ֺ���
void playBgmMusic()
{
    mciSendString(_T("close bgm"), NULL, 0, NULL);
    mciSendString(_T("open res\\bgm.mp3 alias bgm"), NULL, 0, NULL);
    mciSendString(_T("play bgm repeat"), NULL, 0, NULL);//ѭ������
}
void playBoomMusic()
{
    mciSendString(_T("close boom"), NULL, 0, NULL);
    mciSendString(_T("open res\\boom.mp3 alias boom"), NULL, 0, NULL);
    mciSendString(_T("play boom "), NULL, 0, NULL);//���β���
}
void playBoom2Music()
{
    mciSendString(_T("close boom2"), NULL, 0, NULL);
    mciSendString(_T("open res\\boom2.mp3 alias boom2"), NULL, 0, NULL);
    mciSendString(_T("play boom2 "), NULL, 0, NULL);//���β���
}
void playBoom3Music()
{
    mciSendString(_T("close boom3"), NULL, 0, NULL);
    mciSendString(_T("open res\\boom3.mp3 alias boom3"), NULL, 0, NULL);
    mciSendString(_T("play boom3 "), NULL, 0, NULL);//���β���
}
void playShootMusic()
{
    mciSendString(_T("close shoot"), NULL, 0, NULL);
    mciSendString(_T("open res\\shoot.mp3 alias shoot"), NULL, 0, NULL);
    mciSendString(_T("play shoot"), NULL, 0, NULL);//���β���
}

//��ָ����λ����ʾ����ֵ
void showLife(int x, int y, int life)
{
    TCHAR time_text[50];
    _stprintf_s(time_text, _T("Life:%d"), life);
    outtextxy(x, y, time_text);
}