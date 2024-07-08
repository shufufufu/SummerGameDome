#include<bits/stdc++.h>
using namespace std;

long long n, m,dp[100000010],c[10010],v[10010];

int main()
{
	cin>>m>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>c[i]>>v[i];
	}	
	for(int i = 1; i <= n; i++)
	{
		for(int j = c[i]; j <= m; j++)
		{
			dp[j] = max(dp[j],dp[j-c[i]] + v[i]);
		}
	}
	cout<<dp[m];
	return 0;
}