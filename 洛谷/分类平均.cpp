#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,k = 0;
	double x = 0,y = 0;
	double num1 = 0, num2 = 0;
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
	{
		if(i % k == 0)
		{
			num1 += i;
			x++;	
		}
		else
		{
			num2 += i;
			y++;
		}
	}
	cout<<fixed<<setprecision(1)<<num1/x<<' ';
	cout<<fixed<<setprecision(1)<<num2/y;	
} 
