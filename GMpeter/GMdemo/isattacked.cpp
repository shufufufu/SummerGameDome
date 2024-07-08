#include "Game.h"

void isattacked(player* p1, player* p2) {
	if (p1->leattack) {
		if ((p1->play_pos.x - p2->play_pos.x) < 120 && (p1->play_pos.x - p2->play_pos.x) > 0 && (p1->play_pos.y - p2->play_pos.y) <= 100 && (p1->play_pos.y - p2->play_pos.y) > -20) {
			(p2->health)--;
			p2->attacked = true;
			p2->face = false;
			p2->last_time1 = clock();
			//	p2->play_pos.x -= 100;

			if (p2->play_pos.x < 0) {
				p2->play_pos.x = 0;
			}
			if (p2->play_pos.x > 1180) {
				p2->play_pos.x = 1180;
			}
		}
	}
	if (p1->riattack) {
		if ((p2->play_pos.x - p1->play_pos.x) < 120 && (p2->play_pos.x - p1->play_pos.x) > 0 && (p1->play_pos.y - p2->play_pos.y) <= 100 && (p1->play_pos.y - p2->play_pos.y) > -20) {
			(p2->health)--;
			p2->attacked = true;
			p2->face = true;
			p2->last_time1 = clock();
			//	p2->play_pos.x += 100;
			if (p2->play_pos.x < 0) {
				p2->play_pos.x = 0;
			}
			if (p2->play_pos.x > 1180) {
				p2->play_pos.x = 1180;
			}
		}
	}
}