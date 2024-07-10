#pragma once
#include "Animation.h"

#define player_one_indexnum 12
#define player_two_indexnum 12
#define player_one_sizex 100
#define player_one_sizey 200
#define player_two_sizex 100
#define player_two_sizey 200
#define hp_indexnum 2

extern Loaddata player_one_pathes[];
extern Loaddata player_two_pathes[];
extern Loaddata hpdatas[];

class PlayerAnimation : public Animation
{
public:
		PlayerAnimation();
		~PlayerAnimation();
		void loadAllAnimations(int indexnum, Loaddata pathes[]);
		/*void loadAllAnimations(int indexnum, Hploaddata hpdatas[]);*/
		void loadAnimation(int index, int indexnum, LPCTSTR path, int num, int interval, int width, int height) override;
		void drawAnimation(int index, int x, int y, int delta) override;

		////
		void drawAnimation(int index, int health, int x, int y, int delta);
			

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
	//AnimationµÄÊýÁ¿
	static const int MAX_ANIMATIONS = 14;
	//
	std::vector<IMAGE*> frame_lists[MAX_ANIMATIONS];
	int interval_mss[MAX_ANIMATIONS] = { 0 };
	int curs[MAX_ANIMATIONS] = { 0 };
	int timers[MAX_ANIMATIONS] = { 0 };

};