#include<stdio.h>
#include<string.h>

int c(int p);

int main()
{
	int i,x,num[11];
	
	memset(num, 0 ,sizeof(num));
	
	for(i = 1; i <= 10000; i++)
	{	
		x = c(i);
		num[x]++;
	}
	
	for(i = 1; i<= 9; i++)
	{
		printf("%d ",num[i]);
	}
	
	
	return 0;
}

int c(int p)
{
	int z = 1;
	while(p)
	{
		if(p%10)
		{
			z*= p%10;
		}
		p /=10;
	}
	if(z/10 > 0)
	{
		return c(z);
	}
	else
	{
		return z;
	}	
	
	
}
