/*
** Date: 29/12/2022 | Time: 02:57:14
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

// O(n * m)
// NOTE: Below sort function works only when the numbers are from [0, n - 1]
template <typename T, size_t m>
void countSort (vector<array<T, m>> &A) {
    int n = A.size();
    for (int j = m - 1; j >= 0; j--) {
        vector<int> H(n);
        for (int i = 0; i < n; i++) {
            H[A[i][j]]++;
        }
        for (int i = 1; i < n; i++) {
            H[i] += H[i - 1];
        }
        H.pop_back();
        H.emplace (H.begin(), 0);
        vector<array<T, m>> B(n);
        for (int i = 0; i < n; i++) {
            B[H[A[i][j]]++] = A[i];
        }
        A.swap(B);
    } 
}

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
        vector<array<int, 3>> A(n);
        for (int i = 0; i < n; i++) {
            A[i] = {eq_class[i], eq_class[(i + (1 << k)) % n], i};
        }
        countSort(A);
        for (int i = 0; i < n; i++) p[i] = A[i][2];
        eq_class[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            eq_class[p[i]] = eq_class[p[i - 1]];
            if (A[i][0] != A[i - 1][0] || A[i][1] != A[i - 1][1]) {
                eq_class[p[i]]++;
            }
        }
        k++;
    }

    k = 0;
    vector<int> lcp(n);
    for (int i = 0; i < n - 1; i++) {
        int pi = eq_class[i];
        int j = p[pi - 1];
        while (s[i + k] == s[p[eq_class[i] - 1] + k]) {
            k++;
        }
        lcp[eq_class[i]] = k;
        k = max(k - 1, 0);
    }
    
    // O(n)
    long long distinctSubstringCount = 0;
    for (int i = 0; i < n; i++) {
        distinctSubstringCount += (long long)(p[i] - lcp[i]);
    }

    s.pop_back();
    // p.erase(p.begin());
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

    if (d > u) return -2;

    // index of all the matches is p[i] where i @[d, u]

    return *min_element(p.begin() + d, p.begin() + u + 1);
}

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;
    auto p = suffixArray(s);
    while (q--) {
        string t;
        cin >> t;
        cout << substringSearch(t, s, p) + 1 << endl;
    }
}