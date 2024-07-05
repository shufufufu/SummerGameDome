#include<bits/stdc++.h>
using namespace std;
	
int n,s_sum = 0,k_sum = 1,c = INT_MAX,vis[11];

void m(int s[],int k[],int x,int y)
{
	
	for(int i = 0;i < n;i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			m(s,k,x*s[i],y+k[i]);
			vis[i] = 0;
		}

	}
	if(c > abs(x-y)&&y != 0)
	{
		c = abs(x-y);
	}
}

int main()
{
	int s[11],k[11];
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>s[i]>>k[i];
	}
	m(s,k,1,0);
	cout<<c;
	return 0;
}