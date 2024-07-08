#include<bits/stdc++.h>
using namespace std;

long long a[1010] ,n = 0,sum = 0;

void dfs(int p,int s)
{	
	if(p>=n)
	{
		sum += s;
		return ; 
	}
	dfs(p+1,s+a[p]);
	dfs(p+1,s);
}
int main()
{
	do
	{
		cin>>a[n];
		n++;
	}while(getchar() != '\n');
	dfs(0,0);
	cout<<sum;
	return 0;
}