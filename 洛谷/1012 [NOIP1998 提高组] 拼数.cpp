#include<bits/stdc++.h>  
using namespace std;  
  
bool compare(const string &a, const string &b) {  
    return a + b > b + a; // 自定义比较函数，判断a接b是否大于b接a  
}  
  
int main()  
{  
    int n;  
    cin >> n;  
  
    string a[n]; // 数组大小定义为n  
  
    for(int i = 0; i < n; i++) // 从0开始遍历  
    {  
        cin >> a[i];  
    }  
  
    sort(a, a + n, compare); // 使用自定义比较函数进行排序  
  
    for(int i = 0; i < n; i++) // 从0开始输出  
    {  
        cout << a[i];  
    }  
  
    return 0;  
}