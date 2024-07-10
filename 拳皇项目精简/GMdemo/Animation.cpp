#include "Animation.h"
/////
//			Animation父类
// ↑							↑
// BackgroundAnimation	  |     PlayerAnimation
//	非人物类都放这里      |
//		                  |
/////

//动画模块
Animation::Animation() {};
Animation::~Animation() {};
#pragma comment(lib,"MSIMG32.LIB")
//alpha通道输出
void Animation::putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}
