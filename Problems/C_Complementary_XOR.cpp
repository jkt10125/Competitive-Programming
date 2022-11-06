#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if(n == 1) {
            if(a == "1" && b == "0") {
                cout << "YES\n";
                cout << "1\n1 1\n";
            }
            if(a == "1" && b == "1") {
                cout << "NO\n";
            }
            if(a == "0" && b == "1") {
                cout <<"NO\n";
            }
            if(a == "0" && b == "0") {
                cout << "YES\n";
                cout << "0\n";
            }
            continue;
        }
        string comp_a = a;
        for(char &c : comp_a) {
            c = '1' - c + '0';
        }
        vector<pair<int, int>> v;
        int o = 0;
        for(char c : a) o += (c == '1');
        if(a == b || comp_a == b) {
            cout << "YES\n";
            for(int i=0; i<n; i++) {
                if(a[i] == '1') {
                    v.push_back({i+1, i+1});
                } 
            }
            if((a == b && (o & 1)) || (comp_a == b && (o % 2 == 0))) {
                v.push_back({n, n});
                v.push_back({n-1, n-1});
                v.push_back({n-1, n});
            }
            cout << v.size() << endl;
            for(auto p : v) cout << p.first << ' ' << p.second << endl;
        }
        else cout << "NO\n";
    }
}