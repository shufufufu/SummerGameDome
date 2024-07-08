#include <iostream>
using namespace std;

int countDigitTwo(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 10 == 2) {
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    int L, R;
    cin >> L >> R;

    int total_count = 0;
    for (int i = L; i <= R; i++) {
        total_count += countDigitTwo(i);
    }

    cout << total_count << endl;

    return 0;
}

