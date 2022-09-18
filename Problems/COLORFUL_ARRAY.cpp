#include <bits/stdc++.h>
using namespace std;

vector<int> A;
// vector<int> ans;

class LazySegTree {
    int value;
    pair<int, int> range;
    LazySegTree *left, *right;
  public:
    LazySegTree(vector<int> &A, pair<int, int> R) {
        range = R;
        value = 0;
        if(R.first == R.second) { value = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new LazySegTree(A, {R.first, mid});
            right = new LazySegTree(A, {mid+1, R.second});
        }
    }

    void push() {
        if(!value) return;
        if(left) { left->value = value; }
        if(right) { right->value = value; }
        if(range.first != range.second) value = 0;
        // value = 0;
    }

    void update(pair<int, int> R, int val) {
        if(range == R) { value = val; return; }
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) right->update(R, val);
        else if(R.second <= mid) left->update(R, val);
        else {
            left->update({R.first, mid}, val);
            right->update({mid+1, R.second}, val);
        }
    }

    void final_push() {
        push();
        if(left) left->final_push();
        if(right) right->final_push();
    }

    void transfer() {
        if(range.first == range.second) {
            A[range.first] = value;
            return;
        }
        if(left) left->transfer();
        if(right) right->transfer();
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<value<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};
// int main() {
//     int n, m;
//     cin >> n >> m;
//     A.resize(n);
//     parent.resize(n);
//     // for(int i=0; i<n; i++) cin >> A[i];
//     LazySegTree tree(A, {0, n-1});
//     // tree.print();
//     for(int i=0; i<m; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         a--; b--;
//         tree.update({a, b}, c);
//     }
//     tree.final_push();
//     // tree.print();
//     tree.transfer();
//     for(int i=0; i<n; i++) cout << A[i] << "\n";
// }

vector<int> parent;

void make_set(int n) {
    parent.resize(n);
    for(int i=0; i<n; i++) parent[i] = i;
    return;
}

int find_set(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

int main() {
    int n, m;
    cin >> n >> m;
    make_set(n+2);
    vector<pair<pair<int, int>, int>> Q(m);
    for(int i=0; i<m; i++) {
        cin >> Q[i].first.first >> Q[i].first.second >> Q[i].second;
    }

    vector<int> ans(n+1, 0);
    for(int i=m-1; i>=0; i--) {
        int l = Q[i].first.first;
        int r = Q[i].first.second;
        int c = Q[i].second;
        for(int j=find_set(l); j<=r; j=find_set(j)) {
            ans[j] = c;
            parent[j] = j+1;
        }
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<endl;
}