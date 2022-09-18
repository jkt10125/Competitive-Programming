#include <bits/stdc++.h>
using namespace std;

int temp;
int input() { cin >> temp; return temp; }

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> S;
    for(int i=0; i<n; i++) {
        S.insert(input());
    }

    int hsh[32] = {0};
    for(int i=0; i<32; i++) {
        for(auto it : S) {
            if((it >> i) & 1) hsh[i]++;
        } 
    }

    for(int i=0; i<32; i++) cerr << hsh[i]<<" ";

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}