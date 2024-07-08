#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n,m,color,cnt = 0;
bool mp[maxn][maxn];
int vis[maxn][maxn];
int ans[1000010];

int xx[] = {0,1,0,-1};
int yy[] = {1,0,-1,0};

void bfs(int x ,int y)
{
	queue <int> h;
	queue <int> l;
	h.push(x);
	l.push(y);
	vis[x][y] = color;
	while(!h.empty())
	{
		for(int i = 0 ;i < 4;i++)
		{
			int dx = h.front() + xx[i];
			int dy = l.front() + yy[i];
			if(dx >= 1&&dy >= 1&&dx<=n&&dy<=n&&!vis[dx][dy]&&mp[dx][dy]!=mp[h.front()][l.front()])
			{
				h.push(dx);
				l.push(dy);
				vis[dx][dy] = color;
			}
		}
		h.pop();
		l.pop();
		cnt++;
	}
}

int main()
{
	cin>>n>>m;
	for(int i = 1;i <=n ;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			char x;
			cin>>x;
			if(x == '1')
			{
				mp[i][j] = 1;
			}
			else
				mp[i][j] = 0;
		}	
	}
	
	for(int i = 1;i <=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				color++;
				bfs(i,j);
				ans[color] = cnt;
				cnt = 0;
			}
		}
	}
	
	for(int i = 1;i <= m ; i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<ans[vis[x][y]]<<endl;
	}	
	return 0;
}