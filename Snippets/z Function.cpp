#include <bits/stdc++.h>
using namespace std;

vector<int> zFunction (string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min (r - i + 1, z[i - l]);
        }
        while (i + z[i] < n) {
            if (s[z[i]] != s[i + z[i]]) break;
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> substringSearch (string &w, string &s) {
    string res = w + "$" + s;
    vector<int> z = zFunction(res);
    vector<int> match;
    for (int i = w.size() + 1; i < res.size(); i++) {
        if (z[i] == w.size()) {
            match.push_back(i - w.size() - 1);
        }
    }
    return match;
}

// The number of different substring in a string :: O(n * n)
// ==> use suffix array method instead :: O(n logn)

// smallest string a whose several times concatenation produces s
// |a| = compression Length
int compressionLength (string &s) {
    int n = s.size();
    vector<int> z = zFunction(s);
    int len = n;
    for (int i = 0; i < n ; i++) {
        if (n % i) continue;
        if (i + z[i] == n) {
            len = i;
            break;
        }
    }
    return len;
}