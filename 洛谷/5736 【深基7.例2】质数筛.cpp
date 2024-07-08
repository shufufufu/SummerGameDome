#include<bits/stdc++.h>
using namespace std;

bool prime(int s)
{
	for(int i = 2;i*i <= s;i++)
	{
		
		if(s%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n,x;
	cin>>n;
	if(n == 1)
	{
		cin>>x;
		if(x == 1)
		return 0;
	}
	for(int i = 0;i < n; i++)
	{
		cin>>x;
		if(x== 1)continue;
		
		if(prime(x))
		cout<<x<<" ";
	}
	return 0;
}