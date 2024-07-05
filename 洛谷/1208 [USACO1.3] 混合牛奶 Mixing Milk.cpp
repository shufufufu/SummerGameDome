#include<bits/stdc++.h>
using namespace std;
int n,m,s;
struct cow
{
	int x,y;
}a[5005];
bool cmp(cow e,cow f)
{
	return	e.x < f.x;
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i<=m ; i++)
	{
		cin>>a[i].x>>a[i].y;	
	}
	sort(a+1,a+m+1,cmp);
	for(int i = 1; i <= m ; i++)
	{
		if(n>=a[i].y)
		{
		s += a[i].x*a[i].y;
		n -= a[i].y;
		}else
		{
		s+=n*a[i].x ;
		break;
		}
	}
	cout<<s;
	return 0;
}