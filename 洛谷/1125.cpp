#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	char x,y;
	cin>>str;
	int maxn = 1,minn = 100,a = 0,b = 0;
	for(int i = 0;i < str.size();i++)
	{
		a = 1;
		for(int j = 0;j < str.size();j++)
		{
			if(str[i] == str[j])
			{
				a++;
			}
		}
		if(a > maxn)
		{
			maxn = a;
		}
		if(a < minn)
		{
			minn = a;
		}
	}
	
	b = maxn - minn;
	
	if(b == 0||b == 1)
	{
		cout<<"No Answer"<<endl<<0;
			return 0;
	}
	
	for(int i = 2; i <= sqrt(b);i++)
	{
		if(b % i == 0)
		{
			cout<<"No Answer"<<endl<<0;
			return 0;
		}
	}
	
	cout<<"Lucky Word"<<endl<<b;
	return 0;
	
	
	
}