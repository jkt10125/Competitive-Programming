#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ctr = -1;
        for(int i=0; i<=n-7; i++) {
            if(s.substr(i, 7) == "strange") { ctr = i; break; }
        }

        long long a = ctr+1;
        long long b = n - ctr - 6;
        cout << (a * b) % mod << "\n";
    }
}