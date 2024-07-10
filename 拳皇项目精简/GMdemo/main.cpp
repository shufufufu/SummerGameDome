#include "InitGame.h"

#pragma comment(lib,"winmm.lib")

bool is_game_started = false;
bool running = true;
bool is_to_play = false;//�Ƿ���ע��
bool is_load = false;//�Ƿ�����¼
bool is_username = false;//�Ƿ������˻�
bool is_password = false;//�Ƿ���������
bool is_put_username = true;//�Ƿ��������û���ʱ��ȡ��
bool is_enter = true;//�Ƿ񲥷Ž��붯��
char username[20];
char username1[20];
char password[20];
char password1[20];                                   
userdata data;

                                                                                     
int main()
{
	// ��ʼ����Ϸ
	initgame();
	RandBlock randblocks[RandBlock::NUM_ALL_RANDBLOCK];
	while (running) {
		static int counter = 0;
		counter++;
	
		cleardevice();

		// ��ȡ�����Ϣ
		MOUSEMSG mouseMsg;
		while (MouseHit()) {
			mouseMsg = GetMouseMsg();
			// ���������Ϣ
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
					is_put_username = InputBox(username, 15, "�������˺�", "��¼", "����Ϊ��", 0, 0, false);
					
					if(!is_put_username)
					{
						is_put_username = false;
						is_load = false;
						continue;
					}
					switch (data.isUser(data.conn, username)) {
					case 0: {
						std::cout << "ϵͳ�������ˣ�" << std::endl;
						break;
					}
					case 1: {
						
						InputBox(password, 15, "����������", "��¼", "����Ϊ��", 0, 0, false);
						
						
						switch (data.isPass(data.conn, username, password)) {
						case 0: {
							std::cout << "ϵͳ�������ˣ�" << std::endl;
							break;
						}
						case 3: {
							is_username = true;
							is_password = true;
							break;
						}
						case 4: {
								//�������
							MessageBox(GetHWnd(), _T("�����������������"), _T("��¼"), MB_YESNO | MB_ICONQUESTION);
							break;
								}
						}
						
						break;
					}
					case 2: {
						MessageBox(GetHWnd(), _T("�˺Ų����ڣ�����ע���˺�"), _T("��¼"), MB_YESNO | MB_ICONQUESTION);
						is_put_username = false;
						is_load = false;
						break;
					}
					}
					

				}
				else if (is_to_play)
				{
					is_put_username = InputBox(username1, 15, "�������˺�", "ע��", "����Ϊ��", 0, 0, false);
					//ע�᷵�ػ�û��
					if(!is_put_username)
					{
						is_to_play = false;
						is_put_username = true;
						continue;
					}
					switch (data.isUser(data.conn, username1)) {
					case 0: {
						std::cout << "ϵͳ�������ˣ�" << std::endl;
						break;
					}
					case 1: {
						//�û��Ѵ���
						MessageBox(GetHWnd(), _T("�û��Ѵ��ڣ�������û���"), _T("ע��"), MB_YESNO | MB_ICONQUESTION);
						is_to_play = false;
						is_put_username = true;
						break;
					}
					case 2:
					{
						is_username = true;
						InputBox(password1, 15, "����������", "ע��", "����Ϊ��", 0, 0, false);
						data.signup(data.conn, username1, password1);
						is_password = true;
						break;
					}
					}
				}
			}
		}

		//��Ϸ��ʼ
		if (is_game_started) {

			if (is_username && is_password)
			{
				if(is_enter)
				{

					while(1)
					{
						BeginBatchDraw();
						cleardevice();
						bkg_one.drawAnimation(1,0, 0, 60);
						FlushBatchDraw();

						if (bkg_one.getCur(1) == 103)
							break;
					}

					mciSendString(_T("play rg from 0"), NULL, 0, NULL);
					is_enter = false;
					
				}
				background();
				bkg_one.drawAnimation(0, 0, 0, 60);
				bkg_one.drawAnimation(3, 550, 0, 60);

				p1.move(&one, &p1,  60, 'K', 'S', 'A', 'D', 'J');
				p2.move(&two, &p2,  60, VK_NUMPAD2, VK_DOWN, VK_LEFT, VK_RIGHT, VK_NUMPAD1);
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

				hp.drawAnimation(0,p1.health, 30, 30, 60);
				hp.drawAnimation(1, p2.health, 800, 30, 60);

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
				RandBlock::show_randblock(randblocks);	// �������������
			}

		}
		//��Ϸδ��ʼ������
		else {
			putimage(0, 0, &img_menu);
			btn_start_game.Draw();
			btn_quit_game.Draw();
			RandBlock::show_randblock(randblocks);	// �������������
		}

		FlushBatchDraw();
	}
	if(p2.health == 0)
	{
		cleardevice();
		EndBatchDraw();

		while(1)
		{
			bkg_one.drawAnimation(2, 0, 0, 60);
			if (bkg_one.getCur(2) == 14)
				break;
		}
		
		MessageBox(GetHWnd(), _T("p2,KO!"), _T("��Ϸ����"), MB_YESNO | MB_ICONQUESTION);
		while (1);
	}
	else if(p1.health == 0)
	{
		cleardevice();
		EndBatchDraw();
		MessageBox(GetHWnd(), _T("p1,KO!"), _T("��Ϸ����"), MB_YESNO | MB_ICONQUESTION);
		while (1);
	}
	EndBatchDraw();
	closegraph();
}
