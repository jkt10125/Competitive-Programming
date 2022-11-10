#include <bits/stdc++.h>
using namespace std;

#define int long long

const int m1 = 1000000007;
const int m2 = 1000000009;
const int hash_exp = 31;
vector<pair<int, int>> p_hash;

pair<int, int> string_hash(string &s) {
    int h1 = 0, h2 = 0, exp1 = 1, exp2 = 1;
    for(char c : s) {
        h1 = (h1 + (c - 'a' + 1) * exp1) % m1;
        h2 = (h2 + (c - 'a' + 1) * exp2) % m2;
        exp1 = (exp1 * hash_exp) % m1;
        exp2 = (exp2 * hash_exp) % m2;
    }
    return {h1, h2};
}

void generate_hash(string &s) {
    int h1 = 0, h2 = 0, exp1 = 1, exp2 = 1;
    p_hash.resize(s.size());
    int i=0;
    for(char c: s) {
        h1 = (h1 + (c - 'a' + 1) * exp1) % m1;
        h2 = (h2 + (c - 'a' + 1) * exp2) % m2;
        exp1 = (exp1 * hash_exp) % m1;
        exp2 = (exp2 * hash_exp) % m2;
        p_hash[i++] = {h1, h2};
    }
}

int power(int a, int b, int mod=0) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		if(mod) pow %= mod, a %= mod;
	}
	return pow;
}

// O(logn)
pair<int, int> substring_hash(int l, int r) {
    if(!l) return p_hash[r];
    int f1 = power(power(hash_exp, l, m1), m1-2, m1);
    int f2 = power(power(hash_exp, l, m2), m2-2, m2);
    f1 = (p_hash[r].first - p_hash[l-1].first + m1) * f1 % m1;
    f2 = (p_hash[r].second - p_hash[l-1].second + m2) * f2 % m2;
    return {f1, f2};
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        generate_hash(a);
        auto key = string_hash(b);
        int len = b.size();
        vector<int> ans;
        for(int i=0; i<=a.size()-b.size(); i++) {
            if(substring_hash(i, i+len-1) == key) {
                ans.push_back(i+1);
            }
        }

        if(ans.empty()) cout << "Not Found";
        else {
            cout << ans.size() << endl;
            for(int i : ans) cout << i << ' ';
        }
        cout << endl << endl;
    }
}