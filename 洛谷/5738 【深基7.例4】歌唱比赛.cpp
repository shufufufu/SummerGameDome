#include<bits/stdc++.h>
using namespace std;
	int n,m;
	double a[21],aver,sum, maxn = 0;
void num(double x[])
{	sum = 0;
	for(int i = 0;i < m;i++)
	{
		if(x[i] > x[i+1])
		{
			swap(x[i],x[i+1]);
		}
		if(x[m-1-i] < x[m-2-i]&&m-2-i >= 0)
		{
			swap(x[m-1-i],x[m-2-i]);
		}
	}
	for(int i = 1;i < m-1;i++)
	{
		sum +=x[i];
	}
	aver = sum/(m-2);
}


int main()
{

	cin>>n>>m;
	for(int i = 0;i < n ; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin>>a[j];
		}
		num(a);
		if(aver > maxn)maxn = aver;	
	}
	cout<<fixed<<setprecision(2)<<maxn;
	return 0;
	
}