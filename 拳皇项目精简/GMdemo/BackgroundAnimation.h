#pragma once
#include "Animation.h"
//Ŀǰbkg��һ��ʹ�õ�������ʹ������ṹ���ں�������
//���ø��ˣ����������ȫ���⣬˭�пհ�����д�˰�


#define bkg_one_indexnum 4


extern Loaddata bkg_one_pathes[];


class BackgroundAnimation : public Animation
{
public:
	BackgroundAnimation();
	~BackgroundAnimation();
	void loadAllAnimations(int indexnum, Loaddata pathes[]);
	void loadAnimation(int index, int indexnum, LPCTSTR path, int num, int interval, int width, int height) override;
	void drawAnimation(int index, int x, int y, int delta) override;

	// Getter and Setter for frame_lists
	std::vector<IMAGE*> getFrameList(int index) const;
	void setFrameList(int index, const std::vector<IMAGE*>& frameList);

	// Getter and Setter for interval_mss
	int getIntervalMs(int index) const;
	void setIntervalMs(int index, int interval);

	// Getter and Setter for curs
	int getCur(int index) const;
	void setCur(int index, int cur);

	// Getter and Setter for timers
	int getTimer(int index) const;
	void setTimer(int index, int timer);


private:
	//Animation������
	static const int MAX_ANIMATIONS = 14;
	//
	std::vector<IMAGE*> frame_lists[MAX_ANIMATIONS];
	int interval_mss[MAX_ANIMATIONS] = { 0 };
	int curs[MAX_ANIMATIONS] = { 0 };
	int timers[MAX_ANIMATIONS] = { 0 };
};
