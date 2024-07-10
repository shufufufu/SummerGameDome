#pragma once
// 声明 player 类
#include "basic.h"
#include "PlayerAnimation.h"

class player {
public:
    int health;
    bool isjumping;
    POINT play_pos;
    double speed;
    double downspeed;
    double VVspeed;
    double Vspeed;
    bool face;
    bool riattack;
    bool leattack;
    bool isdown;
    bool isattacking;
    bool don;
    bool attacked;
    clock_t last_time;
    clock_t last_time1;
    clock_t current_time;

    bool isattack;

    player(double x, double y, double speed, double downspeed, double VVspeed, bool face);
    ~player();
    void move(PlayerAnimation* animation , player* p, int interval, char up, char down, char left, char right, char attack);
};

//判断是否受击
void isattacked(player* p1, player* p2);

void InitPlayer();