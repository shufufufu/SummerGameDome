#include <stdio.h>  
  
void fun(int x, int *p, int *n);

int main() {  
    int x = 24,n = 0;  
    int factors[100];  
    fun(x, factors, &n);    
    printf("若x中的值为%d，则有%d个数符合要求，它们是:", x, n);  
    for (int i = 0; i < n; i++) 
	{  
        printf("%d ", factors[i]);  
    }  
    printf("\n");   
    return 0;  
}

void fun(int x, int *p, int *n) 
{  
    *n = 0;   
    for(int i = 1; i <= x; i++)
	{
		if(x % i == 0 && i%2 == 0)
		{
			p[*n] = i;
			(*n)++;
		}
	} 
} 