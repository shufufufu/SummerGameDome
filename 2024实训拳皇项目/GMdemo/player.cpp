#include "Game.h"



player::player(double x, double y, double speed, double downspeed, double VVspeed, bool face) :
	isjumping(0), play_pos({ 0,0 }), speed(0), downspeed(0), VVspeed(0), face(0), health(11),
	Vspeed(0), leattack(0), riattack(0), isdown(0), isattacking(0),
	last_time(0), last_time1(0), current_time(0), isattack(0), don(0), attacked(0) {
	play_pos.x = x;
	play_pos.y = y;
	this->face = face;
	this->downspeed = downspeed;
	this->speed = speed;
	this->VVspeed = VVspeed;
};
player::~player() {};

void player::move(Animation* two, player* p, int counter, int interval, char up, char down, char left, char right, char attack) {
	p->current_time = clock();
	enum GAMEINPUT
	{
		NOINPUT = 0X0,
		UPINPUT = 0X1,
		DOWNINPUT = 0X2,
		LEFTINPUT = 0X4,
		RIGHTINPUT = 0X8,
		FIREINPUT = 0X10,
		ATTACK = 0X20
	};
	int input = NOINPUT;


	if (GetAsyncKeyState(up) & 0x8000)
	{
		input |= UPINPUT;
	}
	if (GetAsyncKeyState(down) & 0x8000)
	{
		input |= DOWNINPUT;
	}
	if (GetAsyncKeyState(left) & 0x8000)
	{
		input |= LEFTINPUT;
	}
	if (GetAsyncKeyState(right) & 0x8000)
	{
		input |= RIGHTINPUT;
	}
	if (GetAsyncKeyState(attack) & 0x8000)
	{
		input |= ATTACK;
	}
	if ((input & UPINPUT) && (p->play_pos.y >= 0))
	{
		if (!(p->isjumping)) {
			p->Vspeed = p->VVspeed;
			two->cur4 = 0;
			two->cur6 = 0;
			p->isjumping = true;
		}
	}
	if (p->isjumping) {
		p->Vspeed += p->downspeed;
		p->play_pos.y += p->Vspeed;

	}
	if (!p->isdown) {
		if ((input & LEFTINPUT) && (p->play_pos.x >= 0))
		{
			p->play_pos.x -= p->speed;
			p->face = 1;
			don = true;
		}
		else if ((input & RIGHTINPUT) && (p->play_pos.x <= 1180))
		{
			p->play_pos.x += p->speed;
			p->face = 0;
			don = true;
		}
		else {
			don = false;
		}
	}

	if (p->play_pos.y > 390) {
		p->play_pos.y = 400;
		p->isjumping = false;
	}
	if (input & DOWNINPUT)
	{
		if (!p->isjumping) {
			p->play_pos.y = p->play_pos.y + 50;
			p->isdown = true;
		}
		if (p->face == true) {
			two->drawAnimation5(p->play_pos.x, p->play_pos.y, counter, interval);
		}
		else {
			two->drawAnimation1(p->play_pos.x, p->play_pos.y, counter, interval);

		}
	}
	else {
		p->isdown = false;
		if (p->attacked == true) {
			if (p->current_time - p->last_time1 > 300) {
				p->attacked = false;
				two->cur10 = 0;
				two->cur11 = 0;
			}
			if (!p->face) {
				p->play_pos.x -= 10;
				if (p->play_pos.x < 0) {
					p->play_pos.x = 0;
				}
				if (p->play_pos.x > 1180) {
					p->play_pos.x = 1180;
				}
				two->drawAnimation10(p->play_pos.x, p->play_pos.y, counter, interval);
			}
			else {
				p->play_pos.x += 10;
				if (p->play_pos.x < 0) {
					p->play_pos.x = 0;
				}
				if (p->play_pos.x > 1180) {
					p->play_pos.x = 1180;
				}
				two->drawAnimation11(p->play_pos.x, p->play_pos.y, counter, interval);
			}
		}
		else {
			if (p->isjumping) {
				if (!p->face) {
					two->drawAnimation4(p->play_pos.x, p->play_pos.y, counter, interval);
				}
				else {
					two->drawAnimation6(p->play_pos.x, p->play_pos.y, counter, interval);
				}
			}
			else {
				if (input & ATTACK && (p->isattack == false))
				{
					two->cur3 = 0;
					two->cur7 = 0;
					p->last_time = p->current_time;
					p->isattack = true;
					p->isattacking = true;
					if (!p->face)
					{
						p->riattack = true;
					}
					else
					{
						p->leattack = true;
					}
				}
				if (p->isattacking == true) {
					if (p->current_time - p->last_time > 600)
					{
						p->isattacking = false;
						p->isattack = false;
					}
					if (p->current_time - p->last_time > 10)
					{
						p->leattack = false;
						p->riattack = false;
					}
					if (!p->face) {
						two->drawAnimation3(p->play_pos.x, p->play_pos.y, counter, interval);
					}
					else {
						two->drawAnimation7(p->play_pos.x, p->play_pos.y, counter, interval);
					}


				}
				else {
					if (p->face == true) {//×ó
						if (don == true) {
							two->drawAnimation2(p->play_pos.x, p->play_pos.y, counter, interval);
						}
						else {
							two->drawAnimation9(p->play_pos.x, p->play_pos.y, counter, interval);
						}
					}
					else {
						if (don == true) {
							two->drawAnimation(p->play_pos.x, p->play_pos.y, counter, interval);
						}
						else {

							two->drawAnimation8(p->play_pos.x, p->play_pos.y, counter, interval);
						}

					}

				}

			}
		}
	}

}
