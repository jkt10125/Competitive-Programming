#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m;
    multiset<int> A;
    for(int i=0; i<n; i++) {
        cin >> x;
        A.insert(x);
    }
    for(int i=0; i<m; i++) {
        cin >> x;
        auto it = A.upper_bound(x);
        if(it == A.begin()) cout<<-1;
        else {
            cout<<*(--it);
            A.erase(it);
        }
        cout<<endl;
    }
}