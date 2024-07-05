#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[2000000];
	cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+m);
	for(int i = 0;i<m;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}