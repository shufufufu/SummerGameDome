#include<bits/stdc++.h>
using namespace std;
const int Mn = 1e5+10;
long long int n,x,a[Mn],cnt;

int main()
{

	cin>>n>>x;
	for(int i = 1; i<= n; i++)
	{
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i]+a[i+1]>x)
		{
			long long int y = a[i]+a[i+1]-x;
			a[i+1] -= y;
			cnt += y;
		}
	}
	
	cout<<cnt;
	
	return 0;
}