#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],ans;
	ans=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(a[i]<a[j])
				ans++;
	printf("%d",ans);
}