#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    set<pair<int, int>> S;
    multiset<int> dist;

    S.insert({0, n});
    dist.insert(n+1);

    for(int i=0; i<k; i++) {
        int a;
        cin >> a;
        auto it = S.lower_bound({a, n});
        int aa = it->first, bb = it->second;
        S.erase(it);
        dist.erase(bb-aa+1);
        S.insert({aa, a-1});
        S.insert({a+1, bb});
        dist.insert(a-aa);
        dist.insert(bb-a);

        cout<<*(--dist.end())<<" ";
    }
}