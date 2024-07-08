#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	int n = 0;
	cin>>str;
	for(int i = 0;i <str.size();i++)
	{
		if(str[i] != '\r' && str[i] != '\n')n++;
	}
	cout<<n;
	return 0;
}