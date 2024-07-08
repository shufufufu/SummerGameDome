#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m , cnt = 1,sum = 0,a;
	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		if(sum+a <= m)
		{
			sum += a;
		}else
		{
			sum = a;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}