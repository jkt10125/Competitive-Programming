#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // sliding window max
    deque<int> dq;
    for(int i=0; i<n; i++) {
        while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= n-1) cout << a[dq.front()] << endl;
    }
}