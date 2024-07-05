#include<bits/stdc++.h>
using namespace std;

int a[1010];
int f(int n)
{
	if(a[n] != 0)
	return a[n];
	int sum = 0;
	sum++;
	for(int i = 1; i <= n/2;i++)
	{
		sum += f(i);
	}
	return a[n] = sum;
}




int main()
{
	int n;
	cin>>n;
	cout<< f(n);
	return 0;
}