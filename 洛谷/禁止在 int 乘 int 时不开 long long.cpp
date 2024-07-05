#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x1=0,x2=0;
	int y1=0,y2=0;
	
	cin>>x1>>x2;
	cin>>y1>>y2;
	long long int a = static_cast<long long>(x2) * y2;
    long long int b = static_cast<long long>(x1) * y1;
    long long int c = static_cast<long long>(x2) * y1;
    long long int d = static_cast<long long>(x1) * y2;
	if(a>2147483647||b>2147483647)
	{
		cout<<"long long int";
	}
	else
	{
		if(-2147483648>c||-2147483648>d)
		{
			cout<<"long long int";
		}else
		{
			cout<<"int";
		}
		
		
		
	}
	
} 
