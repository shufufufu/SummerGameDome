#include <bits/stdc++.h>//luogu����
using namespace std;

char a,b='0';//ע���ˣ�һ���Ǹ�ֵΪ'0'��
int n,ans[1000001],zz=1;//zz��ָ�����˼���������洢�ڼ�λ

int main()
{
 while(cin>>a)
 {
 	n++;
 	if(a==b)
 		ans[zz]++;
 	else
 		ans[++zz]++,//��Ч�ڣ�zz=zz+1;ans[zz]++
 		b=a;//������ , ���� ; ��ԭ������û�д�{ }
 }
 cout<<sqrt(n);//ƽ�������õ���<cmath>������<math.h>��Ҳ����һ�е�����
 for(int i=1 ; i<=zz ; i++)
     cout<<" "<<ans[i];
}
