#include <bits/stdc++.h>
using namespace std;
int n,a[110],sum,cnt;
int main(){
	cin >> n;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
		sum += a[i]; 
	}
	sum /= n;
	for(int i=1 ; i<n ; i++){
		if(a[i] != sum){//至于为什么一个if就可以涵盖全部情况，因为有负数的存在
			a[i+1] -= sum - a[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
