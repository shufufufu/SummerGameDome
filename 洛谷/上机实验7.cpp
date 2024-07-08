#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *Replace(char *str, char *substr, char * newstr);


int main()
{
	char str[100],sub[100],news[100];
	char *result;
	printf("请输入原字符串：\n");
	scanf("%s",str);
	printf("请输入要替换的字串：\n");
	scanf("%s",sub);
	printf("请输入要替换成的字串：\n");
	scanf("%s",news);
	result = Replace(str,sub,news);
	
	    if (result) {  
        printf("替换后的字符串是: %s\n", result);  
        free(result); 
    	} 
	
	return 0; 
		
}


char* Replace(char *str, char *substr, char *newstr) {  
    char *result;  
    int i, count = 0;  
    int newstr_len = strlen(newstr);  
    int substr_len = strlen(substr);  
  
    // 计算子串在原字符串中出现的次数  
    for (i = 0; str[i] != '\0'; i++) {  
        if (strstr(&str[i], substr) == &str[i]) {  
            count++;  
  
            // 跳过已经匹配的子串  
            i += substr_len - 1;  
        }  
    }  
  
    // 分配足够大的内存来存储结果字符串  
    result = (char *)malloc(i - count * (substr_len - newstr_len) + 1 + count * newstr_len);  
    if (!result) {  
        return NULL; // 内存分配失败  
    }  
  
    // 复制字符串直到找到子串  
    i = 0;  
    while (*str) {  
        char *p = strstr(str, substr);  
        if (p) {  
            // 将从str到p的字符复制到result  
            strncpy(&result[i], str, p - str);  
            i += p - str;  
  
            // 添加新字符串  
            strcpy(&result[i], newstr);  
            i += newstr_len;  
  
            // 移动到子串后的第一个字符  
            str = p + substr_len;  
        } else {  
            // 复制剩余的字符串  
            strcpy(&result[i], str);  
            break;  
        }  
    }  
  
    // 确保字符串以null终止  
    result[i] = '\0';  
  
    return result;  
}