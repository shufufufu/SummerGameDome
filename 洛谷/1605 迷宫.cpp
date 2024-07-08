#include<bits/stdc++.h>
using namespace std;

int n , m, t, sx, sy, fx , fy, ans = 0;
bool vis[10][10];
bool mp[10][10];
int xx[] ={1,0,-1,0};
int yy[] ={0,-1,0,1};

void dfs(int x,int y)
{
	if( x == fx && y == fy)
	{
		ans++;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int dx = xx[i] + x;
		int dy = yy[i] + y;
		if(dx>=1 && dx<=n && dy>=1 && dy<=m && !vis[dx][dy] && !mp[dx][dy])
		{
			vis[dx][dy] = 1;
			dfs(dx,dy);
			vis[dx][dy] = 0;
		}
	}
}

int main()
{
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	while(t--)
	{
		int x, y;
		cin>>x>>y;
		mp[x][y] = 1;
	}
	vis[sx][sy] = 1;
	dfs(sx,sy);
	cout<<ans;
	return 0;	
}