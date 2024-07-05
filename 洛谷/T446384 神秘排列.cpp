#include<bits/stdc++.h>
using namespace std;
bool vis[100100];

int main()
{
	int n,arr[100100],num,p,flag = 0;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>num;
		arr[i] = num;
		vis[num] = 1;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 0)
		{
			cout<<"NO";
			return 0;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		p = arr[i];
		if(arr[p] != i)	
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
	return 0 ;
}