#include <stdio.h>  
#include <stdlib.h>  
  
// 分配并初始化矩阵  
int** createMatrix(int m, int n) {  
    int** matrix = (int**)malloc(m * sizeof(int*));  
    for (int i = 0; i < m; i++) {  
        matrix[i] = (int*)malloc(n * sizeof(int));  
    }  
    return matrix;  
}  
  
// 释放矩阵内存  
void freeMatrix(int** matrix, int m) {  
    for (int i = 0; i < m; i++) {  
        free(matrix[i]);  
    }  
    free(matrix);  
}  
  
// 计算并打印矩阵的转置  
void transposeAndPrint(int** matrix, int m, int n) {  
    int** transposed = createMatrix(n, m);  
    for (int i = 0; i < m; i++) {  
        for (int j = 0; j < n; j++) {  
            transposed[j][i] = matrix[i][j];  
        }  
    }  
    printf("转置后的矩阵为:\n");  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {  
            printf("%d ", transposed[i][j]);  
        }  
        printf("\n");  
    }  
    freeMatrix(transposed, n);  
}  
  
int main() {  
    int m, n;  
    printf("请输入行数(m): ");  
    scanf("%d", &m);  
    printf("请输入列数(n): ");  
    scanf("%d", &n);  
  
    int** matrix = createMatrix(m, n);  
    printf("请输入矩阵:\n");  
    for (int i = 0; i < m; i++) {  
        for (int j = 0; j < n; j++) {  
            scanf("%d", &matrix[i][j]);  
        }  
    }   
  
    transposeAndPrint(matrix, m, n);  
  
    freeMatrix(matrix, m);  
    return 0;  
}