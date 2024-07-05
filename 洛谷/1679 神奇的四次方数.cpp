#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,dp[100010],c[110],n;
	memset(dp, 63, sizeof(dp));
	dp[0] = 0;
	cin>>m;
	
	for(int i = 1;i*i*i*i<100000;i++)
	{
		c[i] = i*i*i*i;
		n = i;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = c[i]; j <= m; j++)
		{
			dp[j] = min(dp[j],dp[j-c[i]]+1);
		}
	}
	cout<<dp[m];	
	return 0;
}