#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool ok = false;
        int s = 1, t = 1, s_size = 1;
        while(n--) {
            int a, k;
            string x;
            cin >> a >> k >> x;
            if(ok) { cout<<"YES\n"; continue; }
            if(a == 2) {
                for(char c : x) {
                    t += k * (c == 'a');
                    if(c != 'a') {
                        ok = true;
                    }
                }
            }
            else {
                s_size += k * x.size();
                for(char c : x) s += k * (c == 'a');
            }

            if(ok) { cout<<"YES\n"; continue; }
            if(t > s) {
                if(s_size == s) cout << "YES\n";
                else cout << "NO\n";
            }
            else {
                cout << "NO\n";
            }

        }
    }
}