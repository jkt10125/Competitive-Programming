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

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi = prefixFunction(s);
    vector<int> inc;
    int j = n;
    while(j > 0) {
        inc.push_back(j);
        j = pi[j - 1];
    }
    reverse(inc.begin(), inc.end());
    pi = prefixSubstringOccurence(s);
    cout << inc.size() << endl;
    for (int i : inc) {
        cout << i << ' ' << pi[i - 1];
        cout << endl;
    }

}