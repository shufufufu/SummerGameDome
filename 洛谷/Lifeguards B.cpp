#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N = 0,head = 0,tail = 0,rec = 0,a = 0,b = 0,time = 0;
	int max = 0,z = -1;
	int head_data[1000],time_data[1000],m[1000];
	cin>>N;
	for(int i = 0;i < N;i++)
	{
		cin>>head>>tail;
		rec = tail - head;
		head_data[i] = head + 1;
		time_data[i] = rec;
		
	}
	for(int n = 0;n < N;n++)
{
	z++;
	fill(begin(m), end(m), 0);
	for(int i = 0;i < N;i++)
	{
		if(i != z)
		{
		
		a = head_data[i];
		b = time_data[i];
		for(int j = a;j < a + b;j++)
		{
			m[j]++;
		}
		}
	}
	
	for(int i = 0;i < 1000;i++)
	{
		if(m[i] != 0)time++;
	}
	if(time>max)max = time;
	time = 0;
	
	
}
	
	cout<<max;
	
	
	
	
} 
