#include<stdio.h>

int pri[2010],now = 0;
bool vis[2010];

void sieve( int n)//质数筛
{
	now = 0;
	for(int i = 2; i <= n;i++)
	{
		if(!vis[i])pri[++now] = i;
		for(int j = 1; j<=now&&pri[j]*i <= n;j++)
		{
			vis[pri[j] * i] = 1;
			if(i % pri[j] == 0)break;
		}	
	}	
}

int main()
{
	int a[400],sum[400] = {0},cnt = 0,z = 0;
	sum[0] = 0;
	sieve(2000);
	for(int i = 1; i < now; i++)
	{
		a[i] = pri[i+1]-pri[i];
	}
	for(int i = 1;i < now; i++)
	{
		sum[i] = sum[i-1] + a[i];
	}

	for(int i = now-1; i >= 1; i--)
	{
		if(sum[i] < 1898)break;
		for(int j = 0;j <=i; j++)
		{
			 z = sum[i] - sum[j];
			
			if(z < 1898)
			{
			break;	
			}
			
			if(z == 1898)
			{
			cnt++;	
			}	
		}
	}
	
	printf("%d",cnt);
	
	return 0;	
}