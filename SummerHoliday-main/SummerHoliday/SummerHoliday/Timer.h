#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>

class Timer
{
public:
    Timer() = default;
    ~Timer() = default;

    //���ö�ʱ��
    void restart()
    {
        pass_time = 0;
        shotted = false;
    }

    //���õȴ�ʱ��
    void set_wait_time(int val)
    {
        wait_time = val;
    }

    //�Ƿ񵥴δ���
    void set_one_shot(int flag)
    {
        one_shot = flag;
    }


    void set_callback(std::function<void()>callback)
    {
        this->callback = callback;
    }

    //��ͣ
    void pause()
    {
        paused = true;
    }

    //�ָ�
    void resume()
    {
        paused = false;
    }

    //��ʱ������
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
    int pass_time = 0;//�ѹ�ʱ��
    int wait_time = 0;//�ȴ�ʱ��
    bool paused = false;//�Ƿ���ͣ
    bool shotted = false;//�Ƿ񴥷�
    bool one_shot = false;//���δ���
    std::function<void()>callback;//�����ص�


};

#endif  // !_TIMER_H_
