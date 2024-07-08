#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long s = 0,v = 0;//路程和速度
	long long used_time = 0,used_hour = 0;
	cin>>s>>v;
	used_time = s/v;
	if(s%v != 0)used_time++;
	used_time += 10;
	used_hour = used_time/60;
	used_time %= 60;
	if(used_hour > 7)
	{
		used_hour -= 7;
		used_hour = 24 - used_hour;
		if(60 - used_time >= 10)
	{
		cout<<used_hour<<":"<<60-used_time;
	}
	else
	{
		cout<<used_hour<<":0"<<60-used_time;
	}
	return 0;	
	}
		
	if(60 - used_time >= 10)
	{
		cout<<"0"<<7-used_hour<<":"<<60-used_time;
	}
	else
	{
		cout<<"0"<<7-used_hour<<":0"<<60-used_time;
	}
	
	
}
