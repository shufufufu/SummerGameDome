#include<bits/stdc++.h>
using namespace std;
int xx[] = {1,0,-1,0};
int yy[] = {0,1,0,-1};
	int n;
	int mp[40][40];
	bool vis[40][40];
int main()
{
	
	cin>>n;
	for(int i = 1;i <= n ;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cin>>mp[i][j];
		}
	}
	for(int i = 0;i <= 40 ;i++)
	{
		for(int j = 0;j <= 40;j++)
		{
			vis[i][j] = 0;
		}
	}
	queue<int> x;
	queue<int> y;
	x.push(0);y.push(0);
	vis[0][0] = 1;
	while(!x.empty())
	{
		for(int i = 0;i <= 3;i++)
		{
			int dx = x.front() + xx[i];
			int dy = y.front() + yy[i];
			if(dx >= 0 && dx <= n+1 && dy >= 0 && dy <= n+1 && vis[dx][dy] == 0 && mp[dx][dy] == 0)
			{
				x.push(dx);
				y.push(dy);
				vis[dx][dy] = 1;
			}
		}
		x.pop();
		y.pop();
	}
	
//	cout<<endl;
//	for(int i = 0;i <= n ;i++)
//	{
//		for(int j = 0;j <= n;j++)
//		{
//			cout<<vis[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
    for(int i = 1;i <= n ;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(vis[i][j] == 0 && mp[i][j] == 0)
			{
				cout<<2;
			}
			else
			{
				cout<<mp[i][j];
			}
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
	
}