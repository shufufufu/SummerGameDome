#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main(){
	
	int n=0;
	cin>>n;
	
	for(int i=2;i<=n;i+=2){
		
		for(int b=0;b<=(i/2);b++){
			
			if(is_prime(b)==true){
				
				int c=i-b;
				
				if(is_prime(c)==true){
					
					cout<<i<<"="<<b<<"+"<<c<<endl;
					break;
				}
				
			}
			
		}
		
	}
	
}
