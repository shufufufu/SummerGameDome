#include<bits/stdc++.h>
using namespace std;

int a[100005];

void qsort(int L,int R)
{
	int x = L, y = R,mid = a[(x+y)/2];
	while(x<=y)
	{
		while(a[x]<mid)x++;
		while(a[y]>mid)y--;
		if(x<=y)
		{
			swap(a[x],a[y]);
			x++;
			y--;
		}
	}
	if(y>L)qsort(L,y);
	if(x<R)qsort(x,R);
}

int main()
{
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	qsort(1,n);
	for(int i = 1;i <= n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}