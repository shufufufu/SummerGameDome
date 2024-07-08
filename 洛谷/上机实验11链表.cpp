#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
		char ar[100];
		int time;
		struct Node *next;
};
typedef struct Node* ListNode; 
void function(ListNode *s1,char *sub);
int main(){
	int i=0;
	int sum=0;
	int j=0;
	char s[200];
	ListNode prehead=(ListNode)malloc(sizeof(Node));
	prehead->next=NULL;
	ListNode head=prehead;
	gets(s);
	while(s[i]!='\0'){
		j=0;
		char *sub=(char *)malloc(sizeof(char)*100);
		while(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')){
			sub[j]=s[i];
			j++;
			i++;
		}
//		if(j>0){
			sub[j]='\0';
			function(&prehead,sub);	
//		}
		if(s[i]=='\0'){
			break;
		}
		i++;	
		free(sub);
	}
	while(head->next!= NULL){  
        printf("%s: %d\n", head->next->ar, head->next->time);  
        head=head->next;
   	}  
}
void function(ListNode *s1,char *sub){
	ListNode ss=*s1;
	while(ss->next!=NULL&&strcmp(ss->next->ar,sub)<=0){
		if(strcmp(ss->next->ar,sub)==0){
			ss->next->time++;
			return;
		}	
		ss=ss->next;
	}	
	ListNode s2=(ListNode)malloc(sizeof(Node));	
	strcpy(s2->ar,sub);
	s2->time=1;
	s2->next=NULL;
	s2->next=ss->next;
	ss->next=s2;
}