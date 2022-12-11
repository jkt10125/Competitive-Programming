#include <bits/stdc++.h>
using namespace std;

vector<int> Manacher (string &t) {
    int n = t.size();
    string s = "!" + t + "$";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + r - i]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    p.erase(p.begin());
    p.pop_back();

    for (int i = 0; i < n; i++) p[i]--;  
    // yeah i did this because i prefer having info of
    //  #position of palindrome on either side except
    //  the center one!
    
    return p;
}

int main () {
    string s;
    cin >> s;
    for (auto it : Manacher(s)) cout << it << ' ';
}