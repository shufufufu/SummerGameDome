#include <iostream>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
int main() {  
    int n;  
    cin >> n;  
      
    vector<long long> apples(n); 
    for (int i = 0; i < n; ++i) {  
        cin >> apples[i];  
    }  
      
    auto max_nutrient = max_element(apples.begin(), apples.end());  
    auto min_nutrient = min_element(apples.begin(), apples.end());  
      
    cout << *max_nutrient + *min_nutrient << endl;  
      
    return 0;  
}