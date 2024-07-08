#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,x= 0,flag = 0,flag1= 0;
	string str,str1;
	cin>>n>>x;
	if(n<5)
	{
			cout<<2<<endl<<3<<endl;
	}
	if(n%2 == 0)n++;
	
	for(int i = n ;i <=x;i+=2)
	{	
	
		for(int j = 1;j<i/2;j++)
		{
			flag1 = 0;
			if(i == 6*j-1||i == 6*j+1 ) 
			{
				for(int m = 2;m<=sqrt(i);m++)
				{
					if(i == (i/m)*m)
					{
					flag1++;
					break;
					}	
				}
			if(flag1 != 0)
			{
				break;
			}
			
			str = to_string(i);	
			str1 = str;
			reverse(str.begin(),str.end());
			if(str == str1)
			{
				cout<<i<<endl;
			}
			
			
				
			
			}
		
		}
		
	}

	
	return 0;
}
