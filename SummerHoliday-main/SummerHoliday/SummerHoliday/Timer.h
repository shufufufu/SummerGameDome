#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>

class Timer
{
public:
    Timer() = default;
    ~Timer() = default;

    //重置定时器
    void restart()
    {
        pass_time = 0;
        shotted = false;
    }

    //设置等待时间
    void set_wait_time(int val)
    {
        wait_time = val;
    }

    //是否单次触发
    void set_one_shot(int flag)
    {
        one_shot = flag;
    }


    void set_callback(std::function<void()>callback)
    {
        this->callback = callback;
    }

    //暂停
    void pause()
    {
        paused = true;
    }

    //恢复
    void resume()
    {
        paused = false;
    }

    //定时器触发
    void on_update(int delta)
    {
        if (paused)
            return;

        pass_time += delta;
        if (pass_time >= wait_time)
        {
            if ((!one_shot || (one_shot && !shotted)) && callback)
                callback();
            shotted = true;
            pass_time = 0;
        }
    }

private:
    int pass_time = 0;//已过时间
    int wait_time = 0;//等待时间
    bool paused = false;//是否暂停
    bool shotted = false;//是否触发
    bool one_shot = false;//单次触发
    std::function<void()>callback;//触发回调


};

#endif  // !_TIMER_H_
