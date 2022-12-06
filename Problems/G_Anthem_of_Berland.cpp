#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction (string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0) {
            if (s[i] == s[j]) break;
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// O(26n)
vector<vector<int>> automationFunction (string &s) {
    s.push_back('$');
    int n = s.size();
    vector<int> pi = prefixFunction(s);
    vector<vector<int>> A(n, vector<int> (26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i]) {
                A[i][c] = A[pi[i-1]][c];
            }
            else {
                A[i][c] = i + ('a' + c == s[i]);
            }
        }
    }
    s.pop_back();
    return A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    auto A = automationFunction(t);
    int ctr = 0;
    int state = 0;
    for (char &c : s) {
        if (c == '?') {
            char best_choice = 'a';
            for (int i = 0; i < 26; i++) {
                if (A[state][i] > A[state][best_choice - 'a']) {
                    best_choice = i + 'a';
                }
            }
            c = best_choice;
        }
        state = A[state][c - 'a'];
        ctr += (state == t.size());
    }
    cerr << s;
    cout << ctr;
}