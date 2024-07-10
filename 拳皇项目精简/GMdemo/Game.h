#pragma once

#include "basic.h"

// 声明 Animation 类
class Animation {
public:
    Animation(LPCTSTR path, int num, int interval);
    ~Animation();
    void drawAnimatiom(int x, int y, int counter, int delta);
    void putimage_alpha(int x, int y, IMAGE* img);
    void down_drawAnimatiom(int x, int y, int counter, int delta);
private:
    int Size_X ;
    int Size_Y ;
    int interval_ms ;
    int cur ;
    int timer ;
    std::vector<IMAGE*> frame_list;
    std::vector<IMAGE*> down_frame_list;
};

// 声明 player 类
class player {
public:
	int health ;
	bool isjumping ;
	POINT play_pos ;
	int speed ;
	int downspeed ;
	double VVspeed ;
	double Vspeed ;
	bool face ;
	bool uple ;
	bool downle ;
	bool upri ;
	bool downri ;
	bool isdown ;

	player(int x, int y, int speed, int downspeed, int VVspeed);
	~player();
	void move(Animation* two, player* p, int counter, int interval, char up, char down, char left, char right, char attack);
};


void isattacked(player* p1, player* p2);
