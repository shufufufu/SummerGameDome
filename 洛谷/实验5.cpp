#include <stdio.h>
int n, i, a[3], m;
void isArmstrong();
int main()
{
	isArmstrong();
	return 0;   
}

void isArmstrong()
{
	printf("There are follwing armstrong number smaller than 1000："); 
	for(n = 1; n < 1000; n ++)              //数字从1~1000逐一检验是否是阿姆斯特朗数 
	{	
		m = n;
	    for (i = 0; i < 3; i ++)            //通过循环将分离出的每一位数字存放在a[3]数组中 
	    { 
	        a[i] = m % 10;
	        m = m / 10;
	        if (m == 0)
	        	break;
	    }
	    
		if ( n == (a[0]*a[0]*a[0] + a[1]*a[1]*a[1] + a[2]*a[2]*a[2]) )
		    printf("%d ",n);      
    }
}
