#include<bits/stdc++.h>
using namespace std;

int n,p,z = 0;
long long int l,a[310];


int main()
{
	cin>>n;
	for(int i = 1; i<= n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	while(p<=n)
	{
		if(!z)
		{
			l += abs(a[n]-a[p])*abs(a[n]-a[p]);
			p++;
			z++;
			z%=2;
		}
		else
		{
			l += abs(a[n]-a[p])*abs(a[n]-a[p]);
			n--;
			z++;
			z%=2;
		}
	}
	cout<<l;
	
	return 0;
	
	
}