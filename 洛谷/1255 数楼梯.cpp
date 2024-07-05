#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int a[maxn],b[maxn],c[maxn],lc = 1;
int main()
{
//	int a,b,c,n;
//	a = 1;
//	b = 2;
//	cin>>n;
//	for(int i = 3;i <= n;i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	cout<<c;
	int n;
	a[1] = 1;
	b[1] = 2;
	cin>>n;
	if(n == 1)
	{
	cout<<1;
	return 0;
	}
	if(n == 2)
	{
		cout<<2;
		return 0;
	}
	for(int i = 3;i <= n;i++)
	{
		
		memset(c,0,sizeof(c));
		for(int j = 1; j <= lc;j++)
		{
			c[j] += a[j] + b[j];
			c[j+1] = c[j] / 10;
			c[j] = c[j] % 10;
		}
		if(c[lc+1] > 0)lc++;
		for(int j = 1;j <=lc ;j++)
		{
			a[j] = b[j];
		}
		
		for(int j = 1;j <=lc;j++)
		{
			b[j] = c[j];
		}
		
	}
	for(int i = lc;i >= 1;i--)
		{
			cout<<c[i];
		}
		
		
		
		return 0;



}