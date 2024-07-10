#include "InitGame.h"

PlayerAnimation one = PlayerAnimation();
PlayerAnimation two = PlayerAnimation();
PlayerAnimation hp = PlayerAnimation();
BackgroundAnimation bkg_one = BackgroundAnimation();
player p1 = player(100, 400, 10, 3, -40, 0);
player p2 = player(1080, 400, 10, 3, -40, 1);
IMAGE img_menu;
IMAGE img_rg;

void initgame() {
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	one.loadAllAnimations(player_one_indexnum, player_one_pathes);
	two.loadAllAnimations(player_two_indexnum, player_two_pathes);
	bkg_one.loadAllAnimations(bkg_one_indexnum, bkg_one_pathes);
	hp.loadAllAnimations(hp_indexnum, hpdatas);
	// 开始批量绘制，减少界面闪烁
	BeginBatchDraw();
	//游戏之基
	background();
	//加载音效
	initMusic();
	//
	InitButtonRegions();
	InitSpecialButton();
	//
	loadimage(&img_menu, _T("./sucaiku/ui/13.png"));
	loadimage(&img_rg, _T("./sucaiku/ui/13.png"));
}

void background() {
	IMAGE img;
	loadimage(&img, "./sucaiku/background/00.png", WINDOW_WIDTH, WINDOW_HEIGHT, true);
	putimage(0, 0, &img);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(0, 600, WINDOW_WIDTH, 600);
}
void initMusic() {
	mciSendString(_T("open ./sucaiku/sound/bgm.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/ko.mp3 alias ko"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/ready.mp3 alias rg"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/hit1.mp3 alias hit1"), NULL, 0, NULL);
	mciSendString(_T("open ./sucaiku/sound/hit4.mp3 alias hit2"), NULL, 0, NULL);
}