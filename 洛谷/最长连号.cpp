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
    
    int start = nums[0]; // ��ǰ���ŵ���ʼֵ
    int currentLength = 1; // ��ǰ���ŵĳ���
    int maxLength = 1; // ����ŵĳ���
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            // ��ǰ������ǰһ���������������ӵ�ǰ���ų���
            ++currentLength;
        } else {
            // ��ǰ������ǰһ�����ֲ���������������ų��Ȳ����õ�ǰ������Ϣ
            maxLength = max(maxLength, currentLength);
            start = nums[i];
            currentLength = 1;
        }
    }
    
    // ������һ�����ţ���Ϊѭ�������󲻻��ٴθ�������ų���
    maxLength = max(maxLength, currentLength);
    
    cout << maxLength << endl;
    return 0;
}
