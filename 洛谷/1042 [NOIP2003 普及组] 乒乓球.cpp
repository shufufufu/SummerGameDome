#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	char c;
	int s = 0,h = 0,d = 0;
	while(1)
	{
		cin>>c;
		str += c;
		if(c == 'E')break;
	}
	s = str.length();
	for(int i = 0;i < s;i++)
	{
		if(str[i] == 'W')
		{
			h++;
		}
		if(str[i] == 'L')
		{
			d++;
		}

		if((h>=11&&h>d+1)||(d>=11&&d>h+1))
		{
			cout<<h<<":"<<d<<endl;
			h = 0;
			d = 0;
		}
		if(str[i] == 'E')
		{
			cout<<h<<":"<<d<<endl<<endl;
			h = 0;
			d = 0;
			break;
		}
	}
	
	for(int i = 0;i < s;i++)
	{
		if(str[i] == 'W')
		{
			h++;
		}
		if(str[i] == 'L')
		{
			d++;
		}
		if((h>=21&&h>d+1)||(d>=21&&d>h+1))
		{
			cout<<h<<":"<<d<<endl;
			h = 0;
			d = 0;
		}
		if(str[i] == 'E')
		{
			cout<<h<<":"<<d<<endl;
			h = 0;
			d = 0;
			break;
		}
	}
	
	
}