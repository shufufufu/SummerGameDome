#include<bits/stdc++.h>
using namespace std;

int n,num[10010],p = 2,cnt,sum = 1;
string x;
int a[100005],b[100005] = {1,1},c[100005],la,lb = 1,lc = 1;

void f(int x)
{
	
	for(int i = 1;;i++)
	{
		if((x -= p)>=0)
		{
			num[i] = p;
			p++;
		}
		else if(x == 0)
		{
			break;
		}
		else
		{
			x +=p;
			if(x >= i)
			{
				for(int j = 1;j <= i;j++)
				{
					num[j] += x/i;
				}
				for(int k = i;k >=i-x/i;k--)
				{
					num[k] += 1;
				}
			}
			else
			{
				for(int k = i;k >=(i-x%i);k--)
				{
					num[k] += 1;
				}	
			}
			break;
		}
		cnt = i;
	}
}

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

int main()
{
	cin>>n;
	f(n);
	for(int i = 1;i <=cnt;i++)
	{
		cout<<num[i]<<" ";
		int z = num[i];
		mul(z);
	}
	cout<<endl;
	for(int i = lc;i >= 1;i--)
	{
		cout<<c[i];	
	}
	return 0;
}