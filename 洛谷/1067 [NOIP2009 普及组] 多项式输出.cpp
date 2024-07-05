#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,num,cnt = 0;
	cin >>n;
	if(n == 0)
	{
		cin>>num;
		cout<<num;
		return 0;
	}
	for(int i = n;i>=0;i--)
	{
		cin>>num;
		if(i == n)
		{
			if(num == 0)
			{
				cnt++;
				continue;
			}
			else if(num == 1)
			{
				cout<<"x^"<<i;
				continue;
			}
			else if(num == -1)
			{
				cout<<"-x^"<<i;
				continue;
			}
			else
			{
				cout<<num<<"x^"<<i;
				continue;
			}
		}
		if(i == 1)
		{
			if(num == 0)
			{
				continue;
			}
			else if(num > 1)
			{
				cout<<"+"<<num<<"x";
			}
			else if(num < -1)
			{
				cout<<num<<"x";
			}
			else if(num == 1)
			{
				cout<<"+"<<"x";	
			}
			else if(num == -1)
			{
				cout<<"-"<<"x";
			}
			continue;	 
		}
		
		if(i > 0)
		{
				if(num == 0)
			{
				continue;
			}
			else if(num > 1)
			{
				cout<<"+"<<num<<"x^"<<i;
			}
			else if(num < -1)
			{
				cout<<num<<"x^"<<i;
			}
			else if(num == 1)
			{
				cout<<"+"<<"x^"<<i;	
			}
			else if(num == -1)
			{
				cout<<"-"<<"x^"<<i;
			}
		}
		if(i == 0)
		{
			if(num > 0)
			{
				cout<<"+"<<num;
			}
			else if(num < 0)
			{
				cout<<num;
			}
		}
			
		
	}
	if(cnt == n)
	{
		cout<<0;
	}
	return 0;
}