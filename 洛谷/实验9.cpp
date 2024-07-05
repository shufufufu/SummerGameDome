#include<stdio.h>
int vis[11],pos[5];
void find(int k);
int main()
{
	printf("由7、8、9组成的不重复的三位数有：\n");
	find(0);
	return 0;
}

void find(int k)
{
	if(k == 3)
	{
		printf("%d%d%d\n",pos[0],pos[1],pos[2]);
		return ;
	}
		for(int j = 7;j <= 9;j++)
		{
			if(vis[j] == 0)
			{
				pos[k] = j;
				vis[j] = 1;
				find(k+1);
				vis[j] = 0;
			}
		}	
}