#include <stdio.h>

//调用函数声明 
void Prompt();
void Choose(int n);
void Pattern_1();
void Pattern_2();
void Pattern_3();
void Pattern_4();

//主函数----输出不同形式的九九乘法表 
int main()
{    
    int a;
    Prompt();            //输入前提示 
    scanf("%d", &a);     //从键盘获得选择 
    printf("----------------(^0^)----------------\n");
    Choose(a);          //按照选择输出对应的图案 
	return 0;
}
	
//输入前提示的函数 
void Prompt()
{
	printf("----------------o>_<~----------------\n");
    printf("▲       ▲▲▲       ▲        ▲▲▲\n");
    printf("▲▲      ▲▲       ▲▲         ▲▲\n");
    printf("▲▲▲     ▲       ▲▲▲          ▲\n");
    printf("(1)    (2)       (3)       (4)\n");
    printf("----------------(^0^)----------------\n");
    printf("根据上面提示图标选择输出图案形状的编号(1, 2, 3, 4): ");
}

//选择及其对应图案的函数 
void Choose(int n)
{
	switch(n)
    {
    	case 1: Pattern_1(); break;
    	case 2: Pattern_2(); break;
    	case 3: Pattern_3(); break;
    	case 4: Pattern_4(); break;
    	default: printf("\n\n下次再见！！！！！！！！！！\n");
	}
}

//选择1对应的图案 
void Pattern_1()
{

	int i, j;
	for (i = 1; i <= 9; i ++)
	{
		for (j = 1; j <= i; j ++)
		    printf("%d * %d = %-4d", i, j, i * j);
		printf("\n");
	}
}

//选择2对应的图案 
void Pattern_2()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= (10-i); j++)
		    printf("%d * %d = %-4d", i, j, i * j);
	    printf("\n");
	}
}

//选择3对应的图案 
void Pattern_3()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9-i; j++)
		    printf("            ");
		    for (j = 1; j <= 9; j++)
		        if(i>=j)
		            printf("%d * %d = %-4d", i, j, i * j);
	    printf("\n");
	}
}
//选择4对应的图案 
void Pattern_4()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j < i; j++)
		    printf("            ");
		    for (j = 1; j <= 10-i; j++)
		        printf("%d * %d = %-4d", i, j, i * j);
	    printf("\n");
	}
}
