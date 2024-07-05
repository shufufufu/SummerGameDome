#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

int reverseNumber(int N) {
    string numStr = to_string(abs(N));
    reverse(numStr.begin(), numStr.end());
    int reversedNum = stoi(numStr);
    return N >= 0 ? reversedNum : -reversedNum;
}

int main() {
    int N;
    cin >> N;
    int result = reverseNumber(N);
    cout << result << endl;
    return 0;
}

