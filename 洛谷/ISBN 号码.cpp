#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int a[20];
	int b = 0;
	a[0] = str[0] - '0';
	a[1] = str[2] - '0';
	a[2] = str[3] - '0';
	a[3] = str[4] - '0';
	a[4] = str[6] - '0';
	a[5] = str[7] - '0';
	a[6] = str[8] - '0';
	a[7] = str[9] - '0';
	a[8] = str[10] - '0';
	b = a[0] + 2*a[1] + 3*a[2] + 4*a[3] + 5*a[4] + 6*a[5] + 7*a[6] + 8*a[7] + 9*a[8];

	if(b%11 - 10 == str[12] - 'X')
	{
		cout<<"Right";
		return 0;
	}
	
	if(b%11 == str[12] - '0')
	{
		cout<<"Right";
	}
	else  
{  
    b = b % 11;  
    if (b == 10) {  
        str[12] = 'X';  // 如果余数是10，则校验位是'X'  
    } else {  
        str[12] = '0' + b;  // 否则，将余数转换为字符  
    }  
    cout << str;  
}

}
