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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        auto A = substringSearch(t, s);
        if (A.empty()) cout << "Not Found\n";
        else {
            cout << A.size() << endl;
            for (int i : A) cout << i + 1 << ' ';
            cout << endl;
        }
        cout << endl;
    }
}