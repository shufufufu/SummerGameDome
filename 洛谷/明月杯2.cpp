#include <iostream>  
#include <vector>  
#include <queue>  
  
using namespace std;  
  
typedef pair<int, int> PII;
  
int main() {  
    int n, m, x;  
    cin >> n >> m >> x;  
  
    priority_queue<PII> pq; 
    int total_brightness = 0; 
  
    
    for (int i = 0; i < m; ++i) {  
        int a, b;  
        cin >> a >> b;  
        pq.push({a, b}); 
        total_brightness += a * b;
    }  
  
    int shots = 0;
  
    
    while (total_brightness > x && !pq.empty()) {  
        PII top = pq.top(); 
        pq.pop();  
  
        
        if (top.second > 0) {  
            shots += 1; 
            total_brightness -= top.first;   
            top.second -= 1; 
  
            if (top.second > 0) {  
                pq.push(top); 
            }  
        }  
    }  
  
    cout << shots << endl; 
  
    return 0;  
}