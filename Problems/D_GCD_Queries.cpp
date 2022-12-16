#include <bits/stdc++.h>
using namespace std;
int x;
int ask (int i, int j) {
    cout << "? " << i << " " << j << endl;
    cin >> x;
    return x;
}

int print (int i, int j) {
    cout << "! " << i << " " << j << endl;
    cin >> x;
    return x;
}

int main() {
    int t, v = 1;
    cin >> t;
    while (t-- && v == 1) {
        int n;
        cin >> n;
        int x = 1, y = 2;
        for (int i = 3; i <= n; i++) {
            int a = ask(x, y);
            int b = ask(x, i);
            if (a == b) x = i;
            else if (a < b) y = i;
        }
        v = print(x, y);
    }
}