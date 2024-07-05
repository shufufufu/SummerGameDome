#include<bits/stdc++.h>
using namespace std;
int n,k,a[20],cnt = 0;
bool prime(int s)
{
	for(int i = 2;i*i < s;i++)
	{
		if(s%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void dfs(int p,int x,int s)
{
	if(x == k )
	{	
	if(prime(s))
		cnt++;
		return ;	
	}
	if(p > n)
	{
		return ;
	}
	dfs(p+1,x+1,s+a[p]);
	dfs(p+1, x , s );	
}

int main()
{
	cin >>n>>k;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}