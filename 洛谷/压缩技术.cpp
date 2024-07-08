#include<iostream>
#include<cstring>//事实上没有用
using namespace std;
int main()
{
    int n;
    cin>>n;
    //矩阵长宽
    int Map[n*n+10];
    //设置一个登记用的数组，其实n*n就够了，+10是为了防爆
    int Full;//输入要用的
    bool Key=false;
    //判断当前输入的是1的数量还是0的数量，初始为0
    int p=0;
    //已经登记到第几个数，类似于指针
    while(cin>>Full)//持续输入
    {
        int i;
        for(i=p;i<p+Full;i++)
            Map[i]=Key;//把这一块区域登记为Key，就是0或1
        p=i;
        Key=!Key;
        //本文唯一难点，
        /*
         *“!”表示相反，
         *如果原先为true就变为false
         *如果原先为false就变为true
         *这里就把“0和1的数量交替输入”体现出来了
         */
    }
    p=0;
    //指针归零，下面要开始从头开始输入
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Map[p];
            p++;
            //输出
        }
        cout<<endl;
        /*按格式输出*/
    }
        
}
