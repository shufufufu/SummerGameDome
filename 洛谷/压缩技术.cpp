#include<iostream>
#include<cstring>//��ʵ��û����
using namespace std;
int main()
{
    int n;
    cin>>n;
    //���󳤿�
    int Map[n*n+10];
    //����һ���Ǽ��õ����飬��ʵn*n�͹��ˣ�+10��Ϊ�˷���
    int Full;//����Ҫ�õ�
    bool Key=false;
    //�жϵ�ǰ�������1����������0����������ʼΪ0
    int p=0;
    //�Ѿ��Ǽǵ��ڼ�������������ָ��
    while(cin>>Full)//��������
    {
        int i;
        for(i=p;i<p+Full;i++)
            Map[i]=Key;//����һ������Ǽ�ΪKey������0��1
        p=i;
        Key=!Key;
        //����Ψһ�ѵ㣬
        /*
         *��!����ʾ�෴��
         *���ԭ��Ϊtrue�ͱ�Ϊfalse
         *���ԭ��Ϊfalse�ͱ�Ϊtrue
         *����Ͱѡ�0��1�������������롱���ֳ�����
         */
    }
    p=0;
    //ָ����㣬����Ҫ��ʼ��ͷ��ʼ����
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Map[p];
            p++;
            //���
        }
        cout<<endl;
        /*����ʽ���*/
    }
        
}
