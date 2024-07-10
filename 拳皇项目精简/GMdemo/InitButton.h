#pragma once
#include "specialButton.h"
extern RECT region_btn_start_game, region_btn_quit_game, region_btn_register_game, region_btn_load_game, region_btn_quit1_game;
extern StartGameButton btn_start_game;
extern QuitGameButton btn_quit_game;
extern RegisterGameButton btn_register_game;
extern LoadGameButton btn_load_game;
extern QuitGameButton btn_quit1_game;

void InitButtonRegions();

void InitSpecialButton();