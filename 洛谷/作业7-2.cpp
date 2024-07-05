#include<stdio.h>
int x,y;
void cin(int arr[][101]);
void find(int arr[][101]);
int main()
{
int a[101][101];
	cin(a);
	find(a);
	return 0;
}

void cin(int arr[][101])
{
	scanf("%d%d",&x,&y);
	for(int i = 1;i <= x;i++)
	{
		for(int j = 1;j <= y;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

void find(int arr[][101])
{
	int r = 0;
	for(int i = 1;i <= x;i++)
	{	
		int p = 1,z = 1;
		for(int j = 1;j <= y;j++)
		{
			if(arr[i][p] < arr[i][j])
			{
				p = j;
			}
		}
		for(int k = 1;k <= x;k++)
		{
			if(arr[z][p] > arr[k][p])
			{
				z = k;
			}
		}
		if(z == i)
		{
			printf("鞍点位于第%d行第%d列。",z,p);
			r = 1;
			break;
		}	
	}
	if(r == 0)
	{
		printf("不存在鞍点。");
	}
}