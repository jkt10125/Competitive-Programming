#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

class SegTree {
    pair<int, int> range;
    int value;
    SegTree *left, *right;
  public:
    SegTree(pair<int, int> R) {
        range = R;
        value = 0;
        if(R.first == R.second) { left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree({R.first, mid});
            right = new SegTree({mid+1, R.second});
        }
    }

    void push() {
        if(range.first == range.second) return;
        if(!value) return;
        if(left) { left->value = value; }
        if(right) { right->value = value; }
        value = 0;
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
        final_push();
        if(range.first == range.second) ans[range.first] = value;
        else {
            if(left) left->transfer();
            if(right) right->transfer();
        }
    }

    void print() {
        cerr<<range.first<<" "<<range.second<<" : "<<value<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    ans.resize(n+1);
    SegTree tree({0, n-1});

    vector<pair<pair<int, int>, int>> A(m);
    for(int i=0; i<m; i++) {
        cin >> A[i].first.first >> A[i].first.second >> A[i].second;
        A[i].first.first--;
        A[i].first.second--;
    }

    for(int i=m-1; i>=0; i--) {
        tree.update(A[i].first, A[i].second);
    }
    tree.final_push();
    tree.print();
}