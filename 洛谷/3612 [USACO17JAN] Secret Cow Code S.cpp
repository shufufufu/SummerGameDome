#include<bits/stdc++.h>
using namespace std;

string str;
long long int n,l,cnt,i;

int main()
{
	cin>>str>>n;
	l = str.length();
		while(l<n)
	{
		i=l;
		while(n>i)	i*=2;
		i=i/2;
		n-=(i+1); 
		if(n==0)	n=i;
	}
	cout<<str[n-1]; 
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//
//string str;
//long long int n,m,l,cnt;
//
//
//
//int main()
//{
//	cin>>str>>n;
//	m = str.length();
//	l = m;
//	for(long long int i = m; i <= n ; i*=2 )
//	{
//		l *=2;
//	}
//	for(int i = 1; ; i++)
//	{
//		n = n - l/2 - 1 ;
//		if(n == 0)
//		{
//			n = l/2;
//		}
//		for(;l>n;)
//		{
//		 if(l/2<n)break;
//		 l /= 2;	
//		}
//		
//		if(n<=m)
//		break;
//	}
//	cout<<str[n-1]; 
//	return 0;
//}