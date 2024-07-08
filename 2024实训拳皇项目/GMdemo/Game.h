#pragma once

#include "basic.h"


// 声明 Animation 类
class Animation {
public:
    Animation(LPCTSTR path, int num, int interval);
    void drawAnimation(int x, int y, int counter, int delta);
    void lodAnimation1(LPCTSTR path, int num, int interval);
    void lodAnimation2(LPCTSTR path, int num, int interval);
    void lodAnimation3(LPCTSTR path, int num, int interval);
    void lodAnimation4(LPCTSTR path, int num, int interval);
    void lodAnimation5(LPCTSTR path, int num, int interval);
    void lodAnimation6(LPCTSTR path, int num, int interval);
    void lodAnimation7(LPCTSTR path, int num, int interval);
    void lodAnimation8(LPCTSTR path, int num, int interval);
    void lodAnimation9(LPCTSTR path, int num, int interval);
    void lodAnimation10(LPCTSTR path, int num, int interval);
    void lodAnimation11(LPCTSTR path, int num, int interval);
    void lodAnimation12(LPCTSTR path, int num, int interval);
    void lodAnimation13(LPCTSTR path, int num, int interval);
    void lodAnimationmp(LPCTSTR path, int num, int interval);
    void lodAnimationback(LPCTSTR path, int num, int interval);
    void putimage_alpha(int x, int y, IMAGE* img);
    void drawAnimation1(int x, int y, int counter, int delta);
    void drawAnimation2(int x, int y, int counter, int delta);
    void drawAnimation3(int x, int y, int counter, int delta);
    void drawAnimation4(int x, int y, int counter, int delta);
    void drawAnimation5(int x, int y, int counter, int delta);
    void drawAnimation6(int x, int y, int counter, int delta);
    void drawAnimation7(int x, int y, int counter, int delta);
    void drawAnimation8(int x, int y, int counter, int delta);
    void drawAnimation9(int x, int y, int counter, int delta);
    void drawAnimation10(int x, int y, int counter, int delta);
    void drawAnimation11(int x, int y, int counter, int delta);
    void drawAnimation12(int x, int y, int counter, int delta);
    void drawAnimation13(int x, int y, int counter, int delta);
    void drawAnimationmp(int health, int x, int y, int counter, int delta);
    void drawAnimationback(int x, int y, int counter, int delta);


    void vs();
    ~Animation();

    double Size_X;
    double Size_Y;

    int interval_ms;
    int interval_ms1;
    int interval_ms2;
    int interval_ms3;
    int interval_ms4;
    int interval_ms5;
    int interval_ms6;
    int interval_ms7;
    int interval_ms8;
    int interval_ms9;
    int interval_ms10;
    int interval_ms11;
    int interval_ms12;
    int interval_ms13;
    int interval_msmp;
    int interval_msback;

    int cur;
    int cur1;
    int cur2;
    int cur3;
    int cur4;
    int cur5;
    int cur6;
    int cur7;
    int cur8;
    int cur9;
    int cur10;
    int cur11;
    int cur12;
    int cur13;
    int curmp;
    int curback;

    int timer;
    int timer1;
    int timer2;
    int timer3;
    int timer4;
    int timer5;
    int timer6;
    int timer7;
    int timer8;
    int timer9;
    int timer10;
    int timer11;
    int timer12;
    int timer13;
    int timermp;
    int timerback;

    std::vector<IMAGE*> frame_list;
    std::vector<IMAGE*> frame_list1;
    std::vector<IMAGE*> frame_list2;
    std::vector<IMAGE*> frame_list3;
    std::vector<IMAGE*> frame_list4;
    std::vector<IMAGE*> frame_list5;
    std::vector<IMAGE*> frame_list6;
    std::vector<IMAGE*> frame_list7;
    std::vector<IMAGE*> frame_list8;
    std::vector<IMAGE*> frame_list9;
    std::vector<IMAGE*> frame_list10;
    std::vector<IMAGE*> frame_list11;
    std::vector<IMAGE*> frame_list12;
    std::vector<IMAGE*> frame_list13;
    std::vector<IMAGE*> frame_listmp;
    std::vector<IMAGE*> frame_listback;
};

// 声明 player 类
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
    void move(Animation* two, player* p, int counter, int interval, char up, char down, char left, char right, char attack);
};


//
void isattacked(player* p1, player* p2);
void drawButton(IMAGE img_menu);