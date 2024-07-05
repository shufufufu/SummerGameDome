#include <bits/stdc++.h>
using namespace std;
struct bag{
	int tot;
	int w[1010] ,v[1010];
}a[1010];
int dp[1010];

int main(){
	int n, m, N = 0;
	cin >> m >> n;
	for(int i=1 ; i<=n ; i++){
		int x, y, z;		
		cin >> x >> y >> z;
		N = max(N,z);
		a[z].tot++;
		a[z].w[a[z].tot] = x;
		a[z].v[a[z].tot] = y;		
	}
	for(int i=1 ; i<=N ; i++){
		for(int j=m ; j>=0 ; j--){
			for ( int k=1 ; k<=a[i].tot ; k++){
				if(j-a[i].w[k] >=0)
					dp[j] = max( dp[j] , dp[j-a[i].w[k]] + a[i].v[k] );
			}
		}
	}
	cout << dp[m];
	return 0;
}