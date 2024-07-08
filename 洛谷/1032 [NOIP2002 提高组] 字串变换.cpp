#include<bits/stdc++.h>
using namespace std;

map<string ,int >mp;

int main()
{
	string a,b;
	cin>>a>>b;
	string x[10],y[10];
	int n = 1;
	while(cin>>x[n]>>y[n])
	{
		n++;
	}
	n--;
	queue<string> Q;
	queue<int> s;
	Q.push(a);
	s.push(0);
	while(!Q.empty())
	{
		if(Q.front() == b)
		{
			cout<<s.front();
			return 0;
		}
		if(s.front() == 10)
		{
			Q.pop();
			s.pop();
		}
		string t = Q.front();
		if(mp.count(t))
		{
			Q.pop();
			s.pop();
			continue;
		}
		mp[t] = 1;
		for(int i = 1;i <= n;i++)
		{
			int p = 0;
			while(t.find(x[i],p)!=-1)
			{
				p = t.find(x[i],p);
				Q.push(t.substr(0,p) +y[i]+t.substr(p+x[i].length()));
				s.push(s.front()+1);
				p++;
			}
		}
		Q.pop();
		s.pop();
	}
	cout<<"NO ANSWER!";
	return 0;
}