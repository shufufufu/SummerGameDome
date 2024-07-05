#include<bits/stdc++.h>
using namespace std;

	int n,a[2000],b[2000],c[2000],la,lb,lc;
	string x,y;
	
	 
int main()
{
	cin>>n>>x>>y;
	la = x.length();
	lb = y.length();
	lc = max(la,lb);
	
	for(int i = 0;i < la;i++)
	{	
		if(x[la-1-i] >= 'A'&&x[lb-1-i] <= 'Z')
		{
			a[i] = x[la-1-i]-'A'+10;	
		}else
			a[i] = x[la - 1 - i] - '0';
	}
	
	for(int i = 0;i < lb;i++)
	{	
		if(y[lb-1-i] >= 'A'&&y[lb-1-i] <= 'Z')
		{
			b[i] = y[lb-1-i]-'A'+10;
		}else
			b[i] = y[lb - 1 - i] - '0';
	}
	for(int i = 0; i < lc;i++)
	{
		c[i] += a[i] + b[i];
		c[i+1] = c[i]/n;
		c[i] %= n;
	}
	if(c[lc] == 0)lc--;
	
	for(int i = 0; i <= lc;i++)
	{
		if(c[lc-i] >= 10)
		{
		cout<<char(c[lc-i]-10+'A');
		}
		else
		cout<<c[lc-i];
	}
	
	
	
	return 0;
}