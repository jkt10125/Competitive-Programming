#include "/home/jkt/Desktop/Competitive-Programming/Snippets/debug/template.h"

signed main () {
    int n;
    cin >> n;
    map<int, vector<string>> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[i % 2].push_back(s);
    }

    cout << m;
}