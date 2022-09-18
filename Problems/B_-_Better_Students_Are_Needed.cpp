#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> A(n), B(n);
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n; i++) cin >> B[i];

    vector<bool> ok(n, 0);

    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++) {
        a[i].first = A[i];
        a[i].second = -i;
    } 

    sort(a.begin(), a.end());
    while(x--) {
        ok[-a.back().second] = true;
        a.pop_back();
    }

    a.clear();
    for(int i=0; i<n; i++) {
        if(ok[i]) continue;
        a.push_back({B[i], -i});
    }

    sort(a.begin(), a.end());
    while(y--) {
        ok[-a.back().second] = true;
        a.pop_back();
    }

    a.clear();
    for(int i=0; i<n; i++) {
        if(ok[i]) continue;
        a.push_back({A[i]+B[i], -i});
    }

    sort(a.begin(), a.end());
    while(z--) {
        ok[-a.back().second] = true;
        a.pop_back();
    }

    for(int i=0; i<n; i++) {
        if(ok[i]) cout<<i+1<<"\n";
    }
}