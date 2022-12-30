/*
** Date: 29/12/2022 | Time: 02:46:17
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

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

long long suffixArray (string &s) {
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
        k = max(k - 1, 0ll);
    }
    
    // O(n)
    long long distinctSubstringCount = 0;
    for (int i = 0; i < n; i++) {
        distinctSubstringCount += (long long)(p[i] - lcp[i]);
    }

    s.pop_back();
    // p.erase(p.begin());
    return distinctSubstringCount;
}


signed main() {
    string s;
    cin >> s;
    
    cout << suffixArray(s);
}