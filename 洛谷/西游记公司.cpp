#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long hour1 = 0, hour2 = 0, min1 = 0,min2 = 0,sec1 = 0,sec2 = 0,n = 0,g = 0;
	char m;
	cin>>hour1>>m>>min1>>m>>sec1;
	cin>>hour2>>m>>min2>>m>>sec2;
	cin>>n;
	g = n*((hour2 * 3600 + min2 * 60 + sec2 - hour1 * 3600 - min1 * 60 - sec1));
	cout<< g;
} 
