#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,x = 0,y = 0,a = 0;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		for(int j = x;j<x+n-y;j+=2)
		{
			a++;
			printf("%02d",a);
			x++;
		}
		cout<<endl;
		y++;
	}
}
