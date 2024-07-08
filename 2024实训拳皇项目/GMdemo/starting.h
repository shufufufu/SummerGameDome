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
	static const int NUM_ALL_RANDBLOCK = 100;	// 总掩块个数
private:
	int block_left;		// 掩块的左边界
	int block_top;		// 掩块的上边界
	int width;			// 掩块的宽度
	int height;			// 掩块的高度
	double ratio;		// 掩块的黑白比例，先黑后白
	int blink_period;	// 掩块闪烁频率
	int blink_count;	// 闪烁计数，用于控制掩块闪烁

	static int Mosaic_left;			// 掩块区域左边界
	static int Mosaic_right;		// 掩块区域右边界
	static int Mosaic_top;			// 掩块区域上边界
	static int Mosaic_bottom;		// 掩块区域下边界

	static int Mosaic_width;		// 掩块区域宽度
	static int Mosaic_height;		// 掩块区域高度

	static const int block_wid_range = 150;		// 掩块宽度范围
	static const int block_wid_min = 10;		// 掩块宽度最小值

	static const int block_hei_range = 8;		// 掩块高度范围
	static const int block_hei_min = 5;			// 掩块高度最小值

	static const int block_blink_period_min = 1;	// 掩块闪烁周期最小值
	static const int block_blink_period_range = 3;	// 掩块闪烁周期范围

	static int num_showing_block;		// 当前显示掩块数目
	static int renew_block_count;		// 掩块更新计数
	static const int renew_block_period = 4;	// 掩块更新周期

	static std::vector<int> rand_index;		// 掩块随机编号
};


