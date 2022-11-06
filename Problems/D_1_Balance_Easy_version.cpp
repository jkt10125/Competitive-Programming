#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    set<int> s;
    s.insert(0);
    int complete = 0;
    map<int, int> ans;
    while(q--) {
        char c;
        int a;
        cin >> c >> a;
        if(c == '+') {
            if(a == complete + 1) complete++;
            s.insert(a);
        }
        else {
            int val = complete / a * a;
            if(ans[a] != 0) val = ans[a];
            while(s.find(val) != s.end()) {
                val += a;
            }   
            ans[a] = val;
            cout << val << endl;
        }
    }
}