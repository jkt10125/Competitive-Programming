/*
** Date: 28/12/2022 | Time: 13:50:11
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    multiset<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }

    int time = 0;
    int rem_mem = m;
    while (A.size() != 0) {
        auto it = A.upper_bound(rem_mem);
        if (it == A.begin()) {
            time++;
            rem_mem = m;
        }
        else {
            it--;
            rem_mem = m - *it;
            time += *it;
            A.erase(A.find(*it));
        }
    }

    cout << time + 1 << endl;
}