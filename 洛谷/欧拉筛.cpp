#include<bits/stdc++.h>
using namespace std;

int pri[10000000],now = 0;
bool vis[10000000];

void sieve(long long n)
{
	now = 0;
	for(int i = 2;i <= n;n++)
	{
		if(!vis[i])pri[++now] = i;
		for(int j = 1;j <= now && pri[j] * i <= n;j++)
		{
			vis[pri[j]*i] = 1;
			if(i % pri[j] == 0)break;
		}
	}
}



int main()
{
	
	
}
