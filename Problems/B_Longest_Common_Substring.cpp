#include <bits/stdc++.h>
using namespace std;

string suffix_array(string &s, const int l) {
    s.push_back('$');
    int n = s.size();
    vector<int> p(n), c(n);

    {
        vector<pair<char, int>> A(n);
        for(int i=0; i<n; i++) A[i] = {s[i], i};
        sort(A.begin(), A.end());
        for(int i=0; i<n; i++) p[i] = A[i].second;
        c[p[0]] = 0;
        for(int i=1; i<n; i++) {
            c[p[i]] = c[p[i-1]];
            if(A[i].first != A[i-1].first) c[p[i]]++;
        }
    }

    int k=0; 
    while((1 << k) < n) {
        vector<pair<pair<int, int>, int>> A(n);
        for(int i=0; i<n; i++) {
            A[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(A.begin(), A.end());
        for(int i=0; i<n; i++) p[i] = A[i].second;
        c[p[0]] = 0;
        for(int i=1; i<n; i++) {
            c[p[i]] = c[p[i-1]];
            if(A[i].first != A[i-1].first) c[p[i]]++;
        }
        k++;
    }

    k = 0;
    vector<int> lcp(n);
    for(int i=0; i<n-1; i++) {
        int pi = c[i];
        int j = p[pi-1];
        while (s[i + k] == s[p[c[i] - 1] + k]) k++;
        lcp[c[i]] = k;
        k = max(k-1, 0);
    }

    // for(int i=0; i<n; i++) {
    //     cout << lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i])<<endl;
    // }

    string ans; int cnt = 0;
    for(int i=3; i<n; i++) {
        if((p[i] < l && p[i-1] > l) || (p[i] > l && p[i-1] < l))
        if(lcp[i] > cnt) {
            if(s[p[i]+lcp[i]-1] == '$') {
                ans = s.substr(p[i], lcp[i]-1);
                cnt = lcp[i]-1;
            } else {
                ans = s.substr(p[i], lcp[i]);
                cnt = lcp[i];
            }
        }
    }
    return ans;
}

template <typename T>
T input() { T a; cin >> a; return a; }

int main() {
    string s = input<string>();
    s.push_back('$');
    string t = input<string>();
    string r = s + t;
    string A = suffix_array(r, s.size()-1);
    cout << A;
}