#include <bits/stdc++.h>
using namespace std;

vector<int> A;

bool f(int n) {
    string s = to_string(n);
    int ctr = 0;
    for (char c : s) {
        ctr += (c != '0');
    }
    return (ctr == 1);
}

int main() {
    A.resize(1000001);
    for (int i = 1; i < 1000001; i++) {
        A[i] = A[i - 1] + f(i);
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << A[n] << endl;
    }
}