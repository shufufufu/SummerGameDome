#include "RandBlock.h"

static const int win_wid = 1280;	// ������
static const int win_hei = 720;		// ������

static bool IS_QUIT_THREAD = false;	// �߳��˳�����
static bool IS_QUIT_MUSIC = false;	// �����˳�����

static const float pi = 3.141592f;	// Բ���ʳ���

static float x_ratio = win_wid / 1344.0f;	// �����������
static float y_ratio = win_hei / 756.0f;	// �����������

int RandBlock::Mosaic_left = static_cast<int>(0 * x_ratio);		// �ڿ�������߽�
int RandBlock::Mosaic_right = static_cast<int>(1280 * x_ratio);		// �ڿ������ұ߽�
int RandBlock::Mosaic_top = static_cast<int>(0 * y_ratio);		// �ڿ������ϱ߽�
int RandBlock::Mosaic_bottom = static_cast<int>(720 * y_ratio);		// �ڿ������±߽�
int RandBlock::Mosaic_width = Mosaic_right - Mosaic_left;	// �ڿ�������
int RandBlock::Mosaic_height = Mosaic_bottom - Mosaic_top;	// �ڿ�����߶�
int RandBlock::renew_block_count = 1;		// �ڿ���¼���
int RandBlock::num_showing_block = 0;		// ��ǰ��ʾ�ڿ���Ŀ
std::vector<int> RandBlock::rand_index = { 0 };	// �ڿ�������

RandBlock::RandBlock()
{
	// ʹ��ǰ�����Щ�����Ƿ�Ϊ��
	int safe_block_wid_range = block_wid_range == 0 ? 1 : block_wid_range;
	int safe_block_hei_range = block_hei_range == 0 ? 1 : block_hei_range;

	block_left = rand() % (Mosaic_width+1) + Mosaic_left;		// ��������ڿ���߽�
	block_top = rand() % (Mosaic_height+1) + Mosaic_top;		// ��������ڿ��ϱ߽�
	width = rand() % safe_block_wid_range + block_wid_min;		// ��������ڿ���
	height = rand() % safe_block_hei_range + block_hei_min;		// ��������ڿ�߶�
	ratio = (rand() % 99) / 100.0;							// ������ɺڰױ���
	blink_count = rand() % 10;								// ������ɳ�ʼֵ

	int safe_block_blink_period_range = block_blink_period_range == 0 ? 1 : block_blink_period_range;
	blink_period = rand() % safe_block_blink_period_range + block_blink_period_min;

	for (int i = 1; i < RandBlock::NUM_ALL_RANDBLOCK; i++)	// ��ʼ��index
		rand_index.push_back(i);
}


void RandBlock::show_randblock(RandBlock* randblocks)
{
	if (!(renew_block_count % renew_block_period))			// ����͸���һ���������
	{
		random_shuffle(rand_index.begin(), rand_index.end());  // �������˳��
		num_showing_block = rand() % 5 + 7;

		if (!(renew_block_count % (20 * renew_block_period)))
			num_showing_block = rand() % 20 + 60;
	}

	renew_block_count++;

	if (!(renew_block_count % 20))		// ǿ�а����ڳ�3��΢��������
		for (int i = 0; i < num_showing_block; i++)
		{
			randblocks[rand_index[i]].blink_count++;

			if (!(randblocks[rand_index[i]].blink_count % randblocks[rand_index[i]].blink_period))		// ������˸��count����Ͳ�����
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


