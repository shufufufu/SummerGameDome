#include<bits/stdc++.h>
using namespace std;

int n = 0;
int a[100] = {0}, b[100] = {0},c[100] = {0};

void yanghui(int n)
{	
	
	for(int i = 1;i <= n;i++)
	{
		for(int i = 0;i <=20;i++)
	{
		a[i] = c[i]; 
	}
		for(int j = 1;j <= i;j++)
		{
			b[j] = a[j - 1] + a[j];
			cout<<b[j]<<' ';
			c[j] = b[j];	
		}
		cout<<endl;
	}
}






int main()
{
	cin>>n;
	c[1] = 1;
	yanghui(n);
	
	return 0;
}
