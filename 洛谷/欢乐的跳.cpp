#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a[1000], e[1000];
    int k, b;

    cin >> k;

    for (int i = 0; i < k; ++i) {
        cin >> b;
        a[i] = b;
    }

    for (int i = 0; i < k - 1; ++i) {
        e[i] = abs(a[i + 1] - a[i]);
    }

    bool isJolly = true;

    for (int i = 0; i < k - 1; ++i) {
        for (int j = i + 1; j < k - 1; ++j) {
            if (e[i] == e[j]) {
                isJolly = false;
                break;
            }
        }
        if (!isJolly) {
            break;
        }
    }

    if (isJolly) {
        cout << "Jolly" << endl;
    } else {
        cout << "Not jolly" << endl;
    }

    return 0;
}

