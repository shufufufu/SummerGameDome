#include "BackgroundAnimation.h"

//目前bkg就一处使用到，但仍使用数组结构便于后续开发
//懒得改了，非人物的我全放这，谁有空把子类写了吧
Loaddata bkg_one_pathes[bkg_one_indexnum] =
{ {"./sucaiku/战斗背景/%d.png", 8, 600,WINDOW_WIDTH,WINDOW_HEIGHT},
    {"./sucaiku/进入ui/进入%03d.jpg",104, 2400,WINDOW_WIDTH,WINDOW_HEIGHT},
    {"./sucaiku/ko界面/ko%02d.jpg",15, 20000,WINDOW_WIDTH,WINDOW_HEIGHT},
    {"./sucaiku/vs/vs.png",1, 150, 150 ,150}
};


// Implementations
BackgroundAnimation::BackgroundAnimation() {
    // Constructor implementation
}

BackgroundAnimation::~BackgroundAnimation() {
    // Destructor implementation
}

std::vector<IMAGE*> BackgroundAnimation::getFrameList(int index) const {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        return frame_lists[index];
    }
    return std::vector<IMAGE*>();
}

void BackgroundAnimation::setFrameList(int index, const std::vector<IMAGE*>& frameList) {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        frame_lists[index] = frameList;
    }
}

int BackgroundAnimation::getIntervalMs(int index) const {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        return interval_mss[index];
    }
    return 0;
}

void BackgroundAnimation::setIntervalMs(int index, int interval) {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        interval_mss[index] = interval;
    }
}

int BackgroundAnimation::getCur(int index) const {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        return curs[index];
    }
    return 0;
}

void BackgroundAnimation::setCur(int index, int cur) {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        curs[index] = cur;
    }
}

int BackgroundAnimation::getTimer(int index) const {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        return timers[index];
    }
    return 0;
}

void BackgroundAnimation::setTimer(int index, int timer) {
    if (index >= 0 && index < MAX_ANIMATIONS) {
        timers[index] = timer;
    }
}

//加载图片
void BackgroundAnimation::loadAllAnimations(int indexnum, Loaddata pathes[]) {
    for (int i = 0; i < indexnum; i++) {
        loadAnimation(i, indexnum, pathes[i].path, pathes[i].num, pathes[i].intervaL, pathes[i].width, pathes[i].height);
    }
}
void BackgroundAnimation::loadAnimation(int index, int indexnum, LPCTSTR path, int num, int interval, int width, int height) {
    if (index >= indexnum) return;
    interval_mss[index] = interval;
    TCHAR path_file[256];
    for (size_t i = 1; i <= num; ++i) {
        sprintf_s(path_file, path, i);
        IMAGE* frame = new IMAGE();
        loadimage(frame, path_file, width, height, true);
        frame_lists[index].push_back(frame);
    }
}

void BackgroundAnimation::drawAnimation(int index, int x, int y, int delta) {
    if (index >= MAX_ANIMATIONS || frame_lists[index].empty()) return;
    timers[index] += delta;
    if (timers[index] >= interval_mss[index]) {
        curs[index] = (curs[index] + 1) % frame_lists[index].size();
        timers[index] = 0;
    }
    putimage_alpha(x, y, frame_lists[index][curs[index]]);
}