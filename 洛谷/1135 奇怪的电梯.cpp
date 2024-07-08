#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,e[210],vis[210];//引入vis，防止出现重复经过一个楼层，出现无效步数，缩短时间
	memset(vis,0,sizeof(vis));
	cin>>n>>a>>b;
	for(int i = 1;i <= n;i++)
	{
		cin>>e[i];
	}
	vis[a] = 1;
	queue < int > f;
	queue < int > s;
	f.push(a);
	s.push(0);
	while(!f.empty())
	{
		if(f.front() == b)
		{
			cout<< s.front();
			return 0;
		}
		for(int i = 1 ; i <= 2;i++)
		{
			int df = f.front() + pow(-1,i)*e[f.front()];
			if(df > 0 && df <= n && !vis[df])
			{
				f.push(df);
				s.push(s.front()+1);
				vis[df] = 1;
			}
		}
		f.pop();
		s.pop();
		
		
	} 
	cout<<-1;
}
