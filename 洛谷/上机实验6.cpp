#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main()
{
	int n = 0,i,l,flag;
	char str[20],*t,*w;
	for( i = 1; i <= 200; i++)
	{
		n = i*i;
		flag = 1;
		sprintf(str,"%d",n);
		l = strlen(str);
//		printf("%d\n",l);
		t = str;
		w = str + l - 1;
		while(t < w)
		{
			if(*t == *w )
			{
				t++;
				w--;
			}
			else
			{
				flag = 0;
				break;	
			}
		}
		if(flag)
		{
			printf("%d ",i);
		}
		
	}
	return 0;
}