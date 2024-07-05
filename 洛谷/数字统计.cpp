#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a=0,b=0,n=0;
    
    cin>>a>>b;
    
    for(int i=a;i<=b;i++){
        
        if(i/10000==2) n++;
        if((i%10000)/1000==2) n++;
        if((i%1000)/100==2) n++;
        if((i%100)/10==2) n++;
        if(i%10==2) n++;
            
    }
    
    cout<<n<<endl;

    return 0;
}

