#include "PlayerAnimation.h"

//������������ص�·�ɵ�
//soujijingxiang
Loaddata player_one_pathes[player_one_indexnum] =
{ {"./sucaiku/player/������/%d.png", 10, 800,player_one_sizex, player_one_sizey },
	{"./sucaiku/player/������/%d.png", 16, 600,player_one_sizex, player_one_sizey * 0.75} ,
	{"./sucaiku/player/�����߾���/%d.png", 10, 800,player_one_sizex, player_one_sizey},
	{"./sucaiku/player/����a/����a%d.png", 16, 80, player_one_sizex + 20, player_one_sizey + 20},
	{"./sucaiku/player/������/%d.png", 14, 150,player_one_sizex, player_one_sizey},
	{"./sucaiku/player/�����׾���/%d.png", 16, 600, player_one_sizex, player_one_sizey * 0.75},
	{"./sucaiku/player/����������/%d.png", 14, 150,player_one_sizex, player_one_sizey},
	{"./sucaiku/player/����a����/%d.png", 16, 80, player_one_sizex + 20, player_one_sizey + 10},
	{"./sucaiku/player/��������/%d.png", 8, 600,player_one_sizex, player_one_sizey},
	{"./sucaiku/player/������������/%d.png", 8, 600,player_one_sizex, player_one_sizey},
	{"./sucaiku/player/�����ܻ�/%d.png", 11, 600,player_one_sizex, player_one_sizey},
	{"./sucaiku/player/�����ܻ�����/%d.png", 11, 600,player_one_sizex, player_one_sizey}
};
//souji
Loaddata player_two_pathes[player_two_indexnum] =
{ {"./sucaiku/player2/king��/%d.png", 5, 800,player_two_sizex, player_two_sizey },
	{"./sucaiku/player2/king��/%d.png", 3, 600, player_two_sizex, player_two_sizey * 0.75},
	{"./sucaiku/player2/king�߾���/%d.png", 5, 800,player_two_sizex, player_two_sizey},
	{"./sucaiku/player2/kinga/%d.png", 13, 80, player_two_sizex + 50, player_two_sizey + 50},
	{"./sucaiku/player2/king��/%d.png", 22, 150,player_two_sizex+10, player_two_sizey+10},
	{"./sucaiku/player2/king�׾���/%d.png", 3, 600, player_two_sizex, player_two_sizey * 0.75},
	{"./sucaiku/player2/king������/%d.png", 22, 150,player_two_sizex, player_two_sizey},
	{"./sucaiku/player2/kinga����/%d.png", 13, 80, player_two_sizex + 30, player_two_sizey + 30},
	{"./sucaiku/player2/king����/%d.png", 9, 600,player_two_sizex-10, player_two_sizey},
	{"./sucaiku/player2/king��������/%d.png", 9, 600,player_two_sizex-10, player_two_sizey},
	{"./sucaiku/player2/king�ܻ�/%d.png", 8, 600,player_two_sizex+50, player_two_sizey+50},
	{"./sucaiku/player2/king�ܻ�����/%d.png", 8, 600,player_two_sizex+50, player_two_sizey+50}
};

Loaddata hpdatas[hp_indexnum] =
{ {"./sucaiku/Ѫ��1/%d.png", 13, 600,450, 50},
	{ "./sucaiku/Ѫ��2/%d.png", 13, 600 ,450, 50 }
};
// Implementations
PlayerAnimation::PlayerAnimation() {
	// Constructor implementation
}

PlayerAnimation::~PlayerAnimation() {
	// Destructor implementation
}
//Getter Setter

std::vector<IMAGE*> PlayerAnimation::getFrameList(int index) const {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		return frame_lists[index];
	}
	return std::vector<IMAGE*>();
}

void PlayerAnimation::setFrameList(int index, const std::vector<IMAGE*>& frameList) {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		frame_lists[index] = frameList;
	}
}

int PlayerAnimation::getIntervalMs(int index) const {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		return interval_mss[index];
	}
	return 0;
}

void PlayerAnimation::setIntervalMs(int index, int interval) {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		interval_mss[index] = interval;
	}
}

int PlayerAnimation::getCur(int index) const {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		return curs[index];
	}
	return 0;
}

void PlayerAnimation::setCur(int index, int cur) {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		curs[index] = cur;
	}
}

int PlayerAnimation::getTimer(int index) const {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		return timers[index];
	}
	return 0;
}

void PlayerAnimation::setTimer(int index, int timer) {
	if (index >= 0 && index < MAX_ANIMATIONS) {
		timers[index] = timer;
	}
}

//����ͼƬ
void  PlayerAnimation::loadAllAnimations(int indexnum, Loaddata pathes[]) {
	for (int i = 0; i < indexnum; i++) {
		loadAnimation(i, indexnum, pathes[i].path, pathes[i].num, pathes[i].intervaL, pathes[i].width, pathes[i].height);
	}
}


void PlayerAnimation::loadAnimation(int index, int indexnum, LPCTSTR path, int num, int interval, int width, int height) {
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

void PlayerAnimation::drawAnimation(int index, int x, int y, int delta) {
	if (index >= MAX_ANIMATIONS || frame_lists[index].empty()) return;
	timers[index] += delta;
	if (timers[index] >= interval_mss[index]) {
		curs[index] = (curs[index] + 1) % frame_lists[index].size();
		timers[index] = 0;
	}
	putimage_alpha(x, y, frame_lists[index][curs[index]]);
}


void PlayerAnimation::drawAnimation(int index, int health, int x, int y, int delta) {
	if (index >= MAX_ANIMATIONS || frame_lists[index].empty()) return;
	timers[index] += delta;
	if (timers[index] >= interval_mss[index]) {
		curs[index] = (curs[index] + 1) % frame_lists[index].size();
		timers[index] = 0;
	}
	putimage_alpha(x, y, frame_lists[index][health]);
}


