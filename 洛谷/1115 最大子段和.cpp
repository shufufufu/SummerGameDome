#include<bits/stdc++.h>
using namespace std;

long long int n,a[200005],sum[200005],maxn;

int main()
{
	cin>>n;
	for(int i = 1 ; i <= n; i++)
	{
		cin>>a[i];
		if(sum[i-1] < 0)
		{
			sum[i] = a[i];
		}else
		{
			sum[i] = sum[i-1] + a[i];
		}
		
	}
	sort(sum+1,sum+n+1);
	cout<<sum[n];
	
	return 0;
}