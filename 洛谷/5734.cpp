#include<bits/stdc++.h>  
using namespace std;  
  
int main()  
{  
    int n = 0, x = 0, a = 0, b = 0;  
    string str, str1;  
    cin >> n;  
    cin >> str;  
    for (int i = 0; i < n; i++)  
    {  
        cin >> x;  
        if (x == 1)  
        {  
            cin >> str1;  
            str += str1;  
            cout << str << endl;  
        }  
        else if (x == 2)  
        {  
            cin >> a >> b;  
            str1 = str.substr(a - 1, b); // 使用substr函数来截取字符串  
            str = str1;  
            cout << str << endl;  
        }  
        else if (x == 3)  
        {  
            cin >> a >> str1;  
            str.insert(a - 1, str1); // 在指定位置插入字符串  
            cout << str << endl;  
        }  
        else if (x == 4)  
        {  
            cin >> str1;  
            size_t pos = str.find(str1); // 查找子串的位置  
            if (pos != string::npos)  
            {  
                cout << pos + 1 << endl; // 输出位置（题目要求从第0个位置开始计数，但输出时从第1个位置开始）  
            }  
            else  
            {  
                cout << -1 << endl; // 子串未找到  
            }  
        }  
        else  
        {  
            cout << "Invalid operation" << endl;  
            return 1;  
        }  
    }  
    return 0;  
}