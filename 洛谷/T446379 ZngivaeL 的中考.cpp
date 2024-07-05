#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tag1 = 0,tag2 = 0;
	string grade;
	cin>>grade;
	for(int i = 0;i < 4;i++)
	{
		if(grade[i] == 'D')
		{
			cout<<"Never give up.";
			return 0;
		}
	}
	for(int i = 0;i < 4;i++)
	{
		if(grade[i] == 'C')
		{
			tag1 = 1;
		}
		if(grade[i] == 'A')
		{
			tag2 = 1;
		}
	}
	if(tag1 == 0 && tag2 == 1)
	{
		cout<<"I'm so happy.";
	}
	else
	{
		cout<<"This is ok.";
	}
	return 0;

}