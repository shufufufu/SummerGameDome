#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
	string str;
	int n , x, y = 0;
	cin>>n>>x;
	for(int i = 1;i <=n;i++)
	{
		str +=to_string(i);
	} 
	for(int i = 0;i<=str.length();i++)
	{
		if(str[i] - '0' == x)y++;
	}
	cout<<y;
	return 0;
}
