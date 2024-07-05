#include <iostream> //cin & cout 用iostream
#include <cstring> //memset & strlen 用cstring
#include <cstdio> //sscanf & sprintf 用cstdio
using namespace std;
int main(){
	char a;//a用于存储运算符
	int n,c,d;//n存储个数不解释，cd存储两个数字
	char s[100],b[10];//s存储最终的字符串，b临时变量
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b;//输入一串字符，有可能是运算符，也有可能是数字
		if(b[0]>='a' && b[0]<='z'){
			a=b[0];//如果是运算符就存入a，然后输入数字
			cin>>c>>d;
		}else{
			sscanf(b,"%d",&c);//如果是数字就转换b为int存储到第一个数字
			cin>>d;//然后输入剩下的第二个数字
		}
		memset(s,0,sizeof(s));//清空原有的字符串，防止长度判断错误
		if(a=='a')//用sprintf格式化
			sprintf(s,"%d+%d=%d",c,d,c+d);
		else if(a=='b')
			sprintf(s,"%d-%d=%d",c,d,c-d);
		else if(a=='c')
			sprintf(s,"%d*%d=%d",c,d,c*d);
		cout<<s<<endl<<strlen(s)<<endl;//输出字符串和字符串长度
	}
	return 0;
}
