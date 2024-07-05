#include <iostream>  
#include <string>  
#include <vector>  
  
using namespace std;  
  
int main() {  
    string s;  
    cin >> s;  
    int n = s.size();  
      
 
    vector<vector<int>> prefixSum(n + 1, vector<int>(26, 0));  
    for (int i = 1; i <= n; i++) {  
        prefixSum[i] = prefixSum[i - 1];  
        prefixSum[i][s[i - 1] - 'a']++;  
    }  
      
    long long ans = 0;   
    for (int i = 1; i <= n; i++) {  
        for (int j = i; j <= n; j++) {  
            int maxCount = 0;  
            for (int k = 0; k < 26; k++) {  
                int count = prefixSum[j][k] - prefixSum[i - 1][k];  
                maxCount = max(maxCount, count);  
            }  
            if (maxCount <= (j - i + 1) / 2) {  
                ans++;  
            }  
        }  
    }  
      
    cout << ans << endl;  
    return 0;  
}