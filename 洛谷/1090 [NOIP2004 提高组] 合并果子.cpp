//#include<bits/stdc++.h>
//using namespace std;
//int n,a[10010],p = 1,s;
//int main()
//{
//	cin>>n;
//	for(int i = 1; i <=n ; i++)
//	{
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
//	for(int i=1 ; i < n; i++)
//	{
//		a[p+1] += a[p];
//		s+=a[p+1];
//		p++;
//		sort(a+p,a+n+1); 
//	}
//	cout<<s; 
//	return 0;	
//}
#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n,a,p=1,s;
int main(){
	cin >> n;
	priority_queue<int,vector<int> ,greater<int> >q;
	for(int i=1 ; i<=n ; i++){
		cin >> a;
		q.push(a);
	}
	for(int i=1 ; i<n ; i++){
		a = q.top();
		q.pop();
		a += q.top();
		q.pop();
		s += a; 
		q.push(a);
	}
	cout << s;
	return 0;
}

