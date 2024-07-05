#include<bits/stdc++.h>
using namespace std;

int quickPower(int a, int b,int m)
{
	long long ans = 1, base = a % m;
	while(b > 0)
    {
		if(b & 1)
			(ans *= base) %= m;
		
        (base *= base) %= m;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int a,b,m,k;
	cin>>a>>b>>m;
	k = quickPower(a,b,m);
	cout<<a<<"^"<<b<<" mod "<<m<<"="<<k;
	return 0;	
}