#pragma once

#include "PlayerAnimation.h"
#include "BackgroundAnimation.h"
#include "InitButton.h"
#include "userdata.h"
#include "Randblock.h"
#include "player.h"

#pragma comment(lib,"winmm.lib")

extern PlayerAnimation one;
extern PlayerAnimation two;
extern PlayerAnimation hp ;
extern BackgroundAnimation bkg_one ;
extern player p1;
extern player p2;
extern IMAGE img_menu;
extern IMAGE img_rg;

void initgame();
void background();
void initMusic();