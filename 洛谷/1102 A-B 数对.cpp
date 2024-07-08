#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 10;
int n , c;
int a[N];

int main () 
{
	cin >> n >> c;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	int l = 1, r1 = 1 , r2 = 1;
	ll ans = 0;
	for(l = 1 ; l <= n ; l ++) {
		while(r1 <= n && a[r1] - a[l] <= c) r1 ++;
		while(r2 <= n && a[r2] - a[l] < c ) r2 ++;
		if(a[r2] - a[l] == c && a[r1 - 1] - a[l] == c && r1 - 1 >= 1) 	
			ans += r1 - r2;
	}
	cout << ans;
	return 0;
}