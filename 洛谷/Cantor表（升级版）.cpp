#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b){//շת����������Լ��
    if (!b)return a;//���b=0��a�����Լ��
    else return gcd(b,a%b);//��Ȼ����
}//��ʾ������Ҳ����ʹ��__gcd(a,b)ֱ����
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
