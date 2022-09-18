#include <bits/stdc++.h>
using namespace std;
#define int long long
class ds {
    public:
    int pref, suff, sum, ans;
    ds(int a = 0) {
        sum = a;
        pref = suff = ans = max(a, 0ll);
    }
    void print() {
        cout<<pref<<" "<<sum<<" "<<suff<<" "<<ans<<endl;
    }
};

ds f(ds l, ds r) {
    ds a;
    a.sum = l.sum + r.sum;
    a.pref = max(l.pref, l.sum + r.pref);
    a.suff = max(l.suff + r.sum, r.suff);
    a.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return a;
}

class segtree{
    pair<int, int> range;
    ds data;
    segtree *l, *r;
    public:
    segtree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = ds(A[R.first]);
            l = r = nullptr;
        }
        else {
            int mid = (R.first + R.second) / 2;
            l = new segtree(A, {R.first, mid});
            r = new segtree(A, {mid+1, R.second});
            data = f(l->data, r->data);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            data = ds(val);
        }
        else {
            int mid = (range.first + range.second) / 2;
            if(idx > mid) r->update(idx, val);
            else l->update(idx, val);
            data = f(l->data, r->data);
        }
    }

    ds query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return r->query(R);
        else if(R.second <= mid) return l->query(R);
        else return f(l->query({R.first, mid}), r->query({mid+1, R.second}));
    }

    void print() {
        cout<<range.first<<", "<<range.second<<" : ";
        data.print();
        if(l) l->print();
        if(r) r->print();
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    segtree T(A, {0, n-1});
    // T.print();
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            b--;
            T.update(b, c);
        }
        else {
            b--; c--;
            cout<<T.query({b, c}).pref<<"\n";
        }
    }
}