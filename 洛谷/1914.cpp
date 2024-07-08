#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	string str;
	cin>>str;
	for(int i = 0;i<str.size();i++)
	{
		str[i] = (str[i] - 'a' + n) % 26 + 'a';
	}
	cout<<str;
	
} 
