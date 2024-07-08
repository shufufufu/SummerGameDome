#pragma once
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <string>
#include <math.h>
#include <thread>
#include <iostream>


class RandBlock
{
public:
	RandBlock();
	static void show_randblock(RandBlock* randblocks);
	static const int NUM_ALL_RANDBLOCK = 100;	// ���ڿ����
private:
	int block_left;		// �ڿ����߽�
	int block_top;		// �ڿ���ϱ߽�
	int width;			// �ڿ�Ŀ��
	int height;			// �ڿ�ĸ߶�
	double ratio;		// �ڿ�ĺڰױ������Ⱥں��
	int blink_period;	// �ڿ���˸Ƶ��
	int blink_count;	// ��˸���������ڿ����ڿ���˸

	static int Mosaic_left;			// �ڿ�������߽�
	static int Mosaic_right;		// �ڿ������ұ߽�
	static int Mosaic_top;			// �ڿ������ϱ߽�
	static int Mosaic_bottom;		// �ڿ������±߽�

	static int Mosaic_width;		// �ڿ�������
	static int Mosaic_height;		// �ڿ�����߶�

	static const int block_wid_range = 150;		// �ڿ��ȷ�Χ
	static const int block_wid_min = 10;		// �ڿ�����Сֵ

	static const int block_hei_range = 8;		// �ڿ�߶ȷ�Χ
	static const int block_hei_min = 5;			// �ڿ�߶���Сֵ

	static const int block_blink_period_min = 1;	// �ڿ���˸������Сֵ
	static const int block_blink_period_range = 3;	// �ڿ���˸���ڷ�Χ

	static int num_showing_block;		// ��ǰ��ʾ�ڿ���Ŀ
	static int renew_block_count;		// �ڿ���¼���
	static const int renew_block_period = 4;	// �ڿ��������

	static std::vector<int> rand_index;		// �ڿ�������
};


