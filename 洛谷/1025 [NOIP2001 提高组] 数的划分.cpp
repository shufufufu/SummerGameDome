#include<bits/stdc++.h>
using namespace std;
int n,k,a[210][210];

int main()
{
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= i&&j <= k;j++)
		{
			if(i == j)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = a[i-j][j] + a[i-1][j-1];
			}
			
		}
	}
	cout<<a[n][k];
	return 0;
}