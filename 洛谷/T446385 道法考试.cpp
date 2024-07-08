#include <iostream>  
#include <vector>  
#include <unordered_set>  
  
using namespace std;  
  
int main() {  
    int n, m;  
    cin >> n >> m;  
  
    vector<unordered_set<int>> standardAnswers(n); // 存储每道题目的标准答案  
    vector<vector<int>> yourAnswers(n);             // 存储我的作答  
  
    // 读取标准答案  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < m; ++j) {  
            int answer;  
            cin >> answer;  
            standardAnswers[i].insert(answer);  
        }  
    }  
  
    // 读取我的作答  
    for (int i = 0; i < n; ++i) {  
        int l_i;  
        cin >> l_i;  
        yourAnswers[i].resize(l_i);  
        for (int j = 0; j < l_i; ++j) {  
            cin >> yourAnswers[i][j];  
        }  
    }  
  
    int score = 0;  
    // 遍历每一道题计算得分  
    for (int i = 0; i < n; ++i) {  
        unordered_set<int> yourSet(yourAnswers[i].begin(), yourAnswers[i].end());  
        bool containsAll = true;  
        // 检查我的作答是否包含标准答案的所有知识点  
        for (int answer : standardAnswers[i]) {  
            if (yourSet.find(answer) == yourSet.end()) {  
                containsAll = false;  
                break;  
            }  
        }  
        if (containsAll) {  
            score += 2;  
        }  
    }  
    
    cout << score << endl;  
  
    return 0;  
}