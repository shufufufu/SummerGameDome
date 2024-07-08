#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, s, a, b,p = 0,cnt = 0;
	int h[5010],ns[5010],ns1[5010];
	cin>>n>>s>>a>>b;
	for(int i = 0;i < n;i++)
	{
		cin>>h[i];
		cin>>ns[i];
	}
	for(int i = 0;i < n;i++)
	{
		if(a+b >= h[i])
		{
			ns1[p] = ns[i];
			p++;
		}
	}
	sort(ns1,ns1+p);
	for(int i = 0;i < n;i++)
	{
		s -= ns1[i];
		if(s >= 0)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;	
}