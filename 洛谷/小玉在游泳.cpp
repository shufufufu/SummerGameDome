#include<bits/stdc++.h>
using namespace std;

int main()
{
	double a=0,b=2;
	cin>>a;
	int c=0;
	while(a>0)
	{
		a=a-b;
		b=b*0.98;
		c++; 
	}
	cout<<c;
}
