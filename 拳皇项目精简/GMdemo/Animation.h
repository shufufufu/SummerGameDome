#pragma once

#include "basic.h"


struct Loaddata {
    LPCTSTR path; //路由
    int num;   //图片数量
    int intervaL;// 播放速度 
    int width; //图片draw时宽度
    int height;//图片draw时高度
};


class Animation {
public:
    Animation();
    ~Animation();
    void putimage_alpha(int x, int y, IMAGE* img);
    virtual void loadAnimation(int index,int indexnum, LPCTSTR path, int num, int interval, int width, int height)=0;
    virtual void drawAnimation(int index, int x, int y, int delta)=0;

};
