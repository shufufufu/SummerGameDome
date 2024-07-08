#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0, m = 0,x = 0 ,y = 0;
	int a,b,c,d,z = 0;
	int q,e;
	int o,p;
	cin>>n>>m>>x>>y;
	int hongzha[110][110] = {0},times[110][110] = {0};
	int zuobiao[1000],zuobiaoy[1000];
	
	for(int i = 0;i < 4*x;i+=4)
	{
		cin>>a>>b>>c>>d;
		zuobiao[i] = a;
		zuobiao[i+1] = b;
		zuobiao[i+2] = c;
		zuobiao[i+3] = d; 
	}
	for(int i = 0;i < 2*y;i+=2)
	{
		cin>>q>>e;
		zuobiaoy[i] = q	;
		zuobiaoy[i+1] = e;	
	}
	for(int i = 0;i < 4*x;i+=4)
	{
		z++;
		for(int j = zuobiao[i];j <= zuobiao[i+2];j++)
		{
			
			for(int k = zuobiao[i+1];k <= zuobiao[i+3];k++)
			{
				hongzha[j][k]++;
				
				times[j][k] = z;
			}
		}
	}
	
	for(int i = 0;i < 2*y;i+=2)
	{
		o = zuobiaoy[i];
		p = zuobiaoy[i+1];
		if(hongzha[o][p] > 0)
		{
			cout<<"Y"<<' '<<hongzha[o][p]<<' '<<times[o][p]<<endl;
		}
		else
		{
			cout<<"N"<<endl;	
		}
	}
	
	return 0;
} 
