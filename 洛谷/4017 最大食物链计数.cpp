#include<bits/stdc++.h>
using namespace std;
const int Mn = 5005;
 int n,m,x[Mn],y[Mn],mp[Mn][Mn],dp[Mn],ans,mod = 80112002;

int dfs(int p)
{
	 int sum = 0;
	
	if(!y[p])
	{
		return 1;
	}
	if(dp[p])
	{
		return dp[p];
	}
	
	
	for(int i = 1; i<= n; i++)
	{
		if(mp[i][p])
		{
			sum =(sum + dfs(i)) % mod;//注意与ans += dfs(i) % mod;的区别
		}
	}
	
	return dp[p] = sum % mod;
	
}



int main()
{
	int f,q;
	cin>>n>>m;
	for(int i = 1; i <= m; i++)
	{
		
		cin>>f>>q;
		mp[f][q] = 1;
		x[f] = 1;
		y[q] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!x[i])
		{
			ans =(ans + dfs(i)) % mod;
		}
	}	
	
	cout<<ans % mod;
	
	
	return 0;
}