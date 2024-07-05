#include<bits/stdc++.h>
using namespace std;

int t,n,r,num[1010],cnt = 0,p[10],k = 0;
string x;
int a[100005],b[100005] = {1,1},c[100005],la,lb = 1,lc = 1;


void mul(int f)
{
	x = to_string(f);
	la = x.length();
	lb = lc;
	memset(c,0,sizeof(c));
	for(int i = 0;i < la; i++)
	{
		a[la-i] = x[i] - '0';
	}
	for(int i = 1;i <= la;i++)
	{
		for(int j = 1;j <= lb;j++)
		{
			c[i+j-1] += a[i] * b[j];
			c[i+j] += c[i+j-1]/10;
			c[i+j-1] %= 10;
		}
	}
	lc = la + lb;
	while( c[lc] == 0 && lc > 1)
	{
		lc--;
	}
	for(int i = 1;i <= lc;i++)
	{
		b[i] = c[i];
	}	 	
}

void sec(int x,int y)
{
	cnt = 0;
	for(int i = 1;i <= x;i++)
	{
		mul(i);
	}
	for(int i = 1;i <= lc;i++)
	{
		if(c[i] == y)
		{
			cnt++;
		}
	}
	p[k] = cnt;
	k++;
//	for(int i = lc;i >= 1;i--)
//	{
//		cout<<c[i];
//	}
//	cout<<endl;
}

int main()
{
	cin>>t;
	for(int i = 1;i <= t;i++)
	{
		cin>>n>>r;
		sec(n,r);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		b[0] = 1,b[1] = 1;
		lb = 1,lc = 1;
	}
	for(int i = 0;i < k;i++)
	{
		cout<<p[i]<<endl;
	}
	
	return 0;
}