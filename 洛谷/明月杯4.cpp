#include <iostream>  
#include <vector>  
using namespace std;  
  
typedef long long ll;  
const int MOD = 1e9 + 7;  
  
struct Matrix {  
    ll m[2][2];  
    Matrix() { memset(m, 0, sizeof(m)); }  
    Matrix operator*(const Matrix& b) const {  
        Matrix res;  
        for (int i = 0; i < 2; ++i) {  
            for (int j = 0; j < 2; ++j) {  
                for (int k = 0; k < 2; ++k) {  
                    res.m[i][j] = (res.m[i][j] + m[i][k] * b.m[k][j]) % MOD;  
                }  
            }  
        }  
        return res;  
    }  
};  
  
Matrix matrix_pow(Matrix base, ll n) {  
    Matrix res;  
    res.m[0][0] = res.m[1][1] = 1;  
    while (n > 0) {  
        if (n & 1) res = res * base;  
        base = base * base;  
        n >>= 1;  
    }  
    return res;  
}  
  
int main() {  
    int n, q;  
    cin >> n >> q;  
      
    vector<ll> results; 
      
    while (q--) {  
        int l, r;  
        cin >> l >> r;  
          
        Matrix base;  
        base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;  
        base.m[1][1] = 0;  
          
        Matrix res = matrix_pow(base, r - l + 1);  
        results.push_back((res.m[0][0] + res.m[0][1]) % MOD);
    }  
      
    
    for (auto result : results) {  
        cout << result << endl;  
    }  
      
    return 0;  
}