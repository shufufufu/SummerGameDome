#include "Game.h"
#include "specialButton.h"
#include "userdata.h"
#include "starting.h"
#pragma comment(lib,"winmm.lib")

bool is_game_started = false;
bool running = true;
bool is_to_play = false;//是否点击注册
bool is_load = false;//是否点击登录
bool is_username = false;//是否输入账户
bool is_password = false;//是否输入密码
bool is_put_username = true;//是否在输入用户名时点取消
bool is_enter = true;//是否播放进入动画
char username[20];
char username1[20];
char password[20];
char password1[20];
userdata data;

//创建对象
Animation one = Animation("./sucaiku/player/玛丽走/%d.png", 10, 800);
Animation two = Animation("./sucaiku/player2/king走/%d.png", 5, 800);
player p1 = player(100, 400, 10, 3, -40, 0);
player p2 = player(1080, 400, 10, 3, -40, 1);
IMAGE img_menu;
IMAGE img_rg;




//游戏初始化载入
void initgame() {
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//此为底层内容，关系到计时器的计算，虽然已经没有实际作用，但是不可修改或删除
void background() {
	IMAGE img;
	loadimage(&img, "./sucaiku/background/00.png", WINDOW_WIDTH, WINDOW_HEIGHT, true);
	putimage(0, 0, &img);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(0, 600, WINDOW_WIDTH, 600);
}
void point() {



}
int main()
{
	one.lodAnimation1("./sucaiku/player/玛丽蹲/%d.png", 16, 600);
	two.lodAnimation1("./sucaiku/player2/king蹲/%d.png", 3, 600);

	one.lodAnimation2("./sucaiku/player/玛丽走镜像/%d.png", 10, 800);
	two.lodAnimation2("./sucaiku/player2/king走镜像/%d.png", 5, 800);

	one.lodAnimation3("./sucaiku/player/玛丽a/玛丽a%d.png", 16, 80);
	two.lodAnimation3("./sucaiku/player2/kinga/%d.png", 13, 80);

	one.lodAnimation4("./sucaiku/player/玛丽跳/%d.png", 14, 150);
	two.lodAnimation4("./sucaiku/player2/king跳/%d.png", 22, 150);

	one.lodAnimation5("./sucaiku/player/玛丽蹲镜像/%d.png", 16, 600);
	two.lodAnimation5("./sucaiku/player2/king蹲镜像/%d.png", 3, 600);

	one.lodAnimation6("./sucaiku/player/玛丽跳镜像/%d.png", 14, 150);
	two.lodAnimation6("./sucaiku/player2/king跳镜像/%d.png", 22, 150);

	one.lodAnimation7("./sucaiku/player/玛丽a镜像/%d.png", 16, 80);
	two.lodAnimation7("./sucaiku/player2/kinga镜像/%d.png", 13, 80);

	one.lodAnimation8("./sucaiku/player/玛丽待机/%d.png", 8, 600);
	two.lodAnimation8("./sucaiku/player2/king待机/%d.png", 9, 600);

	one.lodAnimation9("./sucaiku/player/玛丽待机镜像/%d.png", 8, 600);
	two.lodAnimation9("./sucaiku/player2/king待机镜像/%d.png", 9, 600);


	one.lodAnimation10("./sucaiku/player/玛丽受击/%d.png", 11, 600);
	two.lodAnimation10("./sucaiku/player2/king受击/%d.png", 11, 600);

	one.lodAnimation11("./sucaiku/player/玛丽受击镜像/%d.png", 11, 600);
	two.lodAnimation11("./sucaiku/player2/king受击镜像/%d.png", 8, 600);

	one.lodAnimationback("./sucaiku/战斗背景/%d.png", 8, 600);

	one.lodAnimationmp("./sucaiku/血条1/%d.png", 12, 600);
	two.lodAnimationmp("./sucaiku/血条2/%d.png", 12, 600);

	one.lodAnimation12("./sucaiku/进入ui/进入%03d.jpg",104, 2400);
	one.lodAnimation13("./sucaiku/ko界面/ko%02d.jpg",15, 20000);
	// 初始化游戏界面
	initgame();
	// 开始批量绘制，减少界面闪烁
	BeginBatchDraw();
	

	//引入音效
	mciSendString(_T("open ./sucaiku/sound/bgm.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/ko.mp3 alias ko"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/ready.mp3 alias rg"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/hit1.mp3 alias hit1"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/hit4.mp3 alias hit2"), NULL, 0, NULL);
	//mciSendString(_T("open ./sucaiku/sound/so3.mp3 alias so1"), NULL, 0, NULL);
	//mciSendString(_T("open ./sucaiku/sound/so4.mp3 alias so2"), NULL, 0, NULL);

	RECT region_btn_start_game, region_btn_quit_game,region_btn_register_game,region_btn_load_game,region_btn_quit1_game;
	region_btn_start_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_start_game.right = region_btn_start_game.left + BUTTON_WIDTH;
	region_btn_start_game.top = 430;
	region_btn_start_game.bottom = region_btn_start_game.top + BUTTON_HEIGHT;

	region_btn_quit_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_quit_game.right = region_btn_quit_game.left + BUTTON_WIDTH;
	region_btn_quit_game.top = 550;
	region_btn_quit_game.bottom = region_btn_quit_game.top + BUTTON_HEIGHT;

	region_btn_load_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_load_game.right = region_btn_start_game.left + BUTTON_WIDTH;
	region_btn_load_game.top = 370;
	region_btn_load_game.bottom = region_btn_start_game.top + BUTTON_HEIGHT_ONE;

	region_btn_register_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_register_game.right = region_btn_quit_game.left + BUTTON_WIDTH;
	region_btn_register_game.top = 470;
	region_btn_register_game.bottom = region_btn_quit_game.top + BUTTON_HEIGHT_ONE;

	region_btn_quit1_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_quit1_game.right = region_btn_quit_game.left + BUTTON_WIDTH;
	region_btn_quit1_game.top = 570;
	region_btn_quit1_game.bottom = region_btn_quit_game.top + BUTTON_HEIGHT;

	StartGameButton btn_start_game = StartGameButton(region_btn_start_game, _T("./sucaiku/ui/开始/2.png"), _T("./sucaiku/ui/开始/3.png"), _T("./sucaiku/ui/开始/4.png"));
	QuitGameButton btn_quit_game = QuitGameButton(region_btn_quit_game, _T("./sucaiku/ui/关闭/1.png"), _T("./sucaiku/ui/关闭/2.png"), _T("./sucaiku/ui/关闭/3.png"));
	RegisterGameButton btn_register_game = RegisterGameButton(region_btn_register_game, _T("./sucaiku/ui/注册/2.png"), _T("./sucaiku/ui/注册/3.png"), _T("./sucaiku/ui/注册/4.png"));
	LoadGameButton btn_load_game = LoadGameButton(region_btn_load_game, _T("./sucaiku/ui/登录/2.png"), _T("./sucaiku/ui/登录/3.png"), _T("./sucaiku/ui/登录/4.png"));
	QuitGameButton btn_quit1_game = QuitGameButton(region_btn_quit1_game, _T("./sucaiku/ui/关闭/1.png"), _T("./sucaiku/ui/关闭/2.png"), _T("./sucaiku/ui/关闭/3.png"));
	RandBlock randblocks[RandBlock::NUM_ALL_RANDBLOCK];
	loadimage(&img_menu, _T("./sucaiku/ui/13.png"));
	loadimage(&img_rg, _T("./sucaiku/ui/13.png"));
	char a1[5] = { 0 };
	char a2[5] = { 0 };
	while (running) {
		static int counter = 0;
		counter++;
	
		cleardevice();

		// 获取鼠标消息
		MOUSEMSG mouseMsg;
		while (MouseHit()) {
			mouseMsg = GetMouseMsg();
			// 处理鼠标消息
			if (!is_game_started) {
				btn_start_game.ProcessEvent(mouseMsg);
				btn_quit_game.ProcessEvent(mouseMsg);
			}
			else
			{
				if (is_username && is_password)
				{
					continue;
				}

				if (!is_load && !is_to_play)
				{
					btn_load_game.ProcessEvent(mouseMsg);
					btn_register_game.ProcessEvent(mouseMsg);
					btn_quit1_game.ProcessEvent(mouseMsg);
				}
				else if( is_load )
				{
					if (!is_put_username && !is_load)
					{
						is_load = false;
						is_put_username = true;
						is_to_play = false;
						continue;
					}
					is_put_username = InputBox(username, 15, "请输入账号", "登录", "请勿为空", 0, 0, false);
					
					if(!is_put_username)
					{
						is_put_username = false;
						is_load = false;
						continue;
					}
					switch (data.isUser(data.conn, username)) {
					case 0: {
						std::cout << "系统出故障了！" << std::endl;
						break;
					}
					case 1: {
						
						InputBox(password, 15, "请输入密码", "登录", "请勿为空", 0, 0, false);
						
						
						switch (data.isPass(data.conn, username, password)) {
						case 0: {
							std::cout << "系统出故障了！" << std::endl;
							break;
						}
						case 3: {
							is_username = true;
							is_password = true;
							break;
						}
						case 4: {
								//密码错误
							MessageBox(GetHWnd(), _T("密码错误，请重新输入"), _T("登录"), MB_YESNO | MB_ICONQUESTION);
							break;
								}
						}
						
						break;
					}
					case 2: {
						MessageBox(GetHWnd(), _T("账号不存在，请先注册账号"), _T("登录"), MB_YESNO | MB_ICONQUESTION);
						is_put_username = false;
						is_load = false;
						break;
					}
					}
					

				}
				else if (is_to_play)
				{
					is_put_username = InputBox(username1, 15, "请输入账号", "注册", "请勿为空", 0, 0, false);
					//注册返回还没做
					if(!is_put_username)
					{
						is_to_play = false;
						is_put_username = true;
						continue;
					}
					switch (data.isUser(data.conn, username1)) {
					case 0: {
						std::cout << "系统出故障了！" << std::endl;
						break;
					}
					case 1: {
						//用户已存在
						MessageBox(GetHWnd(), _T("用户已存在，请更换用户名"), _T("注册"), MB_YESNO | MB_ICONQUESTION);
						is_to_play = false;
						is_put_username = true;
						break;
					}
					case 2:
					{
						is_username = true;
						InputBox(password1, 15, "请输入密码", "注册", "请勿为空", 0, 0, false);
						data.signup(data.conn, username1, password1);
						is_password = true;
						break;
					}
					}
				}
			}
		}

		//游戏开始
		if (is_game_started) {

			if (is_username && is_password)
			{
				if(is_enter)
				{
					while(1)
					{
						BeginBatchDraw();
						cleardevice();
						one.drawAnimation12(0, 0, 0, 60);
						FlushBatchDraw();

						if (one.cur12 == 103)
							break;
					}
					mciSendString(_T("play rg from 0"), NULL, 0, NULL);
					is_enter = false;
					
				}
				background();
				one.drawAnimationback(0, 0, 0, 60);
				one.vs();

				p1.move(&one, &p1, counter, 60, 'K', 'S', 'A', 'D', 'J');
				p2.move(&two, &p2, counter, 60, VK_NUMPAD2, VK_DOWN, VK_LEFT, VK_RIGHT, VK_NUMPAD1);
				if(p1.attacked)
				{
					mciSendString(_T("play hit1 from 0"), NULL, 0, NULL);
				}
				if(p1.isattacking)
				{
					mciSendString(_T("play so1 from 0"), NULL, 0, NULL);
				}
				if(p2.attacked)
				{
					mciSendString(_T("play hit2 from 0"), NULL, 0, NULL);
				}
				if(p2.isattacking)
				{
					mciSendString(_T("play so2 from 0"), NULL, 0, NULL);
				}
				isattacked(&p2, &p1);
				isattacked(&p1, &p2);


				one.drawAnimationmp(p1.health, 30, 30, 0, 60);
				two.drawAnimationmp(p2.health, 800, 30, 0, 60);

				if (p2.health == 0) {
					mciSendString(_T("play ko from 0"), NULL, 0, NULL);
					printf_s("%s ", "p1win");
					
					break;
				}
				if (p1.health == 0) {
					mciSendString(_T("play ko from 0"), NULL, 0, NULL);
					
					printf_s("%s", "p2win");
					
					break;
				}
			}
			else
			{
				putimage(0, 0, &img_rg);
				btn_register_game.Draw();
				btn_load_game.Draw();
				btn_quit1_game.Draw();
				RandBlock::show_randblock(randblocks);	// 放置随机马赛克
			}

		}
		//游戏未开始主界面
		else {
			putimage(0, 0, &img_menu);
			btn_start_game.Draw();
			btn_quit_game.Draw();
			RandBlock::show_randblock(randblocks);	// 放置随机马赛克
		}

		FlushBatchDraw();
	}
	if(p2.health == 0)
	{
		cleardevice();
		EndBatchDraw();
		while(1)
		{
			one.drawAnimation13(0, 0, 0, 60);
			if (one.cur13 == 14)
				break;
		}
		
		MessageBox(GetHWnd(), _T("p2,KO!"), _T("游戏结束"), MB_YESNO | MB_ICONQUESTION);
		while (1);
	}
	else if(p1.health == 0)
	{
		cleardevice();
		EndBatchDraw();
		while (1)
		{
			one.drawAnimation13(0, 0, 0, 60);
			if (one.cur13 == 14)
				break;
		}
		MessageBox(GetHWnd(), _T("p1,KO!"), _T("游戏结束"), MB_YESNO | MB_ICONQUESTION);
		while (1);
	}
	EndBatchDraw();
	closegraph();
}
