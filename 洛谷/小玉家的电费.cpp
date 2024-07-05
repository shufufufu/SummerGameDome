#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int main()
{
	double a = 0,b = 0,c = 0;
	cin>>a;
	if(a > 150)
	{
		if(a > 400)
		{
			b = a - 400;
			c= b * 0.5663 + 250 * 0.4663 + 150 * 0.4463;
		}else{
		
		
		b = a - 150;
		c = b * 0.4663 + 150 * 0.4463; 
	}
	}else
	{
		c = a * 0.4463;
	}

	cout << fixed << setprecision(1) << c << endl;

	
}
