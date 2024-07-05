```java

#include <graphics.h>
#include <stdio.h>
#include <vector>
int sum = 5;
class Animation {
		public:
			Animation(LPCTSTR path,int num,int interval) {
				interval_ms = interval;
				TCHAR path_file[256];
				for (size_t i = 1; i <= num; i++) {
					sprintf_s(path_file, path, i);
					IMAGE* frame = new IMAGE();
					loadimage(frame,path_file,100,200,true);
					frame_list.push_back(frame);
				}
			};

			~Animation() {
				for (size_t i = 1; i <= frame_list.size(); i++) {
					delete frame_list[i];
				}
			};
			void drawAnimatiom(int x,int y,int counter,int delta) {
				timer += delta;
				if (timer >= interval_ms) {
					cur = (cur+1) % frame_list.size();
					timer = 0;
				}
				putimage(x, y, frame_list[cur]);

			}
			void move() {
			
			}
		private:
			int interval_ms = 0;
			int cur = 1;
			int timer = 0;
			std::vector<IMAGE*> frame_list;
};
Animation one = Animation("D:/sucaiku/%d.jpg", 5, 60);
class player {
	public:
		POINT play_pos = { 0,0 };
		int speed = 20;
		int downspeed = 5;
		double Vspeed =0 ;
		bool isjumping = 0;
		double JUMP_VELOCITY = -10.0;
		player(int x,int y) {
			play_pos.x = x;
			play_pos.y= y;
		};
		~player() {
		};
		
		void move(int counter, int interval) {


			enum GAMEINPUT
			{
				NOINPUT = 0X0,
				UPINPUT = 0X1,
				DOWNINPUT = 0X2,
				LEFTINPUT = 0X4,
				RIGHTINPUT = 0X8,
				FIREINPUT = 0X10
			};
			int input = NOINPUT;
			if (GetAsyncKeyState('W') & 0x8000)
			{	
				input |= UPINPUT;
			}
			if (GetAsyncKeyState('S') & 0x8000)
			{
				input |= DOWNINPUT;
			}
			if (GetAsyncKeyState('A') & 0x8000)
			{
				input |= LEFTINPUT;
			}
			if (GetAsyncKeyState('D') & 0x8000)
			{
				input |= RIGHTINPUT;
			}
			if ((input & UPINPUT) && (play_pos.y >= 0))
			{	
				if (!isjumping) {
					Vspeed = -60;
					isjumping = true;

				}
			}
			if (isjumping) {
				Vspeed += downspeed;
				play_pos.y += Vspeed;

			}
			if ((input & DOWNINPUT) && (play_pos.y <=400))
			{	
				play_pos.y += speed;
				if (play_pos.y > 390) {

					play_pos.y = 400;
				}
			}
			if ((input & LEFTINPUT) && (play_pos.x >= 0))
			{	
				play_pos.x -= speed;
			}
			if ((input & RIGHTINPUT) && (play_pos.x <= 1180))
			{
				play_pos.x += speed;
			}
			if (play_pos.y > 390) {
				play_pos.y = 400;
				isjumping = false;
			}
			one.drawAnimatiom(play_pos.x, play_pos.y, counter, interval);
			
		}

};
class player2 {
public:
	POINT play_pos = { 0,0 };
	int speed = 20;
	int downspeed = 5;
	double Vspeed = 0;
	bool isjumping = 0;
	double JUMP_VELOCITY = -10.0;
	player2(int x, int y) {
		play_pos.x = x;
		play_pos.y = y;
	};
	~player2() {
	};

	void move(int counter, int interval) {


		enum GAMEINPUT
		{
			NOINPUT = 0X0,
			UPINPUT = 0X1,
			DOWNINPUT = 0X2,
			LEFTINPUT = 0X4,
			RIGHTINPUT = 0X8,
			FIREINPUT = 0X10
		};
		int input = NOINPUT;
		if (GetAsyncKeyState('I') & 0x8000)
		{
			input |= UPINPUT;
		}
		if (GetAsyncKeyState('K') & 0x8000)
		{
			input |= DOWNINPUT;
		}
		if (GetAsyncKeyState('J') & 0x8000)
		{
			input |= LEFTINPUT;
		}
		if (GetAsyncKeyState('L') & 0x8000)
		{
			input |= RIGHTINPUT;
		}
		if ((input & UPINPUT) && (play_pos.y >= 0))
		{
			if (!isjumping) {
				Vspeed = -60;
				isjumping = true;

			}
		}
		if (isjumping) {
			Vspeed += downspeed;
			play_pos.y += Vspeed;

		}
		if ((input & DOWNINPUT) && (play_pos.y <= 400))
		{
			play_pos.y += speed;
			if (play_pos.y > 390) {

				play_pos.y = 400;
			}
		}
		if ((input & LEFTINPUT) && (play_pos.x >= 0))
		{
			play_pos.x -= speed;
		}
		if ((input & RIGHTINPUT) && (play_pos.x <= 1180))
		{
			play_pos.x += speed;
		}
		if (play_pos.y > 390) {
			play_pos.y = 400;
			isjumping = false;
		}
		one.drawAnimatiom(play_pos.x, play_pos.y, counter, interval);

	}

};
//Animation one = Animation("D:/sucaiku/%d.jpg", 5, 60);
void initgame() {
	initgraph(1280, 720);
}
void background() {
	IMAGE img;
	loadimage(&img, "D:/sucaiku/00.png", 1280, 720, true);
	putimage(0, 0, &img);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(0, 600, 1280, 600);
}
void point() {






}

int main()
{
	initgame();
	BeginBatchDraw();
	player p1 = player(300,400);
	player2 p2 = player2(600,400);
	while (1) {
		static int counter = 0;
		counter++;
		ExMessage msg;
		cleardevice();
		background();
		p1.move(counter, 60);
		p2.move(counter, 60);
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
}

```

