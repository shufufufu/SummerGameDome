#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	int a[10],jing[4][4] = {0};	
	int x = 0, y = 0,z = 0;
	cin>>str;
	for(int i =0;i < str.size();i++)
	{
	a[i] = str[i] - '0';
	}
	for(int i =0;i < str.size();i++)
	{
		x = a[i]/4;
		y = a[i]-x*3-1;
		if(i % 2 == 0)
		{
			jing[x][y] = 1;
		} 
		else
		{
			jing[x][y] = 2; 
		}
	}
	jing[2][0] = jing[1][3];
	
	for(int i = 0;i < 3;i++)
	{
		if((jing[i][0] == 1&& jing[i][1] == 1&& jing[i][2] == 1)
		||(jing [0][i] == 1&& jing[1][i] == 1&& jing[2][i] == 1)
		||(jing [0][0] == 1&& jing[1][1] == 1&& jing[2][2] == 1)
		||(jing [0][2] == 1&& jing[1][1] == 1&& jing[1][3] == 1))
	    {
			cout<<"xiaoa wins."	;
			z++;
			break;
	    }
	    if((jing[i][0] == 2&& jing[i][1] == 2&& jing[i][2] == 2)
		||(jing [0][i] == 2&& jing[1][i] == 2&& jing[2][i] == 2)
		||(jing [0][0] == 2&& jing[1][1] == 2&& jing[2][2] == 2)
		||(jing [0][2] == 2&& jing[1][1] == 2&& jing[1][3] == 2))
	    {
			cout<<"uim wins.";
			z++;
			break;
	    }
	    
	  	    
	}
	if(z == 0)cout<<"drew."<<endl;

	
	
}
