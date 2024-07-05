#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[510][510],b[510][510],p = 1;
	int x = 0,y = 0, r = 0,z = 0;
	cin>>n>>m;
	for(int i = 1;i <=n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			a[i][j] = p;
			p++;
		}
	}
	for(int i = 0; i < m;i++)
	{
		cin>>x>>y>>r>>z;
		if(z == 1)
		{
			for(int j = 0;j <= 2*r;j++)
			{
				for(int k = 0;k <= 2*r;k++)
				{
					b[x-r+j][y-r+k] = a[x-r+k][y+r-j];
				}
			}
		}
		else
		{
			for(int j = 0;j <= 2*r;j++)
			{
				for(int k = 0;k <= 2*r;k++)
				{
					b[x-r+j][y-r+k] = a[x+r-k][y-r+j];
				}
			}
		}
		for(int j = 0;j <= 2*r;j++)
			{
				for(int k = 0;k <= 2*r;k++)
				{
					a[x-r+j][y-r+k] = b[x-r+j][y-r+k];
				}
			}
	}
	for(int i = 1;i <=n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
	
}