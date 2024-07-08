#include<stdio.h>
#include<string.h>

void pr(int x[],int * l);
void func(int a[],int b[],int l,int x);
void pu(int b[],int l);

int main()
{
	int a[105],b[105],l;
	memset(b,0,sizeof(b));
	pr(a,&l);
//	printf("%d",l);
	func(a,b,l,1);
	pu(b,l);
	return 0;
}

void pr(int x[],int * l)
{
	int i = 1;
	do
	{
		scanf("%d",&x[i++]);
	}while( getchar() !='\n');
	*l = i-1;	
}

void func(int a[],int b[],int l,int x)
{
 int min = 1e9,p = 0;
 for(int i = 1;i <=l;i++)
 {
 	if(!b[i] && a[i] < min)
	 {
	 	min = a[i];
	 	p = 1;
	 }
 } 	
if(p == 0)
	return ;
for(int i = 1;i <=l;i++)
{
	if(a[i] == min)
	{
		b[i] = x;
	}
}
func(a,b,l,x+1);		
}

void pu(int b[],int l)
{
	for(int i = 1;i <=l;i++)
	{
		printf("%d ",b[i]);
	}
}