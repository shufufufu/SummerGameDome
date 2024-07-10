#include "basicButton.h"

Button::Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed) {
    region = rect;
    loadimage(&img_idle, path_img_idle);
    loadimage(&img_hovered, path_img_hovered);
    loadimage(&img_pushed, path_img_pushed);
}

void Button::ProcessEvent(const MOUSEMSG& msg) {
    switch (msg.uMsg) {
    case WM_MOUSEMOVE:
        if (status == Status::Idle && CheckCursorHit(msg.x, msg.y))
            status = Status::Hovered;
        else if (status == Status::Hovered && !CheckCursorHit(msg.x, msg.y))
            status = Status::Idle;
        break;
    case WM_LBUTTONDOWN:
        if (CheckCursorHit(msg.x, msg.y))
            status = Status::Pushed;
        break;
    case WM_LBUTTONUP:
        if (status == Status::Pushed) {
            status = Status::Idle;
            OnClick();
        }
        break;
    default:
        break;
    }
}
#pragma comment(lib,"MSIMG32.LIB")
//alphaÍ¨µÀÊä³ö
void Button::putimage_alpha(int x, int y, IMAGE* img)
{
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

void Button::Draw() {
    switch (status) {
    case Status::Idle:
        putimage_alpha(region.left, region.top, &img_idle);
        break;
    case Status::Hovered:
        putimage_alpha(region.left, region.top, &img_hovered);
        break;
    case Status::Pushed:
        putimage_alpha(region.left, region.top, &img_pushed);
        break;
    }
}


bool Button::CheckCursorHit(int x, int y) {
    return x >= region.left && x <= region.right && y >= region.top && y <= region.bottom;
}



