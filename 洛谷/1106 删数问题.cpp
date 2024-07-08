#include<bits/stdc++.h>
using namespace std;

string s;
int l,k,m,f,p,u,q,num[300],c[300];


int main()
{
	cin>>s>>k;
	l = s.length();
	m = l - k;
	f = m;
	for(int i = 0;i < l; i++)
	{
		num[i+1] = s[i] - '0';
//		cout<<num[i+1];
	}
//cout<<endl;
	while(m--)
	{	
		int n = 110;
		if(k == 0)
		{
			q++;
		}
		else
		for(int i = q+1; i<= q+k+1; i++)
		{
			if(i <= l)
			{
					if(num[i] < n)
				{
					p = i;
					n = num[p];
//					cout<<i<<' ';
				}
			}
		}
		if(k != 0)
		q = p;
		c[f-m] = num[q];
//		cout<<q<<' '<<k<<' '<<num[q]<<endl;
		if(k>0)
		{
			k = k-(q-u-2)-1;
			u = q;
		}
			
	}
	int z = 1;
	for(int i = 1;i <= f; i++)
	{
		if(c[i] == 0)
		{
			z++;
		}
		else
		{
			break;
		}
	}
	for(int i = z; i <= f; i++)
	{
		cout<<c[i];
	}
	
	if(z == f+1)
	{
		cout<<0;
	}
	return 0;
}