#include "InitButton.h"

// 定义按钮区域
RECT region_btn_start_game, region_btn_quit_game, region_btn_register_game, region_btn_load_game, region_btn_quit1_game;

// 定义按钮对象
StartGameButton btn_start_game(region_btn_start_game, _T("./sucaiku/ui/开始/2.png"), _T("./sucaiku/ui/开始/3.png"), _T("./sucaiku/ui/开始/4.png"));
QuitGameButton btn_quit_game(region_btn_quit_game, _T("./sucaiku/ui/关闭/1.png"), _T("./sucaiku/ui/关闭/2.png"), _T("./sucaiku/ui/关闭/3.png"));
RegisterGameButton btn_register_game(region_btn_register_game, _T("./sucaiku/ui/注册/2.png"), _T("./sucaiku/ui/注册/3.png"), _T("./sucaiku/ui/注册/4.png"));
LoadGameButton btn_load_game(region_btn_load_game, _T("./sucaiku/ui/登录/2.png"), _T("./sucaiku/ui/登录/3.png"), _T("./sucaiku/ui/登录/4.png"));
QuitGameButton btn_quit1_game(region_btn_quit1_game, _T("./sucaiku/ui/关闭/1.png"), _T("./sucaiku/ui/关闭/2.png"), _T("./sucaiku/ui/关闭/3.png"));

//button定位
void InitButtonRegions() {
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
}


void InitSpecialButton() {
	// 在函数中初始化全局按钮对象
	btn_start_game = StartGameButton(region_btn_start_game, _T("./sucaiku/ui/开始/2.png"), _T("./sucaiku/ui/开始/3.png"), _T("./sucaiku/ui/开始/4.png"));
	btn_quit_game = QuitGameButton(region_btn_quit_game, _T("./sucaiku/ui/关闭/1.png"), _T("./sucaiku/ui/关闭/2.png"), _T("./sucaiku/ui/关闭/3.png"));
	btn_register_game = RegisterGameButton(region_btn_register_game, _T("./sucaiku/ui/注册/2.png"), _T("./sucaiku/ui/注册/3.png"), _T("./sucaiku/ui/注册/4.png"));
	btn_load_game = LoadGameButton(region_btn_load_game, _T("./sucaiku/ui/登录/2.png"), _T("./sucaiku/ui/登录/3.png"), _T("./sucaiku/ui/登录/4.png"));
	btn_quit1_game = QuitGameButton(region_btn_quit1_game, _T("./sucaiku/ui/关闭/1.png"), _T("./sucaiku/ui/关闭/2.png"), _T("./sucaiku/ui/关闭/3.png"));
}