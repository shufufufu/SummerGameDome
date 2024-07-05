#include <iostream>  
#include <string>  
#include <vector>  
#include <algorithm>  
#include <iomanip>  
  
using namespace std;  
  
int main() {  
    string str;  
    vector<int> count(26, 0); // 初始化一个大小为26的数组来记录每个字母出现的次数  
  
    for (int i = 0; i < 4; ++i) {  
        string line;  
        getline(cin, line);  
        str += line;  
    }  
  
    // 统计每个字母出现的次数  
    for (char c : str) {  
        if (isupper(c)) {  
            count[c - 'A']++;  
        }  
    }  
  
    // 找到出现次数最多的字母  
    int maxCount = *max_element(count.begin(), count.end());  
  
    // 打印柱状图  
    for (int i = maxCount; i > 0; --i) {  
        for (int j = 0; j < 26; ++j) {  
            // 如果该字母的出现次数大于等于当前层数，则打印星号  
            if (count[j] >= i) {  
                cout << "* ";  
            } else {  
                cout << "  ";  
            }  
        }  
        cout << endl; // 每打印完一行，输出一个换行符  
    }  
  
    // 打印字母顺序  
    for (char c = 'A'; c <= 'Z'; ++c) {  
        cout << c<<" "; // 使用setw来设置输出宽度，保证字母间对齐  
    }  
    cout << endl; // 字母顺序打印完毕后输出一个换行符  
  
    return 0;  
}