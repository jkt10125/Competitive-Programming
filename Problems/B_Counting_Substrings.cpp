#include <bits/stdc++.h>
using namespace std;

int suffix_array(string s) {
    s.push_back('$');
    int n = s.size();
    vector<int> eq_class(n), p(n);
    {
        vector<pair<char, int>> A(n);
        for(int i=0; i<n; i++) A[i] = {s[i], i};
        sort(A.begin(), A.end());
        for(int i=0; i<n; i++) p[i] = A[i].second;
        eq_class[p[0]] = 0;
        for(int i=1; i<n; i++) {
            eq_class[p[i]] = eq_class[p[i-1]];
            if(A[i].first != A[i-1].first) eq_class[p[i]]++;
        }
    }

    int k = 0;
    while((1 << k) < n) {
        vector<pair<pair<int, int>, int>> A(n);
        for(int i=0; i<n; i++) {
            A[i] = {{eq_class[i], eq_class[(i + (1 << k)) % n]}, i};
        }
        sort(A.begin(), A.end());
        for(int i=0; i<n; i++) p[i] = A[i].second;
        eq_class[p[0]] = 0;
        for(int i=1; i<n; i++) {
            eq_class[p[i]] = eq_class[p[i-1]];
            if(A[i].first != A[i-1].first) eq_class[p[i]]++;
        }
        k++;
    }

    k = 0;
    vector<int> lcp(n);
    for(int i=0; i<n-1; i++) {
        int pi = eq_class[i];
        int j = p[pi-1];
        while (s[i + k] == s[p[eq_class[i] - 1] + k]) k++;
        lcp[eq_class[i]] = k;
        k = max(k-1, 0);
    }
    
    long long ans = 0;
    for(int i=0; i<n; i++) ans += (long long)(p[i] - lcp[i]);

    s.pop_back();
    return ans;
}

template <typename T>
T input() { T a; cin >> a; return a; }

int main() {
    string s = input<string>();
    cout << suffix_array(s) << endl;   
}