#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n=0,a=0;
	int high[10000];
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		
		cin>>a;
		high[i]=a;
		
	}
	
	
	
	int b=0,c=0,d=0,m=0;
	
	for(int i=0;i<n-1;i++){
		
	c=high[i];
	b=high[i+1];
	d=high[i+2];
	if((b>c&&b>d)||(b>c&&b==d)){    
		
		m++;
		
	    }
	
	
		
	}
	
	cout<<m-1<<endl;
	
	
}

