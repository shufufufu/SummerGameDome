#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x=0 , n=0 , s=0 ,d=0;
	cin>>x>>n;
	
	int c=n/7;
	s= (x+c)*250*5;
	if(n<=5)
	{
		d=n*250;	
	}
	
	if(n=6)
	{
		d=5*250;
	}
	
	if(n>7)
	{
		n=n%7;
		if(n=6)
		{
			d=5*250;
		}else
		{
			d=n*250;
		}
		
	}
	s=s+d;
	cout<<s;
}
