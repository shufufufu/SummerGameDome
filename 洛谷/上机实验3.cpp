#include<stdio.h>
#include<string.h>
int main()
{
	char a[110],b[110];
	int la,lb,lc;
	int num1[110],num2[110],c[110];
	memset(c,0,sizeof(c));//注意数组c要清零
	scanf("%s%s",a,b);
//	printf("%s\n%s\n",a,b);
	la = strlen(a);
	lb = strlen(b);
//	printf("%d\n%d\n",la,lb);
	lc = la+lb;
	for(int i = 0; i < la;i++)
	{
	num1[la-i] = a[i] - '0';	
	}
//	printf("%d\n",num1[1]);
	for(int i = 0; i < lb;i++)
	{
	num2[lb-i] = b[i] - '0';	
	}
	
	for(int i = 1;i <=la; i++)
	{
		for(int j = 1; j <= lb; j++)
		{
			c[i+j-1] += num1[i] * num2[j];
			c[i+j] += c[i+j-1]/10;
			c[i+j-1] %= 10;
		}
	}
	while(c[lc] == 0 && lc>1)
	{
		lc--;
	}
//	printf("%d\n",c[1]);
	for(int i = lc ; i>=1; i--)
	{
		printf("%d",c[i]);
	}
	return 0;
}