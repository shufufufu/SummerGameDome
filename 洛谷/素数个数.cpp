#include<bits/stdc++.h>
using namespace std;
bool v[1000000000];
int cnt = 0;
void prime(int n)
{
	for(int i = 2;i <= n;i++)
	{
		if(v[i])
		{
			continue;
		}
		cnt++;
		for(int j = i; j <=n/i;j++)
		{
			v[i*j] = 1;
		}
		
	}
}
int main()
{
	int n ;
	cin>>n;
	prime(n);
	cout<<cnt;
	return 0; 
}
 
