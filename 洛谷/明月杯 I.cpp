#include <iostream>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
int minNumbersToCover(const vector<int>& a, int n) {  
    int count = 0; 
    int endPos = 0; 
  
    for (int i = 0; i < n; ++i) {  
       
        if (i > endPos) {  
          
            int maxCover = i;  
            for (int j = i; j < n && j <= i + a[i] - 1; ++j) {  
                maxCover = max(maxCover, j + a[j] - 1);  
            }  
          
            endPos = maxCover;  
            count++; 
        }  
    }  
  
    return count;  
}  
  
int main() {  
    int n;  
    cin >> n;  
    vector<int> a(n);  
    for (int i = 0; i < n; i++) {  
        cin >> a[i];  
    }  
  
    int result = minNumbersToCover(a, n);  
    cout << result << endl;  
  
    return 0;  
}