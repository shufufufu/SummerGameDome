#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x,y;
	int a[100005],b[100005],c[100005],la , lb;
	cin>>x>>y;
	la = x.length();
	lb = y.length();
	if(la < lb || la == lb && x<y)
	{
		swap(x,y);
		swap(la,lb);
		cout<<'-';
	}
	for(int i = 0;i < la ;i++)
	{
		a[la-i] = x[i] - '0' ;
	}
	for(int i = 0;i < lb ;i++)
	{
		b[lb-i] = y[i] - '0' ;
	}
	for(int i = 1;i<=la;i++)
	{
		if(a[i]<b[i])
		{
			a[i] += 10;
			a[i+1]--;
		}
		c[i] = a[i] - b[i];
	}
	while( c[la] == 0 && la>1)la--;
	for(int i = la;i>=1;i--)
	{
		cout<<c[i];
	}
	return 0;
}
