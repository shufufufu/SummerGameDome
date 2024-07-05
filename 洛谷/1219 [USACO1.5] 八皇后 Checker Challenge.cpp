#include<bits/stdc++.h>
using namespace std;
int n,a[20],cnt = 0;
bool vis[20],//列
	 u[40],//左下到右上
	 v[40];//左上到右下

void pr()
{
	if(cnt <= 3)
	{
		for(int i = 1;i <= n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	
} 

void dfs(int x)//x为行数
{
	if(x > n)
	{
		cnt++;
		pr();
		return ;
	}
	
	for( int i = 1;i <= n;i++)
	{
		if(!vis[i] && !u[x+i+n] && !v[x-i+n])
		{	
			a[x] = i;
			vis[i] = 1;
			u[x+i+n] = 1;//左上到右下的同一斜线上行号与列号的和相等
			v[x-i+n] = 1;//同理
			dfs(x+1);
			vis[i] = 0;
			u[x+i+n] = 0;
			v[x-i+n] = 0;	
		}
	}
}

int main()
{
	cin>>n;
	dfs(1);
	cout<<cnt;
	return 0;
}