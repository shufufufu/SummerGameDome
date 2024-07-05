#include<bits/stdc++.h>
using namespace std;

	int n,f[1000005][2];
	
int main()
{
	cin>>n;
	f[0][0]=f[1][0]=1;
for(int i=2;i<=n;++i)
{
    f[i][0]=(f[i-1][0]+f[i-1][1]+f[i-2][0])%10000;
    f[i][1]=(2*f[i-2][0]+f[i-1][1])%10000;
}
cout<<f[n][0]<<endl;
	
	
	return 0;
}