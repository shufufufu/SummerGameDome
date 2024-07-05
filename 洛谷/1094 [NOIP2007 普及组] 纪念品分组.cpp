#include<bits/stdc++.h>
using namespace std;
int n,w,a[30010],L = 1,cnt;
int main()
{
	cin>>w>>n;
	for(int i = 1; i<= n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(L<=n)
	{
		if(a[n] + a[L] <= w)
		{
			L++;
			n--;
		} 
		else
		{
			n--;
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}