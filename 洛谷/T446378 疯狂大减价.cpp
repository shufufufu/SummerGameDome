#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n >= 200)
	{
		n = n-50;
	}
	if(n >= 100)
	{
		n = n -20;
	}
	cout<<n;
	return 0;
	
}