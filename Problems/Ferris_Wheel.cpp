#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    multiset<int> A;
    int ctr = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }

    while(true) {
        if(A.empty()) break;
        ctr++;
        int it = *(--A.end());
        A.erase(--A.end());
        
        if(A.empty()) break;
        auto iit = A.upper_bound(x - it);
        if(iit == A.begin()) continue;
        else A.erase(--iit);
    }
    cout<<ctr;
}