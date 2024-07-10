#include "RandBlock.h"

static const int win_wid = 1280;	// 画布宽
static const int win_hei = 720;		// 画布高

static bool IS_QUIT_THREAD = false;	// 线程退出条件
static bool IS_QUIT_MUSIC = false;	// 音乐退出条件

static const float pi = 3.141592f;	// 圆周率常数

static float x_ratio = win_wid / 1344.0f;	// 横向比例调节
static float y_ratio = win_hei / 756.0f;	// 纵向比例调节

int RandBlock::Mosaic_left = static_cast<int>(0 * x_ratio);		// 掩块区域左边界
int RandBlock::Mosaic_right = static_cast<int>(1280 * x_ratio);		// 掩块区域右边界
int RandBlock::Mosaic_top = static_cast<int>(0 * y_ratio);		// 掩块区域上边界
int RandBlock::Mosaic_bottom = static_cast<int>(720 * y_ratio);		// 掩块区域下边界
int RandBlock::Mosaic_width = Mosaic_right - Mosaic_left;	// 掩块区域宽度
int RandBlock::Mosaic_height = Mosaic_bottom - Mosaic_top;	// 掩块区域高度
int RandBlock::renew_block_count = 1;		// 掩块更新计数
int RandBlock::num_showing_block = 0;		// 当前显示掩块数目
std::vector<int> RandBlock::rand_index = { 0 };	// 掩块随机编号

RandBlock::RandBlock()
{
	// 使用前检查这些常量是否为零
	int safe_block_wid_range = block_wid_range == 0 ? 1 : block_wid_range;
	int safe_block_hei_range = block_hei_range == 0 ? 1 : block_hei_range;

	block_left = rand() % (Mosaic_width+1) + Mosaic_left;		// 随机生成掩块左边界
	block_top = rand() % (Mosaic_height+1) + Mosaic_top;		// 随机生成掩块上边界
	width = rand() % safe_block_wid_range + block_wid_min;		// 随机生成掩块宽度
	height = rand() % safe_block_hei_range + block_hei_min;		// 随机生成掩块高度
	ratio = (rand() % 99) / 100.0;							// 随机生成黑白比例
	blink_count = rand() % 10;								// 随机生成初始值

	int safe_block_blink_period_range = block_blink_period_range == 0 ? 1 : block_blink_period_range;
	blink_period = rand() % safe_block_blink_period_range + block_blink_period_min;

	for (int i = 1; i < RandBlock::NUM_ALL_RANDBLOCK; i++)	// 初始化index
		rand_index.push_back(i);
}


void RandBlock::show_randblock(RandBlock* randblocks)
{
	if (!(renew_block_count % renew_block_period))			// 到点就更新一次随机数组
	{
		random_shuffle(rand_index.begin(), rand_index.end());  // 随机打乱顺序
		num_showing_block = rand() % 5 + 7;

		if (!(renew_block_count % (20 * renew_block_period)))
			num_showing_block = rand() % 20 + 60;
	}

	renew_block_count++;

	if (!(renew_block_count % 20))		// 强行把周期乘3，微调的作用
		for (int i = 0; i < num_showing_block; i++)
		{
			randblocks[rand_index[i]].blink_count++;

			if (!(randblocks[rand_index[i]].blink_count % randblocks[rand_index[i]].blink_period))		// 控制闪烁，count到点就不出现
				continue;

			int BW_border = int(randblocks[rand_index[i]].block_left + randblocks[rand_index[i]].ratio * randblocks[rand_index[i]].width);

			if (rand() % 2)
			{
				setfillcolor(RGB(20, 24, 40));
				setlinecolor(RGB(20, 24, 40));
				fillrectangle(randblocks[rand_index[i]].block_left, randblocks[rand_index[i]].block_top, BW_border, randblocks[rand_index[i]].block_top + randblocks[rand_index[i]].height);

				setfillcolor(RGB(230, 230, 218));
				setlinecolor(RGB(230, 230, 218));
				fillrectangle(BW_border, randblocks[rand_index[i]].block_top, randblocks[rand_index[i]].block_left + randblocks[rand_index[i]].width, randblocks[rand_index[i]].block_top + randblocks[rand_index[i]].height);
			}
			else
			{
				setfillcolor(RGB(230, 230, 218));
				setlinecolor(RGB(230, 230, 218));
				fillrectangle(randblocks[rand_index[i]].block_left, randblocks[rand_index[i]].block_top, BW_border, randblocks[rand_index[i]].block_top + randblocks[rand_index[i]].height);

				setfillcolor(RGB(20, 24, 40));
				setlinecolor(RGB(20, 24, 40));
				fillrectangle(BW_border, randblocks[rand_index[i]].block_top, randblocks[rand_index[i]].block_left + randblocks[rand_index[i]].width, randblocks[rand_index[i]].block_top + randblocks[rand_index[i]].height);
			}

		}

}


