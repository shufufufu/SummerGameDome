#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int a = 0, b = 0, c = 0,d = 0;
	long long int max = 0,min = 0;
	cin>>a>>b>>c;
	if (a > b) swap(a, b);  
    if (b > c) swap(b, c);  
    if (a > b) swap(a, b); 
	
	if(a + b <= c){
	cout<<"Not triangle" <<endl;
	return 0;}
	if(a*a + b*b == c*c)cout<<"Right triangle"<<endl;
	if(a*a + b*b > c*c)cout<<"Acute triangle"<<endl;
	if(a*a + b*b < c*c)cout<<"Obtuse triangle"<<endl;
	if(a == b||b == c)cout<<"Isosceles triangle"<<endl;
	if(a == b&&b == c)cout<<"Equilateral triangle"<<endl;


}
