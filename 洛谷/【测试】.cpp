#include<stdio.h>
#include<string>
#include <stdlib.h>  
#include<iostream>
using namespace std;

int main()
{
	int *p,a = 1,b = 2;
	cout<<p<<endl;
	p = &a;
	*p = b;
	cout<<a<<endl;
	
	
	
	return 0;
}