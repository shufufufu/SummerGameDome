#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,t = 0;
	cin>>n;
	while( n != 1)
	{
		n = n/2;
		t++;
	}

	cout<<t+1;
} 

