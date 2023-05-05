#include <bits/stdc++.h>
using namespace std;

vector<int> rest[8];
int ans = 0, placed[8];

void f(int r) {
    if (r == 8) { ans++; return; }
    for (int j = 0; j < 8; j++) {
        bool safe = true;
        for (int i : rest[r]) { if (j == i) safe = false; }
        for (int i = 0; i < r; i++) {
            if (j == placed[i] || abs(i - r) == abs(j - placed[i])) {
                safe = false;
            }
        }
        if (safe) {
            placed[r] = j;
            f(r + 1);
            placed[r] = -1;
        }
    }
}

int main() {
    string s;

    for (int i = 0; i < 8; i++) {
        placed[i] = -1;
    }

    for (int i = 0; i < 8; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '*') {
                rest[i].push_back(j);
            }
        }

    }
    
    f(0);
    cout << ans;
}