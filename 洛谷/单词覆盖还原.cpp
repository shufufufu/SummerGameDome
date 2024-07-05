#include<bits/stdc++.h>
#include<string>
using namespace std;


int main()
{
	string str1;
	cin>>str1;
	int boy=0,girl=0;
	
	
	for(int i=0;i<str1.length();i++)
	{
		if(str1[i]=='b'||str1[i+1]=='o'||str1[i+2]=='y')
		{
			boy++;	
		}
		if(str1[i]=='g'||str1[i+1]=='i'||str1[i+2]=='r'||str1[i+3]=='l')
		{
			girl++;
		}	
		
	} 
	
	cout<<boy<<endl<<girl<<endl;
	
} 
