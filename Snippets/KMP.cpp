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

vector<int> substringSearch (string &w, string &s) {
    string res = w + "$" + s;
    vector<int> pi = prefixFunction(res);
    vector<int> match;
    for (int i = w.size() + 1; i < res.size(); i++) {
        if (pi[i] == w.size()) {
            match.push_back(i - (pi[i] << 1));
        }
    }
    return match;
}

vector<int> prefixSubstringOccurence (string &s) {
    int n = s.size();
    vector<int> ans(n + 1);
    vector<int> pi = prefixFunction(s);
    
    for (int i = 0; i < n; i++) {
        ans[pi[i]]++;
    }
    
    for (int i = n; i > 0; i--) {
        ans[pi[i-1]] += ans[i];
    }
    
    for (int i = 0; i <= n; i++) {
        ans[i]++;
    }

    return vector<int> (&ans[1], &ans[n + 1]);
}

vector<int> prefixSubstringOccurence (string &w, string &s) {
    string str = w + "$" + s;
    vector<int> pi1 = prefixSubstringOccurence(str);
    vector<int> pi2 = prefixSubstringOccurence(w);
    vector<int> res(w.size());
    for (int i = 0; i < (int)res.size(); i++) {
        res[i] = pi1[i] - pi2[i];
    }
    return res;
}

// O(26n)
// NOTE :: 0-based indexing is followed in the DFA
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

// smallest string a whose several times concatenation produces s
// |a| = compression Length
int compressionLength (string &s) {
    int n = s.size();
    vector<int> pi = prefixFunction(s);
    int k = n - pi[n - 1];
    if (n % k) return n;
    else return k;
}

int main() {
    string s, t;
    cin >> s;
    auto A = automationFunction(s);
    for (int i = 0; i <= s.size(); i++) {
        cout << A[i][0] << ' ';
        cout << A[i][1] << ' ';
        cout << A[i][2] << '\n';
    }
}