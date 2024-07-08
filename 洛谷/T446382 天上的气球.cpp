#include<iostream>
using namespace std;

int main()
{
	long int n,m,k,high[10010][10010],co[10010][10010];
	long int dx,dy,h,c;
	cin >> n >> m >> k;
	for(int i = 0;i < k;i++)
	{
		cin>>dx>>dy;
		cin>>h>>c;
		if(high[dx][dy] == 0)
		{
			high[dx][dy] = h;
			co[dx][dy] = c;
			continue;
		}
		if( h < high[dx][dy])
		{
			high[dx][dy] = h;
			co[dx][dy] = c;
		}
	}
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1 ;j <= m;j++)
		{
			if(high[i][j] == 0)
			{
				cout<<0<<' ';
			}
			else
			{
				cout<<co[i][j]<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}