#include<stdio.h>
void func(int n, int m);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	func(n,m);
	return 0;
}

void func(int n, int m)
{
	int max,min;
	if(n>m)
	{
		max = n;
		min = m;
	}else
	{
		max = m;
		min = n;
	}
	if(max%min == 0)
	{
		printf("%d",min);
		return ;
	}
	else
	{
		func(min,max%min);
	}
	
}