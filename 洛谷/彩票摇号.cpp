#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,x = 0;
	int a[7],b[7],y[8] = {0};
	cin>>n; 
	for(int i = 0;i<7;i++)
	{
		cin>>a[i];
	}
	for(int i = 0;i < n;i++)
	{
		x = 0;
		for(int j = 0;j < 7;j++)
		{
			cin>>b[j];
		}
		for(int k = 0;k < 7; k++)
		{
			for(int m = 0;m < 7;m++)
			{
				if(a[k] == b[m])x++;
			}
		}
		
		y[x]++;
		
	}
	cout<<y[7]<<' '<<y[6]<<' '<<y[5]<<' '<<y[4]<<' '<<y[3]<<' '<<y[2]<<' '<<y[1];
	
}
