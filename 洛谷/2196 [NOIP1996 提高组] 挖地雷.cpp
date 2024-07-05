#include<bits/stdc++.h>
using namespace std;

int n,a[30],p[30],mp[30][30],dp[30],maxn,maxi;

void pr(int x)
{
	if(!x)
	{
		return ;
	}
	
	pr(p[x]);
	
	cout<<x<<" ";
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		dp[i] = a[i];
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			cin>>mp[i][j];
		}
	}
	
	for(int i = 1 ;i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(mp[j][i])
			{
				if(dp[i] < dp[j] + a[i])
				{
					dp[i] = dp[j] + a[i];
					p[i] = j;
				}	
			}
		}
		if(maxn < dp[i])
		{
			maxn = dp[i];
			maxi = i;
		}
	}
	pr(maxi);
	cout<<endl<<maxn;
	return 0;
}