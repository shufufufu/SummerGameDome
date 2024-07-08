#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;	

int main()
{
long long int a,n,cnt = 0,minn = 5000,maxn = 0;
	int t[5005] = {0};
	cin>>n;
	for(int i = 0 ; i < n;i++)
	{
		cin>>a;
		t[a]++;
		minn = min(a,minn);
		maxn = max(a,maxn);	
	}
	for(int i =minn;i <= maxn/2;i++)
	{
		if(t[i]>1&&t[2*i]>1)
		{
			cnt = (((((((t[i]-1)*t[i])/2)%MOD)*(t[2*i]*(t[2*i]-1)/2)%MOD)%MOD)+cnt)%MOD;
		}
		for(int j = minn;j <= maxn/2;j++)
		{
			if(i != j&&t[i]>=1&&t[j]>=1&&t[i+j]>1)
			{
			cnt = (((((t[i]*t[j])%MOD)*((t[i+j]*(t[i+j]-1)/2)%MOD))%MOD)+cnt)%MOD;
			}
		}
	}
	cout<<cnt;
	return 0;
}