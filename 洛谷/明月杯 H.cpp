#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
	int n,a,b, sum = 0;
	cin>>n;
	for(int i = 1;i <= n - 2;i++)
	{
		for(int j = 1 ;j <= n - 2;j++)
		{
			a = min(j,i);
			b = min(n-1-i,n-1-j);
			sum += a * b;
			a = min(i,n-1-j);
			b = min(j,n-1-i);
			sum += a * b; 
		}
	}
	cout<<sum;
	return 0;
} 
  
