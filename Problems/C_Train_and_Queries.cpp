#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        set<pair<int, int>> A;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            A.insert({x, i});
        }

        while(k--) {
            int a, b;
            cin >> a >> b;
            auto it = A.upper_bound({b+1, -1});
            if(it == A.begin()) {
                cout<<"NO\n";
                continue;
            }
            it--;
            auto it2 = A.lower_bound({a, -1});
            if(it2 == A.end()) {
                cout<<"NO\n";
                continue;
            }
            
            if(it->first != b || it2->first != a) {
                cout<<"NO\n";
                continue;
            }

            if(it->second < it2->second) {
                cout<<"NO\n";
                continue;
            }

            cout<<"YES\n";
            continue;
        }
    }
}