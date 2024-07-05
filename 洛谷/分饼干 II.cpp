#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	long long T = 0;
	long long N = 0,K = 0,min = 0;
	
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		
		min = K * (K + 1) / 2;
		
		if(N < min)
		{
		cout<<"No"<<endl;
	}else
	{
		cout<<"Yes"<<endl;
	}
	
	}
	
	
	
}
