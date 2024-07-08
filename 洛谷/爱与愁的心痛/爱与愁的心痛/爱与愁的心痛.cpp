#include<iostream>
using namespace std;

int main()
{
	int n = 0, m = 0,num = 0,re = 0, min =1000000;
	int a[3005];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a[i] = num;
	}
	for (int i = 0; i <= n-m; i++)
	{
		for (int j = i; j < i+m; j++) 
		{
			re = re + a[j];
		}
		
		if (re < min)min = re;

		re = 0;



	}
	

	cout << min;
}
