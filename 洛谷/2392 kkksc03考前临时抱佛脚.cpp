#include<bits/stdc++.h>
using namespace std;
int a[5],i,j,k,sum,t,homework[21],dp[2501];
int main(){
	for(i=1;i<=4;i++)
		cin>>a[i];
	for(i=1;i<=4;i++)
	{
		sum=0;	
		for(j=1;j<=a[i];j++)
			{
			cin>>homework[j];//输入
			sum+=homework[j];//总时间累加
			}
		for(j=1;j<=a[i];j++)
		{
			for(k=sum/2;k>=homework[j];k--)//只要是总和的一半
				dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);//01背包
		}	
		t+=sum-dp[sum/2];//累加为另一个脑子
		for(j=1;j<=sum/2;j++)
		{
			dp[j]=0;//清零
		}
	}
	cout<<t;//输出
	return 0;
}