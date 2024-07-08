#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int n = 0,x = 0, y = 0;
	string str,str1,str2;
	cin>>str;
	for(int i = 0;i < str.size();i++)
	{
		if(str[i] == '.')
		{
			n = 1;
			x = i;
			break;
		}
		if(str[i] == '/')
		{
			n = 2;
			x = i;
			break;
		}
		if(str[i] == '%')
		{
			n = 3;
			x = i;
			break;
		}
	}
	if(n == 0)
	{
		reverse(str.begin(),str.end());
		for(size_t i = 0;i < str.size()-1&&str[i] == '0';++i)
		{
			y++;	
		}
		str.erase(0,y);
		cout<<str;
	}
	if(n == 1)
	{
		for(int i = 0;i < x;i++)
		{
			str1 += str[i];
		}
		reverse(str1.begin(),str1.end());
		for(size_t i = 0;i < str1.size() - 1 &&str1[i] == '0';++i)
		{
			y++;	
		}
		str1.erase(0,y);
		y = 0;
		for(int i = x + 1;i < str.size();i++)
		{
			str2 += str[i];
		}
		for(size_t i = 0;i < str2.size() - 1 && str2[i] == '0';++i)
		{
			y++;	
		}
		str2.erase(0,y);
		reverse(str2.begin(),str2.end());
		cout<<str1<<'.'<<str2;
	}
	if(n == 2)
	{	
		for(int i = 0;i < x;i++)
		{
			str1 += str[i];
		}
		reverse(str1.begin(),str1.end());
		for(size_t i = 0;i < str1.size() - 1 &&str1[i] == '0';++i)
		{
			y++;	
		}
		str1.erase(0,y);
		y = 0;
		for(int i = x + 1;i < str.size();i++)
		{
			str2 += str[i];
		}
		reverse(str2.begin(),str2.end());
		for(size_t i = 0;str2[i] == '0';++i)
		{
			y++;	
		}
		str2.erase(0,y);
		
		cout<<str1<<'/'<<str2;	
	}
	if(n == 3)
	{
		reverse(str.begin(),str.end() - 1);
		for(size_t i = 0;i < str.size() - 2 &&str[i] == '0';++i)
		{
			y++;	
		}
		str.erase(0,y);
		cout<<str;
		
	}
	
	return 0;
}

