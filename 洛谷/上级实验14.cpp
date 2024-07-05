#include<stdio.h>
#include<string>
int ar[4]={0};
int minus(int n);
void cun(int n);
int max();
int min();
int main(){
	int n;
	int same=-1;
	scanf("%d",&n);
	while(same!=n){
		same=n;
		cun(n);
		n=minus(n);
	}

	
	printf("%d",same);
	
}
int minus(int n){
	return max()-min();
}
void cun(int n){
	int ll=0;
	while(n!=0){
		ar[ll]=n%10;
		n=n/10;
		ll++;
	}
}
int max(){
	int temp;
	for(int i=0;i<3;i++){
		for(int j=i;j<4;j++){
			if(ar[i]<ar[j]){
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
				
			}
		}
	}	
	return ar[0]*1000+ar[1]*100+ar[2]*10+ar[3];
}
int min(){
	
	return ar[3]*1000+ar[2]*100+ar[1]*10+ar[0];
}