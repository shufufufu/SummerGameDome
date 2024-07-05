#include <graphics.h> // 引入图形库头文件
#include <stdio.h> // 标准输入输出头文件
#include <vector> // 引入向量（动态数组）头文件
#include <conio.h>
#include <time.h>
#include<functional>
#include "camera.h"

int sum = 5; // 全局变量 sum，未被使用
IMAGE img_bk;
#pragma comment(lib,"MSIMG32.LIB")
//alpha通道输出
inline void putimage_alpha(int x, int y, IMAGE* img)
{
    int w = img->getwidth();
    int h = img->getheight();
    AlphaBlend(GetImageHDC(NULL), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

// 定义动画类 Animation
class Animation {
public:
    // 构造函数，加载动画帧
    Animation(LPCTSTR path, int num, int interval) {//LPCTSTR是指向常量字符串的指针
        interval_ms = interval; // 设置帧间隔时间
        TCHAR path_file[256]; // 存储文件路径的缓冲区
        // 循环加载 num 个动画帧
        for (size_t i = 1; i <= num; i++) {
            sprintf_s(path_file, path, i); // 格式化文件路径
            IMAGE* frame = new IMAGE(); // 创建图像对象指针            
            loadimage(frame, path_file, 100, 200, true);// 加载图片到 frame
            frame_list.push_back(frame); // 将帧添加到帧列表中，在私有属性中定义了vector类的帧数组frame_list
        }
    };

    // 析构函数，释放动画帧的内存
    ~Animation() {
        for (size_t i = 0; i < frame_list.size(); i++) { // 遍历帧列表
            delete frame_list[i]; // 删除每一帧的内存
        }
    };

    // 绘制动画帧
    void drawAnimatiom(int x, int y, int counter, int delta) {
        timer += delta; // 更新计时器
        if (timer >= interval_ms) { // 如果计时器超过帧间隔时间
            cur = (cur + 1) % frame_list.size(); // 切换到下一帧
            timer = 0; // 重置计时器
        }

        putimage_alpha(x, y, frame_list[cur]); // 在指定位置绘制当前帧
    }

    // 动画移动逻辑（暂未实现）
    void move() {
        // 此处可以添加动画移动的逻辑，暂未实现
    }

private:
    int interval_ms = 0; // 帧间隔时间（毫秒）
    int cur = 0; // 当前帧索引
    int timer = 0; // 计时器
    std::vector<IMAGE*> frame_list; // 存储动画帧的指针列表
};

// 创建 Animation 对象 one，加载动画帧
Animation one = Animation("../sucaiku/palyer/%d.png", 1, 60);

// 定义玩家类 player
class player {
public:
    POINT play_pos = { 0,0 }; // 玩家位置
    int speed = 20; // 移动速度
    int downspeed = 5; // 重力加速度
    double Vspeed = 0; // 垂直速度
    bool isjumping = 0; // 跳跃状态
    double JUMP_VELOCITY = -10.0; // 跳跃初速度

    // 构造函数，初始化玩家位置
    player(int x, int y) {
        play_pos.x = x;
        play_pos.y = y;
    };

    // 析构函数，未定义

    // 玩家移动逻辑
    void move(int counter, int interval) {
        // 定义键盘输入枚举
        enum GAMEINPUT {
            NOINPUT = 0X0,
            UPINPUT = 0X1,
            DOWNINPUT = 0X2,
            LEFTINPUT = 0X4,
            RIGHTINPUT = 0X8,
            FIREINPUT = 0X10
        };
        int input = NOINPUT; // 初始化输入状态
        // 检测键盘输入状态
        if (GetAsyncKeyState('W') & 0x8000) {
            input |= UPINPUT;
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            input |= DOWNINPUT;
        }
        if (GetAsyncKeyState('A') & 0x8000) {
            input |= LEFTINPUT;
        }
        if (GetAsyncKeyState('D') & 0x8000) {
            input |= RIGHTINPUT;
        }
        // 处理上键输入，实现跳跃
        if ((input & UPINPUT) && (play_pos.y >= 0)) {
            if (!isjumping) {
                Vspeed = -60;
                isjumping = true;
            }
        }
        // 处理跳跃状态下的重力和位置更新
        if (isjumping) {
            Vspeed += downspeed;
            play_pos.y += Vspeed;
        }
        // 处理下键输入，实现向下移动
        if ((input & DOWNINPUT) && (play_pos.y <= 400)) {
            play_pos.y += speed;
            if (play_pos.y > 390) {
                play_pos.y = 400;
            }
        }
        // 处理左键输入，实现向左移动
        if ((input & LEFTINPUT) && (play_pos.x >= 0)) {
            play_pos.x -= speed;
        }
        // 处理右键输入，实现向右移动
        if ((input & RIGHTINPUT) && (play_pos.x <= 1180)) {
            play_pos.x += speed;
        }
        // 处理触地后状态重置
        if (play_pos.y > 390) {
            play_pos.y = 400;
            isjumping = false;
        }
        // 绘制玩家和动画
        one.drawAnimatiom(play_pos.x, play_pos.y, counter, interval);
    }
};

// 定义玩家2类 player2
class player2 {
public:
    POINT play_pos = { 0,0 }; // 玩家位置
    int speed = 20; // 移动速度
    int downspeed = 5; // 重力加速度
    double Vspeed = 0; // 垂直速度
    bool isjumping = 0; // 跳跃状态
    double JUMP_VELOCITY = -10.0; // 跳跃初速度

    // 构造函数，初始化玩家位置
    player2(int x, int y) {
        play_pos.x = x;
        play_pos.y = y;
    };

    // 析构函数，未定义

    // 玩家移动逻辑
    void move(int counter, int interval) {
        // 定义键盘输入枚举
        enum GAMEINPUT {
            NOINPUT = 0X0,
            UPINPUT = 0X1,
            DOWNINPUT = 0X2,
            LEFTINPUT = 0X4,
            RIGHTINPUT = 0X8,
            FIREINPUT = 0X10
        };
        int input = NOINPUT; // 初始化输入状态
        // 检测键盘输入状态
        if (GetAsyncKeyState('I') & 0x8000) {
            input |= UPINPUT;
        }
        if (GetAsyncKeyState('K') & 0x8000) {
            input |= DOWNINPUT;
        }
        if (GetAsyncKeyState('J') & 0x8000) {
            input |= LEFTINPUT;
        }
        if (GetAsyncKeyState('L') & 0x8000) {
            input |= RIGHTINPUT;
        }
        // 处理上键输入，实现跳跃
        if ((input & UPINPUT) && (play_pos.y >= 0)) {
            if (!isjumping) {
                Vspeed = -60;
                isjumping = true;
            }
        }
        // 处理跳跃状态下的重力和位置更新
        if (isjumping) {
            Vspeed += downspeed;
            play_pos.y += Vspeed;
        }
        // 处理下键输入，实现向下移动
        if ((input & DOWNINPUT) && (play_pos.y <= 400)) {
            play_pos.y += speed;
            if (play_pos.y > 390) {
                play_pos.y = 400;
            }
        }
        // 处理左键输入，实现向左移动
        if ((input & LEFTINPUT) && (play_pos.x >= 0)) {
            play_pos.x -= speed;
        }
        // 处理右键输入，实现向右移动
        if ((input & RIGHTINPUT) && (play_pos.x <= 1180)) {
            play_pos.x += speed;
        }
        // 处理触地后状态重置
        if (play_pos.y > 390) {
            play_pos.y = 400;
            isjumping = false;
        }
        // 绘制玩家和动画
        one.drawAnimatiom(play_pos.x, play_pos.y, counter, interval);
    }
};



Camera camera;

void on_draw(const Camera& camera) 
{
    putimage(0, 0, &img_bk);
}
void on_input(const MSG& msg)
{
    if (msg.message == WM_MOUSEMOVE)
    {
        camera.shake(10, 350);
    }
}

// 初始化游戏图形界面
void initgame() {
    initgraph(1280, 720); // 初始化窗口大小为 1280x720
}

// 绘制游戏背景
void background() {
    IMAGE img;
    loadimage(&img, "../sucaiku/background/00.png", 1280, 720, true); // 加载背景图片
    putimage(0, 0, &img); // 绘制背景图片到窗口
    setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10); // 设置线条样式
    line(0, 600, 1280, 600); // 绘制分界线
}

// 绘制得分和其他游戏元素（未实现）
void point() {
    // 此处可以添加绘制得分等游戏元素的逻辑，未实现
}

// 主函数
int main() {
    initgame(); // 初始化游戏界面
    BeginBatchDraw(); // 开始批量绘制，减少界面闪烁

    player p1 = player(300, 400); // 创建玩家1对象，初始位置 (300, 400)
    player2 p2 = player2(600, 400); // 创建玩家2对象，初始位置 (600, 400)


    MSG msg;
    // 主循环
    while (1) {
        static int counter = 0; // 计数器，用于控制动画帧
        counter++; // 计数器自增

        // 获取消息并处理
        

        // 清空绘制区域，绘制背景
        cleardevice();
        background();
while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            on_input(msg); // 处理消息
        }
        // 玩家1移动
        p1.move(counter, 60);

        // 玩家2移动
        p2.move(counter, 60);

        FlushBatchDraw(); // 刷新绘制区域，保持界面流畅
    }

    EndBatchDraw(); // 结束批量绘制
    closegraph(); // 关闭图形界面
}
