#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[20];
int a[20];

void pr()
{
	for(int i = 1;i <= n ;i++)
	{
		cout<<setw(5)<<a[i];
	}
	cout<<endl;
}

void dfs(int x)
{
	if(x > n)
	{
		pr();
	}
	
	for(int i = 1;i <=n;i++)
	{
		if(!vis[i])
		{	
			a[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;	
		}
	}
}

int main()
{
	cin>>n;
	dfs(1);
	return 0;
	
}