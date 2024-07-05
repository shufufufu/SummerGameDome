#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long s = 0,n = 1, m = 1,a = 0;
	cin>>s;
	for(long long i = s + 1;i < 10000000000;i++)
	{
		for(long long j = 2;j < sqrt(i);j++)
		{
			if(i % j == 0)
			{
				n = n + j + (i/j);	
			}
		} 
		for(long long y = 2;y < sqrt(n);y++)
		{
			if(n % y == 0)
			{
				m = m + y + (n/y);
			}
		}
		
		if(m == i&& i != n)
		{	
			a = i;
			break;
		}else
		{
			n = 1;
			m = 1;
		}
	}
	
	cout<<a<<' '<<n;
	return 0;	
}
