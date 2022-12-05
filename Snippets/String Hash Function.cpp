#include "Custom Integer.cpp"

const int m1 = 1000000007;
const int m2 = 1000000009;
const int hash_exp = 31;

class HASH {
    public:
    mint f, s;
    bool operator == (const HASH &rhs) const {
        return (f == rhs.f) && (s == rhs.s);
    }
};

HASH str_hash(string &s) {
    mint ep1(m1, 1), ep2(m2, 1);
    mint hs1(m1, 0), hs2(m2, 0);
    for (char c : s) {
        hs1 += ep1 * (c - 'a' + 1);
        hs2 += ep2 * (c - 'a' + 1);
        ep1 *= hash_exp;
        ep2 *= hash_exp;
    }
    return {hs1, hs2};
}

vector<HASH> p_hash;

void gen_hash(string &s) {
    mint ep1(m1, 1), ep2(m2, 1);
    mint hs1(m1, 0), hs2(m2, 0);
    p_hash.resize(s.size());
    int ctr = 0;
    for (char c : s) {
        hs1 += ep1 * (c - 'a' + 1);
        hs2 += ep2 * (c - 'a' + 1);
        ep1 *= hash_exp;
        ep2 *= hash_exp;
        p_hash[ctr++] = {hs1, hs2};
    }
}

HASH sub_hash(int l, int r) {
    if (!l) return p_hash[r];
    mint f1(m1, hash_exp), f2(m2, hash_exp);
    f1 = f1.power(f1, l).inv();
    f2 = f2.power(f2, l).inv();
    f1 *= (p_hash[r].f - p_hash[l-1].f);
    f2 *= (p_hash[r].s - p_hash[l-1].s);
    return {f1, f2};
}

signed main() {
    string s;
    cin >> s;
    string t = "rtha";
    auto h = str_hash(t);
    cerr << h.f << ' ' << h.s << endl;
    gen_hash(s);
    bool ok = false;
    for(int i=0; i<=(int)s.size()-t.size(); i++) {
        if(h == sub_hash(i, i+t.size()-1)) ok = 1;
    }
    if(ok) cout << "YES";
    else cout << "NO";
}
