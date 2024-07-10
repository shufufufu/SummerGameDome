///////////
// Button类说明
// basicbutton为button类的父类
//      ↑
// special为button类的子类
// 
// 
// initButton 为所有spcialbutton的初始化函数
///////////
#pragma once
#include "basic.h"

#define BUTTON_WIDTH 192
#define BUTTON_HEIGHT 75
#define BUTTON_HEIGHT_ONE 10


//button类
class Button {
public:
    Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
    void ProcessEvent(const MOUSEMSG& msg);
    void putimage_alpha(int x, int y, IMAGE* img);
    void Draw();

protected:
    virtual void OnClick() = 0;

private:
    enum class Status {
        Idle = 0,
        Hovered,
        Pushed
    };

    RECT region;
    IMAGE img_idle;
    IMAGE img_hovered;
    IMAGE img_pushed;
    Status status = Status::Idle;

    bool CheckCursorHit(int x, int y);
};


