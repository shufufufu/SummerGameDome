//////https://yiyan.baidu.com/share/OvWRfv0FQf

#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
#define MAX_WORDS 1000  
#define MAX_WORD_LEN 100  
#define MAX_LINE_LEN 1024  
  
typedef struct {  
    char word[MAX_WORD_LEN];  
    int count;  
} WordCount; //和struct WordCount 是一个效果 
  
int cmpfunc(const void *a, const void *b) {  
    WordCount *wordA = (WordCount *)a; //类型转换 
    WordCount *wordB = (WordCount *)b;  
    return strcmp(wordA->word, wordB->word);  
}//为qsort函数定义了一个迭代器（比较器  
  
int main() {  
    char line[MAX_LINE_LEN]; //存储输入单词串
    WordCount words[MAX_WORDS] = {0};// 定义出存储单词的结构体数组
    int wordCount = 0; //单词种类总数 
    char *word = NULL;  //单个单词
  
    // 读取一行文本  
    if (fgets(line, MAX_LINE_LEN, stdin) != NULL) {  
        // 去除可能的换行符  
        line[strcspn(line, "\n")] = 0;  
  
        // 使用strtok分割单词  
        word = strtok(line, " ,.!?;");  
        while (word != NULL && wordCount < MAX_WORDS) {  
            int found = 0;//标识  
            for (int i = 0; i < wordCount; ++i) {  
                if (strcmp(words[i].word, word) == 0) {//通过srtcmp比较字典序，返回值为0则相等  
                    words[i].count++;  
                    found = 1;  
                    break;  
                }  
            }  
            if (!found) { //如果以前没存过这个单词 
                strcpy(words[wordCount].word, word);//存入数组  
                words[wordCount].count = 1;//计数为1  
                wordCount++;//数组往下走一位  
            }  
            word = strtok(NULL, " ,.!?;");//从上一个NULL的位置往后找，截取出单词  
        }  
  
        // 按照字典顺序排序  
        qsort(words, wordCount, sizeof(WordCount), cmpfunc); //sizeof(WordCount)是表示结构体的大小，和sizeof(int)同质 
  
        // 打印结果  
        for (int i = 0; i < wordCount; ++i) {  
            printf("%s %d\n", words[i].word, words[i].count);  
        }  
    }  
  
    return 0;  
}