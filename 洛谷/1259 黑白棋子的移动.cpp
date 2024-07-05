#include<bits/stdc++.h>
using namespace std;

int n,a[206],l;
void f(int a[],int n)
{
	if(a[1] == 3)return ;
	if(a[4] == 3)
	{
		for(int i = 1; i<=5; i++)
		{
			
			if(i == 2)
			{
				cout<<"ooo*o**--";
				for(int i = 10;i <= 2*l+2; i++)
	{
		if(a[i] == 1)
		{
			cout<<"o";
		}
		else if(a[i] == 2)
		{
			cout<<"*";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<endl;
				
			}
		if(i == 3)
			{
				cout<<"o--*o**oo";
				for(int i = 10;i <= 2*l+2; i++)
	{
		if(a[i] == 1)
		{
			cout<<"o";
		}
		else if(a[i] == 2)
		{
			cout<<"*";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<endl;
				
			}
			if(i == 4)
			{
				cout<<"o*o*o*--o";
				for(int i = 10;i <= 2*l+2; i++)
	{
		if(a[i] == 1)
		{
			cout<<"o";
		}
		else if(a[i] == 2)
		{
			cout<<"*";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<endl;
				
			}
			if(i == 5)
			{
				cout<<"--o*o*o*o";
				for(int i = 10;i <= 2*l+2; i++)
	{
		if(a[i] == 1)
		{
			cout<<"o";
		}
		else if(a[i] == 2)
		{
			cout<<"*";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<endl;
				
			}
			
			
		}
	return ;	
	}
	if(a[n] == 1&&a[n+1] == 2)
	{
		swap(a[n],a[2*n+1]);
		swap(a[n+1],a[2*n+2]);
		for(int i = 1;i <= 2*l+2; i++)
	{
		if(a[i] == 1)
		{
			cout<<"o";
		}
		else if(a[i] == 2)
		{
			cout<<"*";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<endl;
	f(a,n-1);
	}
	else
	{
		swap(a[n+1],a[2*n+1]);
		swap(a[n+2],a[2*n+2]);
		for(int i = 1;i <= 2*l+2; i++)
	{
		if(a[i] == 1)
		{
			cout<<"o";
		}
		else if(a[i] == 2)
		{
			cout<<"*";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<endl;
	f(a,n);		
	}
			
}
int main()
{
	cin>>n;
	l = n;
	for(int i = 1;i <= 2*n+2; i++)
	{
		if(i <= n)
		{
			a[i] = 1;
		}
		else if(i>n&&i<=2*n)
		{
			a[i] = 2;
		}
		else
		{
			a[i] = 3;
		}
	}
	for(int i = 1;i <= 2*n+2; i++)
	{
		if(a[i] == 1)
		{
			cout<<"o";
		}
		else if(a[i] == 2)
		{
			cout<<"*";
		}
		else
		{
			cout<<"-";
		}
	}
	cout<<endl;
	f(a,n);
	
	
	
	return 0;
}