#include<iostream>
using namespace std;

int main(){
	
	int k=0,sub1,sub2,sub3,a=0;
	
	cin>>k;
	
	for(int i=10000;i<=30000;i++){
		
		sub1=i/100;
		sub2=((i%1000)/10)+((i/1000)%10)*100;
		sub3=i%1000;
		
		if(sub1%k==0&&sub2%k==0&&sub3%k==0){
			
			a++;
			
			cout<<i<<endl;
			
			}
			
		}
		
		if(a==0){
			
			cout<<"No"<<endl;
		
	    }
}
 
