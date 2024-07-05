#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,x= 0,y = 5,flag = 0,flag1= 0;
	cin>>n;
	if(n == 1)
	{
		cout<<0<<endl;
		return 0;
	}
	
	
	cout<<2<<endl<<3<<endl;
	for(int i = 4 ;i <=1000000;i++)
	{
		for(int j = 1;j<i/2;j++)
		{
			flag1 = 0;
			if(i == 6*j-1||i == 6*j+1 ) 
			{
			for(int m = 2;m<=sqrt(i);m++)
			{
				if(i == (i/m)*m){
					flag1++;
					break;
				}	
			}
			if(flag1 != 0)
			{
				break;
			}	
				
			 y+=i;	
			if(y<=n)
			{
				cout<<i<<endl;
				x++;
			}
			else
			{
				flag++;
				break;
				
			}
		}
		
		}
		if(flag != 0)
		{
			break;
		}
	}

	cout<<x+2;
	return 0;
}
