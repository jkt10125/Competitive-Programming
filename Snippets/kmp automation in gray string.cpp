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
vector<vector<int>> automationFunction (string &s, int k) {
    s.push_back('$');
    int n = s.size();
    vector<int> pi = prefixFunction(s);
    vector<vector<int>> A(n, vector<int> (k + 1));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < k; c++) {
            if (i > 0 && 'a' + c != s[i]) {
                A[i][c + 1] = A[pi[i-1]][c + 1];
            }
            else {
                A[i][c + 1] = i + ('a' + c == s[i]);
            }
        }
    }
    s.pop_back();
    return A;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    auto A = automationFunction(s, k);
    for (int i = 0; i <= s.size(); i++) {
        cerr << A[i][0] << ' ';
        cerr << A[i][1] << ' ';
        cerr << A[i][2] << '\n';
    }

    vector<vector<int>> G(k + 1, vector<int> (n + 1));
    vector<vector<int>> K(k + 1, vector<int> (n + 1));

    for (int j = 0; j <= n; j++) G[0][j] = j;
    for (int j = 0; j <= n; j++) K[0][j] = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            int mid = A[G[i - 1][j]][i];
            G[i][j] = G[i - 1][mid];
            K[i][j] = K[i - 1][j] + (mid == s.size()) + K[i - 1][mid];
        }
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            cout << G[i][j] << ' ';
        }
        cout << endl;
    } 
    cout << "\n\n\n";
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            cout << K[i][j] << ' ';
        }
        cout << endl;
    }
}