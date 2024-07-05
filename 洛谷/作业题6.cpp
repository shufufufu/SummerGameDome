#include <stdio.h>  
#include <string.h>  
  
void remove(char *str, char *sub);
  
int main() {  
    char str[10010];  
    char sub[10010];
	scanf("%s%s",&str,&sub);  
    remove(str, sub);  
    printf("After removing substring: %s\n", str);  
    return 0;  
}

void remove(char *str, char *sub) {  
    char *pos = str;  
    int subLen = strlen(sub);  
    while ((pos = strstr(pos, sub)) != NULL) {  
        memmove(pos, pos + subLen, strlen(pos + subLen) + 1);//由于strlen计算长度并不算入\0，
		//需要末尾加1把\0一同复制
    }  
} 