#include<bits/stdc++.h>
using namespace std;
int fx[] = {-2,-2,-1,1,2,2,1,-1};
int fy[] = {-1,1,2,2,1,-1,-2,-2};
long long int vis[25][25],dp[25][25];
int bx = 0, by = 0, mx = 0, my = 0,cnt = 0;
 
int main()
{
	cin>>bx>>by>>mx>>my;
	bx++,by++,mx++,my++;
	dp[1][1] = 1;
	vis[1][1] = 1; 
	vis[mx][my] = 1;
	for(int i = 0;i < 8;i++)
	{
		int dmx = mx + fx[i];
		int dmy = my + fy[i];
		if( dmx>=1&&dmx<=bx&&dmy>=1&&dmy<=by )
		{
			vis[dmx][dmy] = 1;
		}
	}
	for(int i = 1;i <=bx; i++)
	{
	 for(int j = 1;j <=by; j++)
	 {
			if(vis[i][j] == 0)
			{
			 dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
	 }
	}
	cout<<dp[bx][by];
	return 0;
}