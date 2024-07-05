#include<stdio.h>

void s(int n);

int main()
{
	int n;
	scanf("%d",&n);
	s(n);
	return 0;
}

void s(int n)
{
	int a[101][101],p = 1,x = 1,y = 0,k = 0;
	int xx[] = {0,1,0,-1};
	int yy[] = {1,0,-1,0};
	for(int i = 1;i <=n*n;i++)
	{
		int dx = x + xx[k];
		int dy = y + yy[k];
		if(dx>=1&&dx<=n&&dy>=1&&dy<=n&&a[dx][dy]==0)
		{
			x = dx,y = dy;
			a[x][y] = p++;
		}
		else
		{
			(++k) %= 4;
			x = x + xx[k],y = y + yy[k];
			a[x][y] = p++;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}
}