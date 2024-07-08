#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100];
	int n=0,t=0;
	for(int i=0;i<100;i++)
	{
		cin>>n;
		a[i]=n;
		if(n==0)
		{
			break;
		}
		t++;
	}
	
	for(int i=t-1;i>=0;i--)
	{
		cout<<a[i]<<' ';
	}
	
}
