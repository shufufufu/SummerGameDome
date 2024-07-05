#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int start = nums[0]; // 当前连号的起始值
    int currentLength = 1; // 当前连号的长度
    int maxLength = 1; // 最长连号的长度
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            // 当前数字与前一个数字连续，增加当前连号长度
            ++currentLength;
        } else {
            // 当前数字与前一个数字不连续，更新最长连号长度并重置当前连号信息
            maxLength = max(maxLength, currentLength);
            start = nums[i];
            currentLength = 1;
        }
    }
    
    // 检查最后一个连号，因为循环结束后不会再次更新最长连号长度
    maxLength = max(maxLength, currentLength);
    
    cout << maxLength << endl;
    return 0;
}
