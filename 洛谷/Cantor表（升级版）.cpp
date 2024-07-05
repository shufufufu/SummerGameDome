#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b){//辗转相除法求最大公约数
    if (!b)return a;//如果b=0，a是最大公约数
    else return gcd(b,a%b);//不然继续
}//提示：现在也可以使用__gcd(a,b)直接求。
int main()
{
	double a1 = 0,a2 = 0,b1 = 0,b2 = 0,c = 0;
	char x;
	cin>>a1>>x>>a2;
	cin>>b1>>x>>b2;
	
	a1*=b1;
	a2*=b2;
	c=gcd(a1,a2);
	a1/=c;
	a2/=c;
	cout<<a1<<" "<<a2;
}
