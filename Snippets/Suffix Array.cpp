#include <bits/stdc++.h>
using namespace std;

vector<int> suffixArray (string &s) {
    s.push_back('$');
    int n = s.size();
    vector<int> eq_class(n), p(n);
    {
        vector<pair<char, int>> A(n);
        for (int i = 0; i < n; i++) A[i] = {s[i], i};
        sort (A.begin(), A.end());
        for (int i = 0; i < n; i++) p[i] = A[i].second;
        eq_class[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            eq_class[p[i]] = eq_class[p[i - 1]];
            if (A[i].first != A[i - 1].first) {
                eq_class[p[i]]++;
            }
        }
    }

    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> A(n);
        for (int i = 0; i < n; i++) {
            A[i] = {{eq_class[i], eq_class[(i + (1 << k)) % n]}, i};
        }
        sort (A.begin(), A.end());
        for (int i = 0; i < n; i++) p[i] = A[i].second;
        eq_class[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            eq_class[p[i]] = eq_class[p[i - 1]];
            if (A[i].first != A[i - 1].first) {
                eq_class[p[i]]++;
            }
        }
        k++;
    }
    
    s.pop_back();
    p.erase(p.begin());
    return p;
}

int substringSearch (string &w, string &s, vector<int> &p) {
    int n = s.size();
    int match;
    int d, u, l, r;
    l = 0, r = n - 1;
    d = n;

    while (l <= r) {
        int m = ((l + r) >> 1);
        string str = s.substr(p[m], w.size());
        if (str < w) {
            l = m + 1;
        }
        else {
            if (str == w) d = m;
            r = m - 1;
        }
    }

    l = 0, r = n - 1;
    u = d - 1;

    while (l <= r) {
        int m = ((l + r) >> 1);
        string str = s.substr(p[m], w.size());
        if (str > w) {
            r = m - 1;
        }
        else {
            if (str == w) u = m;
            l = m + 1;
        }
    }

    return u - d + 1;
}

vector<int> LCP (string &s, vector<int> &p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        rank[p[i]] = i;
    }

    int k = 0;
    vector<int> lcp(n - 1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        const int j = p[rank[i] + 1];
        while (i + k < n && j + k < n) {
            if (s[i + k] != s[j + k]) break;
            k++;
        }
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}

int main() {
    string s;
    cin >> s;
    // s.push_back('@');
    auto sa = suffixArray(s);
    // for (int i : sa) cout << i << ' ';
    string t;
    cin >> t;
    cout << substringSearch(t, s, sa);

}