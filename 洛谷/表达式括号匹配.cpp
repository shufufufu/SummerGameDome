#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;

	int n = 0;
	for(int i = 0;i < str.size();i++)
	{
		if(str[i] == '(')n++;
		if(str[i] == ')')n--;
		if(n < 0){
			break;
		}
	}
	
	if(n == 0)
	{
	cout<<"YES";}
	else
	 {
	 cout<<"NO"; }
	
}
