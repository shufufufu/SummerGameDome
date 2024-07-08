#include<bits/stdc++.h>
using namespace std;

int main()
{
	int day = 0,unhappy_degree = 0,all_unhappy_degree = 0;
	int schooltime = 0,outschooltime = 0;
	int time[3000],left_time[3000];
	cin>>day;
	for(int i=0;i<day;i++)
	{
		
		cin>>schooltime>>outschooltime;
		time[i] = schooltime + outschooltime;
		
	}
	
	for(int i=0;i<day;i++)
	{
		
		left_time[i] = time[i] - 8;
		unhappy_degree = unhappy_degree + left_time[i];
		all_unhappy_degree = all_unhappy_degree + unhappy_degree;
	}
	
	cout<<all_unhappy_degree;
	
}
