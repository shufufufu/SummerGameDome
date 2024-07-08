#include <bits/stdc++.h>
using namespace std;
const int Maxn = 31;
long long int n, m, c[Maxn], dp[30005];
int main(){
	cin >> m >> n;
	for(int i=1 ; i<=n ; i++){
		cin >> c[i];
	}		
	for(int i=1 ; i<=n ; i++){
		for(int j=m ; j>=c[i] ; j--){
			dp[j] = max( dp[j] ,dp[j-c[i]]+ c[i]);
            if(dp[j] == m)
            {
                cout<<0;
                return 0;
            }

		}
	}
	cout << m - dp[m];
	return 0;
}