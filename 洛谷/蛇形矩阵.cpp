#include <iostream>  
#include <iomanip>  
#include <vector>  
  
using namespace std;  
  
void printSnakeMatrix(int n) {  
    // 初始化一个n*n的二维矩阵，所有元素初始值为0  
    vector<vector<int>> matrix(n, vector<int>(n, 0));  
      
    // num用于记录当前要填入的数字，初始为1  
    int num = 1;  
      
    // dx和dy表示当前移动的方向，初始方向为向下（0, 1）  
    int dx = 0, dy = 1;  
      
    // x和y表示当前位置，初始位置为(0, 0)  
    int x = 0, y = 0;  
      
    // dirs数组存储了四个方向的偏移量  
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  
      
    // dirIndex表示当前方向的索引，初始为0（即向下）  
    int dirIndex = 0;  
      
    // 循环n*n次，因为我们需要填充n*n个数字  
    for (int i = 0; i < n * n; ++i) {  
        // 在当前位置(x, y)填入数字num  
        matrix[x][y] = num++;  
          
        // 尝试按照当前方向移动  
        int nx = x + dx, ny = y + dy;  
          
        // 检查新位置(nx, ny)是否越界或者已经被填充过  
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {  
            // 如果越界或被填充，则改变方向  
            dirIndex = (dirIndex + 1) % 4; // 顺时针旋转，更新方向索引  
            dx = dirs[dirIndex][0]; // 更新dx  
            dy = dirs[dirIndex][1]; // 更新dy  
            nx = x + dx; // 根据新方向计算新位置  
            ny = y + dy;  
        }  
          
        // 更新当前位置  
        x = nx;  
        y = ny;  
    }  
      
    // 打印矩阵，确保每个数字占3个字符宽  
    for (const auto& row : matrix) {  
        for (int val : row) {  
            cout << setw(3) << val; // 使用setw确保每个数字占3个字符  
        }  
        cout << endl; // 每行打印完后换行  
    }  
}  
  
int main() {  
    int n;  
    cin >> n; // 输入矩阵的大小n  
      
    // 检查输入是否在合法范围内  
    if (n < 1 || n > 9) {  
        cout << "Input should be between 1 and 9." << endl;  
        return 1; // 输入不合法，退出程序  
    }  
      
    printSnakeMatrix(n); // 调用函数打印蛇形方阵  
    return 0;  
}
