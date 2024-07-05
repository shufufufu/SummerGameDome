#include<bits/stdc++.h>
using namespace std;
int d[33][33] = {1},n,m;

int main()
{
	cin>>m>>n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			d[i][j] = d[i-1][(j-1+m)%m] + d[i-1][(j+1)%m];
		}
	}
	cout<<d[n][0];
	return 0;
}