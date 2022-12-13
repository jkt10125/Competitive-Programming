#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<string, vector<int>> m;
        for (int i = 0; i < n - 1; i++) {
            m[s.substr(i, 2)].push_back(i);
        }
        bool ok = false;
        for (auto it : m) {
            if (it.first[0] != it.first[1]) {
                if(it.second.back() != it.second.front()) {
                    ok = true;
                }
            }
            else if (it.second.back() > it.second.front() + 1) {
                ok = true;
            }
        }

        if(ok) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}