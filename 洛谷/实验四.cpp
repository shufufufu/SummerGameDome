#include<stdio.h>  
  
int a, b[11], n = 0, k, t;  
  
void cin(int num)  
{  
    while(num > 0)   
    {  
        b[n] = num % 10;  
        num /= 10;  
        n++;  
    }  
}  
  
void cout(int b[])  
{  
    for(int i = 0; i < n; i++) 
    {  
        printf("%d", b[i]);  
    }  
    printf("\n");  
}  
  
void ncout(int b[])  
{  
    for(int i = n - 1; i >= 0; i--)  
    {  
        printf("%d", b[i]);  
    }  
    printf("\n");  
}  
  
void sort(int b[])  
{  
    for(int i = 0; i < n; i++)  
    {  
        k = i;  
        for(int j = i + 1; j < n; j++)  
        {  
            if(b[k] < b[j])  
            {  
                k = j;  
            }  
        }  
        if(k != i)   
        {  
            t = b[i];  
            b[i] = b[k];  
            b[k] = t;  
        }  
    }  
}  
  
int main()  
{  	
	printf("请输入一位正整数：");
	
    scanf("%d", &a);
    if(a <= 0)
	{
		printf("输入数据不合法。\n");
		return 0;
	}
    cin(a); 
	printf("按逆序显示输出各位数字：") ;
    cout(b);  
    sort(b);  
    printf("分离数字所组成的最大数为：");
    cout(b);  
    printf("分离数字所组成的最小数为：");
    ncout(b);  
      
    return 0;  
}