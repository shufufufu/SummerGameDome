#include<stdio.h>

unsigned short Max(unsigned short x, unsigned short y, unsigned short z);
unsigned short Min(unsigned short x, unsigned short y, unsigned short z);

int main()
{
	unsigned short a, b, c, umax, umin, orimax, orimin; 
	printf("Input three integers:");
	scanf("%hu%hu%hu", &a, &b, &c);
	umax = Max(a, b, c);
	orimax = umax;
	umin = Min(a, b, c);
	orimin = umin;
	printf("The maxmum unsigned integer is %hu.\nAnd its corresponding input value is %hd.\n", umax, orimax);
	printf("The minmum unsigned integer is %hu.\nAnd its corresponding input value is %hd.\n", umin, orimin);
	return 0;
}

unsigned short Max(unsigned short x, unsigned short y, unsigned short z)
{
	unsigned short max;
	if(x > y)
	   max = x;
	else
	   max = y;
	   
	if(z > max)
	   max = z;
	   
	return max; 
}

unsigned short Min(unsigned short x, unsigned short y, unsigned short z)
{
	unsigned short min;
	if(x < y)
	   min = x;
	else
	   min = y;
	   
	if(z < min)
	   min = z;
	   
	return min;
}

