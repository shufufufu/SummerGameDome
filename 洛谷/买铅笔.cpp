#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,a1 = 0,a2 = 0,b1 = 0,b2 = 0,c1 = 0,c2 = 0;
	int x = 0,y = 0,z = 0,min = 0;
	cin>>n>>a1>>a2>>b1>>b2>>c1>>c2;
	if(n%a1 != 0)
	{
		x = (n/a1 + 1)*a2;
	}
	else
	{
		x = (n/a1)*a2;
	}
	if(n%b1 != 0)
	{
		y = (n/b1 + 1)*b2;
	}
	else
	{
		y = (n/b1)*b2;
	}
	if(n%c1 != 0)
	{
		z = (n/c1 + 1)*c2;
	}
	else
	{
		z = (n/c1)*c2;
	}
	min = x;
	if(min>z)min = z;
	if(min>y)min = y;
	cout<<min;
	
	
	
} 
