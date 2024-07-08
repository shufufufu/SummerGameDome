#include<bits/stdc++.h>
using namespace std;
const int maxn = 1024;
int n,sump = 0,a[maxn][maxn] ,leng,size;

void shemian(int p,int p1,int size)
{
	if(size == 1)return ;
	
	for(int i = p;i < p+(size/2);i++)
	{
		for(int j = p1 ;j < p1+(size/2);j++)
		{
			a[i][j] = 0;
		}
	}
	
	shemian(p,p1+size/2,size/2);
	shemian(p+size/2,p1,size/2);
	shemian(p+size/2,p1+size/2,size/2);	
}


int main()
{	

	fill_n(&a[0][0], maxn * maxn, 1);
	cin>>n;
	n = pow(2,n);
	leng = n;
	shemian(0,0,leng);
	  
	for(int i = 0;i < leng;i++)
	{
		for(int j = 0;j < leng; j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}