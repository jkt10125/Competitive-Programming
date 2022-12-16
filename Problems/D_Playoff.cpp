#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int o = 0;
    for (char c : s) {
        o += (c - '0');
    }

    int z = n - o;
    vector<int> A((1 << n) + 1, 1);
    for (int i = 1; i < (1 << o); i++) {
        A[i] = false;
    }

    int ctr = (1 << z) - 1;
    int idx = (1 << n);
    while (ctr > 0) {
        A[idx] = false;
        idx--;
        ctr--;
    }

    for (int i = 0; i < (1 << n); i++) {
        if (A[i + 1]) {
            cout << i + 1 << ' ';
        }
    }
}