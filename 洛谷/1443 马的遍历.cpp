#include<bits/stdc++.h>
using namespace std;

int xx[] = {2,2,1,1,-1,-1,-2,-2};
int yy[] = {1,-1,2,-2,2,-2,1,-1};
int n,m,sx,sy;
int mp[410][410];

struct Node
{
	int x,y,s;
};

int main()
{
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
//	for(int i = 1 ;i <= n;i++)
//	{
//		for(int j = 1;j <=n ;j++)
//		{
//			mp[i][j] = -1;
//		}
//	}
	memset(mp,-1,sizeof(mp));
	queue < Node > Q;
	Q.push( (Node){sx,sy,0});
	mp[sx][sy] = 0;
	while(!Q.empty())
	{
		for(int i = 0;i < 8;i++)
		{
			int dx = xx[i] + Q.front().x;
			int dy = yy[i] + Q.front().y;
			if(dx >= 1&&dx <= n&&dy >= 1&&dy <= m && mp[dx][dy] == -1)
			{
				Q.push( (Node){dx,dy,Q.front().s+1});
				mp[dx][dy] = Q.front().s+1;
			}
		}
		Q.pop();
	}
	for(int i = 1 ;i <= n;i++)
	{
		for(int j = 1;j <=m ;j++)
		{
			printf("%-5d",mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
