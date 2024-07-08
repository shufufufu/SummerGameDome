#include<bits/stdc++.h>
using namespace std;

int n,v[20];
double ans=1e9;
double a[20],b[20],dp[65000][17];
double dis(int x,int y)
{
	return sqrt( (a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
}
void dfs(int p, int cur, double s,int bi)
{
	if(s>ans)
		return ;
	if(p==n)
	{
		ans = min(ans,s);
		return ; 
	}
	for(int i=1 ; i<=n ; i++)
	{
		if( !v[i])
		{
			int t= bi + (1<<(i-1));
			if(dp[t][i]!=0 && dp[t][i] <= s+dis(cur,i) )
			continue;
			v[i] = 1;
			dp[t][i] = s+dis(cur,i);
			dfs(p+1,i,dp[t][i],t);
			v[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i<=n ; i++)
	{
		cin>>a[i]>>b[i];
	
	}
	dfs(0,0,0,0);
	printf("%.2lf",ans);
	return 0;
}