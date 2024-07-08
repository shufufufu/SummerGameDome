#include<bits/stdc++.h>
using namespace std;

void fnc(string str)
{
	int p,k;
	string sub = {']'},ss,snum,sc;
	int l = str.length();
	size_t pos = str.find(sub);
	if(pos == string::npos)
	{
		cout<<str;
		return ;
	}
	for(int i = pos;;i--)
	{
		if(str[i] == '[')
		{
			p = i;
			break;
		}
	}
	for(int i = pos;;i--)
	{
		if(str[i]>='0'&&str[i] <= '9')
		{
			k = i;
			break;
		}
	}
	ss = str.substr(k+1,pos-k-1);//截取出来的字符；
	snum = str.substr(p+1,k-p);
    int m = stoi(snum);//截取出来的数字；
    for(int i = 0;i < m;i++)
	{
		sc += ss;	
	}
	str.erase(p,pos-p+1);
	string str1 = str.insert(p,sc);
	fnc(str1);
}


int main()
{
	string str;
	cin>>str;
	fnc(str);
	return 0;
}