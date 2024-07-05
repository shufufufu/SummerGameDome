#include<bits/stdc++.h>
using namespace std;
string x,y;
int a[101]={0},b[101]={0},lb = 100,n = 0,f = 0; 

void mul(int a[], int c)
{
	int g = 0;
	for(int i = 0;i<=100;i++)
	{
		a[i] = a[i] * c + g;
		g = a[i] / 10;
		a[i] = a[i] % 10;
	}
} 

void add(int a[],int b[])
{
	int g = 0;
	for(int i = 0;i<=100;i++)
	{
		b[i] = a[i] + b[i] + g;
		g = b[i] / 10;
		b[i] = b[i] % 10; 
	}
}



int main()
{
   a[0] = 1;
 cin>>n;
 

 for(int j = 1;j <= n;j++)
 {

 	mul(a,j);
 	add(a,b);

 }

for(int i = 100;i>=0;i--)
{
	if(b[i] != 0)
	{
	break;
	}
	else
	{	
	lb--;
	}
}

 for(int i = lb;i>=0;i--)
 {
 	cout<<b[i];
 	
 }

	
	
}
