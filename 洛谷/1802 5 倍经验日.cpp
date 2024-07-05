#include<bits/stdc++.h>
using namespace std;

long long int n,m,dp[10100],c[10100],vw[10100],vl[10100];


int main()
{
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n ; i++)
	{
		cin>>vl[i]>>vw[i]>>c[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = m ; j>=0 ; j--)
		{
			if(j < c[i])
			{
				dp[j] = dp[j] + vl[i];
			}else
			{
			dp[j] = max(dp[j] + vl[i],dp[j-c[i]] + vw[i]);
			}
		}
	}
	cout<<5*dp[m];
	return 0;
}