#pragma once

#include "basic.h"


struct Loaddata {
    LPCTSTR path; //·��
    int num;   //ͼƬ����
    int intervaL;// �����ٶ� 
    int width; //ͼƬdrawʱ���
    int height;//ͼƬdrawʱ�߶�
};


class Animation {
public:
    Animation();
    ~Animation();
    void putimage_alpha(int x, int y, IMAGE* img);
    virtual void loadAnimation(int index,int indexnum, LPCTSTR path, int num, int interval, int width, int height)=0;
    virtual void drawAnimation(int index, int x, int y, int delta)=0;

};
