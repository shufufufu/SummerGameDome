#include<bits/stdc++.h>
using namespace std;
int n ,cnt = 0,s,x = 1,p;
string str,str1;

int main()
{
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>str;
		s = str.size();
		cnt++;
		if(s > x)
		{
			x = s; 
			str1 = str;
			p = cnt;
		}
		if(s == x)
		{
			if(str1 < str)
			{
				x = s;
				str1 = str;
				p = cnt;
			}
		}
	}
	cout<<p<<endl;
	cout<<str1;
	return 0;
}