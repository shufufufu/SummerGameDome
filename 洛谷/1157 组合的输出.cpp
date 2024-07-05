#include<bits/stdc++.h>
using namespace std;
int num[30],r;

void s(int x, int y,int p)//传入p的原因是防止每一次递归都是从1开始搜索，防止出现重复答案，并且确保答案从小到大排列
{

	if(y == r)
	{
		for(int i = 1;i <=x;i++)
		{
			if(num[i] == 1)
			{
				cout<<setw(3)<<i;
			}
		}
		cout<<endl;
		return ;		
	}	

	for(int i = p;i <= x;i++)
	{
		num[i] = 1;
		s(x,y+1,i+1);//在此处对p赋值为i+1使得递归中的搜索位置更新，不再搜索之前的位置
		num[i] = 0;
	}		
}

int main()
{
	int n;
	cin>>n>>r;
	s(n,0,1);
	return 0;
}