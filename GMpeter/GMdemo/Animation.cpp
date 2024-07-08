#include "Game.h"

//动画模块

Animation::Animation(LPCTSTR path, int num, int interval) :
	Size_X(100), Size_Y(200), interval_ms(0), cur(0), timer(0),
	cur1(0), cur2(0), cur3(0), cur4(0), cur5(0), cur6(0), cur7(0), cur8(0), cur9(0), curback(0), curmp(0),
	cur10(0), cur11(0),cur12(0),cur13(0),
	interval_ms1(0), interval_ms2(0), interval_ms3(0), interval_ms4(0), interval_ms5(0),
	interval_ms6(0), interval_ms7(0), interval_ms8(0), interval_ms9(0), interval_msback(0),
	interval_ms10(0), interval_ms11(0), interval_ms12(0), interval_msmp(0), interval_ms13(0),
	timer1(0), timer2(0), timer3(0), timer4(0), timer5(0), timer6(0), timer7(0), timer8(0),
	timer9(0), timerback(0), timer10(0), timer11(0), timer12(0), timermp(0),timer13(0) {
	interval_ms = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list.push_back(frame);
	}
};

Animation::~Animation() {
	// Release memory for frame_list
	for (size_t i = 0; i < frame_list.size(); ++i) {
		delete frame_list[i];
	}
	frame_list.clear();

	// Release memory for frame_list1
	for (size_t i = 0; i < frame_list1.size(); ++i) {
		delete frame_list1[i];
	}
	frame_list1.clear();

	// Release memory for frame_list2
	for (size_t i = 0; i < frame_list2.size(); ++i) {
		delete frame_list2[i];
	}
	frame_list2.clear();

	// Release memory for frame_list3
	for (size_t i = 0; i < frame_list3.size(); ++i) {
		delete frame_list3[i];
	}
	frame_list3.clear();
	for (size_t i = 0; i < frame_list4.size(); ++i) {
		delete frame_list4[i];
	}
	frame_list4.clear();
	for (size_t i = 0; i < frame_list5.size(); ++i) {
		delete frame_list5[i];
	}
	frame_list5.clear();
	for (size_t i = 0; i < frame_list6.size(); ++i) {
		delete frame_list6[i];
	}
	frame_list6.clear();
	for (size_t i = 0; i < frame_list7.size(); ++i) {
		delete frame_list7[i];
	}
	frame_list7.clear();
	for (size_t i = 0; i < frame_list8.size(); ++i) {
		delete frame_list8[i];
	}
	frame_list8.clear();
	for (size_t i = 0; i < frame_list9.size(); ++i) {
		delete frame_list9[i];
	}
	frame_list9.clear();
	for (size_t i = 0; i < frame_listback.size(); ++i) {
		delete frame_listback[i];
	}
	frame_listback.clear();
	for (size_t i = 0; i < frame_list10.size(); ++i) {
		delete frame_list10[i];
	}
	frame_list10.clear();
	for (size_t i = 0; i < frame_list11.size(); ++i) {
		delete frame_list11[i];
	}
	frame_list11.clear();
	for (size_t i = 0; i < frame_listmp.size(); ++i) {
		delete frame_listmp[i];
	}
	frame_list12.clear();
	for (size_t i = 0; i < frame_listmp.size(); ++i) {
		delete frame_listmp[i];
	}
	frame_listmp.clear();
	for (size_t i = 0; i < frame_list13.size(); ++i) {
		delete frame_list13[i];
	}
	frame_list13.clear();
}
#pragma comment(lib,"MSIMG32.LIB")
//alpha通道输出
void Animation::putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}


void Animation::lodAnimation1(LPCTSTR path, int num, int interval) {
	interval_ms1 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y * 0.75, true);
		frame_list1.push_back(frame);
	}

}
void Animation::lodAnimation2(LPCTSTR path, int num, int interval) {
	interval_ms2 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list2.push_back(frame);
	}

}
void Animation::lodAnimation3(LPCTSTR path, int num, int interval) {
	interval_ms3 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X + 20, Size_Y + 20, true);
		frame_list3.push_back(frame);
	}

}
void Animation::lodAnimation4(LPCTSTR path, int num, int interval) {
	interval_ms4 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list4.push_back(frame);
	}

}
void Animation::lodAnimation5(LPCTSTR path, int num, int interval) {
	interval_ms5 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y * 0.75, true);
		frame_list5.push_back(frame);
	}

}
void Animation::lodAnimation6(LPCTSTR path, int num, int interval) {
	interval_ms6 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list6.push_back(frame);
	}

}
void Animation::lodAnimation7(LPCTSTR path, int num, int interval) {
	interval_ms7 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X + 20, Size_Y + 10, true);
		frame_list7.push_back(frame);
	}

}
void Animation::lodAnimation8(LPCTSTR path, int num, int interval) {
	interval_ms8 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list8.push_back(frame);
	}

}
void Animation::lodAnimation9(LPCTSTR path, int num, int interval) {
	interval_ms9 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list9.push_back(frame);
	}

}
void Animation::lodAnimationback(LPCTSTR path, int num, int interval) {
	interval_msback = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, WINDOW_WIDTH, WINDOW_HEIGHT, true);
		frame_listback.push_back(frame);
	}

}
void Animation::lodAnimation10(LPCTSTR path, int num, int interval) {
	interval_ms10 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list10.push_back(frame);
	}

}
void Animation::lodAnimation11(LPCTSTR path, int num, int interval) {
	interval_ms11 = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list11.push_back(frame);
	}

}
void Animation::lodAnimation12(LPCTSTR path, int num, int interval) {
	interval_ms12 = interval;
	TCHAR path_file[256];
	for (size_t i = 0; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, 1280, 720, true);
		frame_list12.push_back(frame);
	}

}
void Animation::lodAnimationmp(LPCTSTR path, int num, int interval) {
	interval_msmp = interval;
	TCHAR path_file[256];
	for (size_t i = 0; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, 450, 50, true);
		frame_listmp.push_back(frame);
	}

}
void Animation::lodAnimation13(LPCTSTR path, int num, int interval) {
	interval_ms13 = interval;
	TCHAR path_file[256];
	for (size_t i = 0; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, 1280, 720, true);
		frame_list13.push_back(frame);
	}

}
void Animation::drawAnimation(int x, int y, int counter, int delta) {
	timer += delta;
	if (!frame_list1.empty()) {
		if (timer >= interval_ms) {
			cur = (cur + 1) % frame_list.size();
			timer = 0;
		}
		putimage_alpha(x, y, frame_list[cur]);
	}
}
void Animation::drawAnimation1(int x, int y, int counter, int delta) {
	timer1 += delta;
	if (!frame_list1.empty()) {
		if (timer1 >= interval_ms1) {
			cur1 = (cur1 + 1) % frame_list1.size();
			timer1 = 0;
		}
		putimage_alpha(x, y, frame_list1[cur1]);
	}
}
void Animation::drawAnimation2(int x, int y, int counter, int delta) {
	timer2 += delta;
	if (!frame_list2.empty()) {
		if (timer2 >= interval_ms2) {
			cur2 = (cur2 + 1) % frame_list2.size();
			timer2 = 0;
		}
		putimage_alpha(x, y, frame_list2[cur2]);
	}
}
void Animation::drawAnimation3(int x, int y, int counter, int delta) {
	timer3 += delta;
	if (!frame_list3.empty()) {
		if (timer3 >= interval_ms3) {
			cur3 = (cur3 + 1) % frame_list3.size();
			timer3 = 0;
		}
		putimage_alpha(x, y - 10, frame_list3[cur3]);
	}
}
void Animation::drawAnimation4(int x, int y, int counter, int delta) {
	timer4 += delta;
	if (!frame_list4.empty()) {
		if (timer4 >= interval_ms4) {
			cur4 = (cur4 + 1) % frame_list4.size();
			timer4 = 0;
		}
		putimage_alpha(x, y, frame_list4[cur4]);
	}
}
void Animation::drawAnimation5(int x, int y, int counter, int delta) {
	timer5 += delta;
	if (!frame_list5.empty()) {
		if (timer5 >= interval_ms5) {
			cur5 = (cur5 + 1) % frame_list5.size();
			timer5 = 0;
		}
		putimage_alpha(x, y, frame_list5[cur5]);
	}
}
void Animation::drawAnimation6(int x, int y, int counter, int delta) {
	timer6 += delta;
	if (!frame_list6.empty()) {
		if (timer6 >= interval_ms6) {
			cur6 = (cur6 + 1) % frame_list6.size();
			timer6 = 0;
		}
		putimage_alpha(x, y, frame_list6[cur6]);
	}
}
void Animation::drawAnimation7(int x, int y, int counter, int delta) {
	timer7 += delta;
	if (!frame_list7.empty()) {
		if (timer7 >= interval_ms7) {
			cur7 = (cur7 + 1) % frame_list7.size();
			timer7 = 0;
		}
		putimage_alpha(x, y - 10, frame_list7[cur7]);
	}
}
void Animation::drawAnimation8(int x, int y, int counter, int delta) {
	timer8 += delta;
	if (!frame_list8.empty()) {
		if (timer8 >= interval_ms8) {
			cur8 = (cur8 + 1) % frame_list8.size();
			timer8 = 0;
		}
		putimage_alpha(x, y, frame_list8[cur8]);
	}
}
void Animation::drawAnimation9(int x, int y, int counter, int delta) {
	timer9 += delta;
	if (!frame_list9.empty()) {
		if (timer9 >= interval_ms9) {
			cur9 = (cur9 + 1) % frame_list9.size();
			timer9 = 0;
		}
		putimage_alpha(x, y, frame_list9[cur9]);
	}
}
void Animation::drawAnimationback(int x, int y, int counter, int delta) {
	timerback += delta;
	if (!frame_listback.empty()) {
		if (timerback >= interval_msback) {
			curback = (curback + 1) % frame_listback.size();
			timerback = 0;
		}
		putimage_alpha(x, y, frame_listback[curback]);
	}
}
void Animation::drawAnimation10(int x, int y, int counter, int delta) {
	timer10 += delta;
	if (!frame_list10.empty()) {
		if (timer10 >= interval_ms10) {
			cur10 = (cur10 + 1) % frame_list10.size();
			timer10 = 0;
		}
		putimage_alpha(x, y, frame_list10[cur10]);
	}
}
void Animation::drawAnimation11(int x, int y, int counter, int delta) {
	timer11 += delta;
	if (!frame_list11.empty()) {
		if (timer11 >= interval_ms11) {
			cur11 = (cur11 + 1) % frame_list11.size();
			timer11 = 0;
		}
		putimage_alpha(x, y, frame_list11[cur11]);
	}
}
void Animation::drawAnimation12(int x, int y, int counter, int delta) {
	timer12 += delta;
	if (!frame_list12.empty()) {
		if (timer12 >= interval_ms12) {
			cur12 = (cur12 + 1) % frame_list12.size();
			timer12 = 0;
		}
		putimage_alpha(x, y, frame_list12[cur12]);
	}
}
void Animation::drawAnimationmp(int health, int x, int y, int counter, int delta) {
	timermp += delta;
	if (!frame_listmp.empty()) {
		if (timermp >= interval_msmp) {
			curmp = (curmp + 1) % frame_listmp.size();
			timermp = 0;
		}
		putimage_alpha(x, y, frame_listmp[health]);
	}
}
void Animation::drawAnimation13(int x, int y, int counter, int delta) {
	timer13 += delta;
	if (!frame_list13.empty()) {
		if (timer13 >= interval_ms13) {
			cur13 = (cur13 + 1) % frame_list13.size();
			timer13 = 0;
		}
		putimage(x, y, frame_list13[cur13]);
	}
}
void  Animation::vs() {
	IMAGE img;
	loadimage(&img, "./sucaiku/vs/vs.png", 150, 150, true);
	putimage_alpha(550, 0, &img);
}
