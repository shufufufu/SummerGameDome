#include <graphics.h> // ����ͼ�ο�ͷ�ļ�
#include <stdio.h> // ��׼�������ͷ�ļ�
#include <vector> // ������������̬���飩ͷ�ļ�
#include <conio.h>
#include <time.h>
#include<functional>
#include "camera.h"

int sum = 5; // ȫ�ֱ��� sum��δ��ʹ��
IMAGE img_bk;
#pragma comment(lib,"MSIMG32.LIB")
//alphaͨ�����
inline void putimage_alpha(int x, int y, IMAGE* img)
{
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

// ���嶯���� Animation
class Animation {
public:
    // ���캯�������ض���֡
    Animation(LPCTSTR path, int num, int interval) {//LPCTSTR��ָ�����ַ�����ָ��
        interval_ms = interval; // ����֡���ʱ��
        TCHAR path_file[256]; // �洢�ļ�·���Ļ�����
        // ѭ������ num ������֡
        for (size_t i = 1; i <= num; i++) {
            sprintf_s(path_file, path, i); // ��ʽ���ļ�·��
            IMAGE* frame = new IMAGE(); // ����ͼ�����ָ��            
            loadimage(frame, path_file, 100, 200, true);// ����ͼƬ�� frame
            frame_list.push_back(frame); // ��֡��ӵ�֡�б��У���˽�������ж�����vector���֡����frame_list
        }
    };

    // �����������ͷŶ���֡���ڴ�
    ~Animation() {
        for (size_t i = 0; i < frame_list.size(); i++) { // ����֡�б�
            delete frame_list[i]; // ɾ��ÿһ֡���ڴ�
        }
    };

    // ���ƶ���֡
    void drawAnimatiom(int x, int y, int counter, int delta) {
        timer += delta; // ���¼�ʱ��
        if (timer >= interval_ms) { // �����ʱ������֡���ʱ��
            cur = (cur + 1) % frame_list.size(); // �л�����һ֡
            timer = 0; // ���ü�ʱ��
        }

        putimage_alpha(x, y, frame_list[cur]); // ��ָ��λ�û��Ƶ�ǰ֡
    }

    // �����ƶ��߼�����δʵ�֣�
    void move() {
        // �˴�������Ӷ����ƶ����߼�����δʵ��
    }

private:
    int interval_ms = 0; // ֡���ʱ�䣨���룩
    int cur = 0; // ��ǰ֡����
    int timer = 0; // ��ʱ��
    std::vector<IMAGE*> frame_list; // �洢����֡��ָ���б�
};

// ���� Animation ���� one�����ض���֡
Animation one = Animation("../sucaiku/palyer/%d.png", 1, 60);

// ��������� player
class player {
public:
    POINT play_pos = { 0,0 }; // ���λ��
    int speed = 20; // �ƶ��ٶ�
    int downspeed = 5; // �������ٶ�
    double Vspeed = 0; // ��ֱ�ٶ�
    bool isjumping = 0; // ��Ծ״̬
    double JUMP_VELOCITY = -10.0; // ��Ծ���ٶ�

    // ���캯������ʼ�����λ��
    player(int x, int y) {
        play_pos.x = x;
        play_pos.y = y;
    };

    // ����������δ����

    // ����ƶ��߼�
    void move(int counter, int interval) {
        // �����������ö��
        enum GAMEINPUT {
            NOINPUT = 0X0,
            UPINPUT = 0X1,
            DOWNINPUT = 0X2,
            LEFTINPUT = 0X4,
            RIGHTINPUT = 0X8,
            FIREINPUT = 0X10
        };
        int input = NOINPUT; // ��ʼ������״̬
        // ����������״̬
        if (GetAsyncKeyState('W') & 0x8000) {
            input |= UPINPUT;
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            input |= DOWNINPUT;
        }
        if (GetAsyncKeyState('A') & 0x8000) {
            input |= LEFTINPUT;
        }
        if (GetAsyncKeyState('D') & 0x8000) {
            input |= RIGHTINPUT;
        }
        // �����ϼ����룬ʵ����Ծ
        if ((input & UPINPUT) && (play_pos.y >= 0)) {
            if (!isjumping) {
                Vspeed = -60;
                isjumping = true;
            }
        }
        // ������Ծ״̬�µ�������λ�ø���
        if (isjumping) {
            Vspeed += downspeed;
            play_pos.y += Vspeed;
        }
        // �����¼����룬ʵ�������ƶ�
        if ((input & DOWNINPUT) && (play_pos.y <= 400)) {
            play_pos.y += speed;
            if (play_pos.y > 390) {
                play_pos.y = 400;
            }
        }
        // ����������룬ʵ�������ƶ�
        if ((input & LEFTINPUT) && (play_pos.x >= 0)) {
            play_pos.x -= speed;
        }
        // �����Ҽ����룬ʵ�������ƶ�
        if ((input & RIGHTINPUT) && (play_pos.x <= 1180)) {
            play_pos.x += speed;
        }
        // �����غ�״̬����
        if (play_pos.y > 390) {
            play_pos.y = 400;
            isjumping = false;
        }
        // ������ҺͶ���
        one.drawAnimatiom(play_pos.x, play_pos.y, counter, interval);
    }
};

// �������2�� player2
class player2 {
public:
    POINT play_pos = { 0,0 }; // ���λ��
    int speed = 20; // �ƶ��ٶ�
    int downspeed = 5; // �������ٶ�
    double Vspeed = 0; // ��ֱ�ٶ�
    bool isjumping = 0; // ��Ծ״̬
    double JUMP_VELOCITY = -10.0; // ��Ծ���ٶ�

    // ���캯������ʼ�����λ��
    player2(int x, int y) {
        play_pos.x = x;
        play_pos.y = y;
    };

    // ����������δ����

    // ����ƶ��߼�
    void move(int counter, int interval) {
        // �����������ö��
        enum GAMEINPUT {
            NOINPUT = 0X0,
            UPINPUT = 0X1,
            DOWNINPUT = 0X2,
            LEFTINPUT = 0X4,
            RIGHTINPUT = 0X8,
            FIREINPUT = 0X10
        };
        int input = NOINPUT; // ��ʼ������״̬
        // ����������״̬
        if (GetAsyncKeyState('I') & 0x8000) {
            input |= UPINPUT;
        }
        if (GetAsyncKeyState('K') & 0x8000) {
            input |= DOWNINPUT;
        }
        if (GetAsyncKeyState('J') & 0x8000) {
            input |= LEFTINPUT;
        }
        if (GetAsyncKeyState('L') & 0x8000) {
            input |= RIGHTINPUT;
        }
        // �����ϼ����룬ʵ����Ծ
        if ((input & UPINPUT) && (play_pos.y >= 0)) {
            if (!isjumping) {
                Vspeed = -60;
                isjumping = true;
            }
        }
        // ������Ծ״̬�µ�������λ�ø���
        if (isjumping) {
            Vspeed += downspeed;
            play_pos.y += Vspeed;
        }
        // �����¼����룬ʵ�������ƶ�
        if ((input & DOWNINPUT) && (play_pos.y <= 400)) {
            play_pos.y += speed;
            if (play_pos.y > 390) {
                play_pos.y = 400;
            }
        }
        // ����������룬ʵ�������ƶ�
        if ((input & LEFTINPUT) && (play_pos.x >= 0)) {
            play_pos.x -= speed;
        }
        // �����Ҽ����룬ʵ�������ƶ�
        if ((input & RIGHTINPUT) && (play_pos.x <= 1180)) {
            play_pos.x += speed;
        }
        // �����غ�״̬����
        if (play_pos.y > 390) {
            play_pos.y = 400;
            isjumping = false;
        }
        // ������ҺͶ���
        one.drawAnimatiom(play_pos.x, play_pos.y, counter, interval);
    }
};



Camera camera;

void on_draw(const Camera& camera) 
{
    putimage(0, 0, &img_bk);
}
void on_input(const MSG& msg)
{
    if (msg.message == WM_MOUSEMOVE)
    {
        camera.shake(10, 350);
    }
}

// ��ʼ����Ϸͼ�ν���
void initgame() {
    initgraph(1280, 720); // ��ʼ�����ڴ�СΪ 1280x720
}

// ������Ϸ����
void background() {
    IMAGE img;
    loadimage(&img, "../sucaiku/background/00.png", 1280, 720, true); // ���ر���ͼƬ
    putimage(0, 0, &img); // ���Ʊ���ͼƬ������
    setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10); // ����������ʽ
    line(0, 600, 1280, 600); // ���Ʒֽ���
}

// ���Ƶ÷ֺ�������ϷԪ�أ�δʵ�֣�
void point() {
    // �˴�������ӻ��Ƶ÷ֵ���ϷԪ�ص��߼���δʵ��
}

// ������
int main() {
    initgame(); // ��ʼ����Ϸ����
    BeginBatchDraw(); // ��ʼ�������ƣ����ٽ�����˸

    player p1 = player(300, 400); // �������1���󣬳�ʼλ�� (300, 400)
    player2 p2 = player2(600, 400); // �������2���󣬳�ʼλ�� (600, 400)


    MSG msg;
    // ��ѭ��
    while (1) {
        static int counter = 0; // �����������ڿ��ƶ���֡
        counter++; // ����������

        // ��ȡ��Ϣ������
        

        // ��ջ������򣬻��Ʊ���
        cleardevice();
        background();
while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            on_input(msg); // ������Ϣ
        }
        // ���1�ƶ�
        p1.move(counter, 60);

        // ���2�ƶ�
        p2.move(counter, 60);

        FlushBatchDraw(); // ˢ�»������򣬱��ֽ�������
    }

    EndBatchDraw(); // ������������
    closegraph(); // �ر�ͼ�ν���
}
