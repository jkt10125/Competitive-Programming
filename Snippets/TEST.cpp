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
    // s.push_back('$');
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
        // vector<pair<pair<int, int>, int>> A(n);
        vector<array<int, 3>> A(n);
        for (int i = 0; i < n; i++) {
            // A[i] = {{eq_class[i], eq_class[(i + (1 << k)) % n]}, i};
            A[i] = {eq_class[i], eq_class[(i + (1 << k)) % n], i};
        }
        // sort (A.begin(), A.end());
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
    
    // s.pop_back();
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

    // index of all the matches is p[i] where i @[d, u]

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

// O(n logn)
// NOTE :: Empty substring is not counted here!
int countDistinctSubstring (string &s) {
    int n = s.size();
    vector<int> p = suffixArray(s);
    vector<int> lcp = LCP(s, p);
    int sum = accumulate(lcp.begin(), lcp.end(), 0ll);
    return n * (n + 1) / 2 - sum;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int a = suffixArray(s)[0];
    // cerr << s;
    for (int i = a; i < n; i++) cout << s[i];
    for (int i = 0; i < a; i++) cout << s[i];
}