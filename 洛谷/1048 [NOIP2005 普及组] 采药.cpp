#include<bits/stdc++.h>
using namespace std;

int m,t,c[105],v[105],dp[1005];
int main()
{
	cin>>t>>m;
	for(int i = 1;i<=m;i++)
	cin>>c[i]>>v[i];
	for(int i = 1;i <= m;i++)
	{
		for(int j = t;j >= c[i];j--)
		{
			dp[j] = max(dp[j],dp[j-c[i]] + v[i]);
		}
	}
	cout<<dp[t];
	return 0;
}