#include <bits/stdc++.h>
using namespace std;
#define int long long
    int n;
    vector<string> A;
    vector<pair<int, int>> X;

bool cmp(pair<int, int> B, pair<int, int> C) {
    int b = 0, bb = 0;
    int ctr = 0;
    for(char c : A[B.second]) {
        if(c == 'X') continue;
        b += (c-'0')*(ctr + C.first);
    }

    ctr = 0;
    for(char c : A[C.second]) {
        if(c == 'X') continue;
        bb += (c - '0')*(ctr + B.first);
    }

    return bb > b;
}

signed main() {
    cin >> n;
    A.resize(n);
    X.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n; i++) {
        for(char c : A[i]) {
            X[i].first += (c == 'X');
            X[i].second = i;
        }
    }
    sort(X.begin(), X.end(), cmp);
    string S;
    for(int i=0; i<n; i++) {
        S += A[X[i].second];
    }

    // cerr<<S;

    int ctr = 0;
    int ans = 0;
    for(int i=0; i<(int)S.size(); i++) {
        if(S[i] == 'X') ctr++;
        else ans += (S[i]-'0')*ctr;
    }

    cout<<ans;

}