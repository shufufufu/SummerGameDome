#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,x,y,min = 0,n = 0;
	cin>>a>>b>>x>>y;
	
	if(b<a)
	{
		min = a;
		a = b;
		b = min;
	}
	if(y<x)
	{
		min = x;
		x = y;
		y = min;
	}
	min = b - a;
	n = abs(a - x) + abs(b - y);
	if(n < min)min = n;
	
	cout<<min;	
}
