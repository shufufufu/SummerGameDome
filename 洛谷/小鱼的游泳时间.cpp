#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d;
	a=a*60;
	c=c*60;
	e=c+d-a-b;
	f=e/60;
	e=e%60;
	cout<<f<<' '<<e;
} 
