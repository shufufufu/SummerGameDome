#include <iostream>  
#include <vector>  
  
using namespace std;  
  
int main() {  
    int n,money = 0,cnt = 0; 
	int day[100000] ;
    cin >> n;  
  	
  	for(int i = 1;i <= n;i++)
	  {
	  	cin>>day[i];
	  }
	for(int i = 1;i <= n ;i++)
	{
		money += day[i] - day[i-1];
		if(money >= 50)money = 50;
		cnt += money/8;
		money = money%8;
	}
	
	 cout<<cnt; 
	  
    
    return 0;  
}