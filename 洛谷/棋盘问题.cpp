#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n = 0,m = 0,min = 0,max = 0;
	long long int number_of_rectangle = 0,number_of_square = 0,all_graph = 0;
	
	cin>>n>>m;
	
	all_graph = 1ll * ((n*(n+1))/2)*((m*(m+1))/2);
	min = n;
	max = m;
	if(m<min) min = m,max = n;
	for(int i = 0;i<min;i++)
	{
		number_of_square = number_of_square + ((i+1)*(max-(n-i)+1));	
	}
	number_of_rectangle = all_graph - number_of_square;
	
	cout<<number_of_square<<" "<<number_of_rectangle<<endl;
	
	return 0;
}
