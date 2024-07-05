#include <iostream>  
#include <iomanip>  
#include <vector>  
  
using namespace std;  
  
void printSnakeMatrix(int n) {  
    // ��ʼ��һ��n*n�Ķ�ά��������Ԫ�س�ʼֵΪ0  
    vector<vector<int>> matrix(n, vector<int>(n, 0));  
      
    // num���ڼ�¼��ǰҪ��������֣���ʼΪ1  
    int num = 1;  
      
    // dx��dy��ʾ��ǰ�ƶ��ķ��򣬳�ʼ����Ϊ���£�0, 1��  
    int dx = 0, dy = 1;  
      
    // x��y��ʾ��ǰλ�ã���ʼλ��Ϊ(0, 0)  
    int x = 0, y = 0;  
      
    // dirs����洢���ĸ������ƫ����  
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  
      
    // dirIndex��ʾ��ǰ�������������ʼΪ0�������£�  
    int dirIndex = 0;  
      
    // ѭ��n*n�Σ���Ϊ������Ҫ���n*n������  
    for (int i = 0; i < n * n; ++i) {  
        // �ڵ�ǰλ��(x, y)��������num  
        matrix[x][y] = num++;  
          
        // ���԰��յ�ǰ�����ƶ�  
        int nx = x + dx, ny = y + dy;  
          
        // �����λ��(nx, ny)�Ƿ�Խ������Ѿ�������  
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {  
            // ���Խ�����䣬��ı䷽��  
            dirIndex = (dirIndex + 1) % 4; // ˳ʱ����ת�����·�������  
            dx = dirs[dirIndex][0]; // ����dx  
            dy = dirs[dirIndex][1]; // ����dy  
            nx = x + dx; // �����·��������λ��  
            ny = y + dy;  
        }  
          
        // ���µ�ǰλ��  
        x = nx;  
        y = ny;  
    }  
      
    // ��ӡ����ȷ��ÿ������ռ3���ַ���  
    for (const auto& row : matrix) {  
        for (int val : row) {  
            cout << setw(3) << val; // ʹ��setwȷ��ÿ������ռ3���ַ�  
        }  
        cout << endl; // ÿ�д�ӡ�����  
    }  
}  
  
int main() {  
    int n;  
    cin >> n; // �������Ĵ�Сn  
      
    // ��������Ƿ��ںϷ���Χ��  
    if (n < 1 || n > 9) {  
        cout << "Input should be between 1 and 9." << endl;  
        return 1; // ���벻�Ϸ����˳�����  
    }  
      
    printSnakeMatrix(n); // ���ú�����ӡ���η���  
    return 0;  
}
