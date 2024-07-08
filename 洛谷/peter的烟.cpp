#include<iostream>
using namespace std;

int main(){
	
	int n=0,k=0,a=0,b=0;
	
	cin>>n>>k;
	
	a=n/k;
	b=a+n%k;
	n=n+a;
	while(b>=k){
		
		n=n+b/k;
		
		b=b/k+b%k;
		
		
	}
	
	cout<<n<<endl;
	
}
