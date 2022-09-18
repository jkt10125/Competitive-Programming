#include <bits/stdc++.h>
using namespace std;

class LazySegTree {
    int value;
    pair<int, int> range;
    LazySegTree *left, *right;
  public:
    LazySegTree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { value = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new LazySegTree(A, {R.first, mid});
            right = new LazySegTree(A, {mid+1, R.second});
            value = 0;
        }
    }

    void push() {
        if(!value) return;
        if(left) { left->value += value; }
        if(right) { right->value += value; }
        value = 0;
    }

    void update(pair<int, int> R, int val) {
        if(range == R) {
            value += val;
            return;
        }
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) right->update(R, val);
        else if(R.second <= mid) left->update(R, val);
        else {
            left->update({R.first, mid}, val);
            right->update({mid+1, R.second}, val);
        }
    }

    int value_at(int idx) {
        if(range.first == range.second) return value;
        push();
        int mid = (range.first + range.second) / 2;
        if(idx > mid) return right->value_at(idx);
        else return left->value_at(idx);
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<value<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        LazySegTree tree(A, {0, n-1});
        // tree.print();
        int ctr = 0;

        vector<vector<int>> AA;
        for(int i=1; i<n; i++) {
            if(tree.value_at(i) > tree.value_at(i-1)) {
                continue;
            }
            vector<int> temp(3);
            ctr = tree.value_at(i-1) - tree.value_at(i) + 1;
            temp[0] = 1;
            temp[1] = ctr;
            temp[2] = i+1;
            AA.push_back(temp);
            tree.update({i, i}, ctr);
        }

        cout<<AA.size()<<"\n";
        for(auto it : AA) {
            cout<<it[0]<<" "<<it[1]<<endl;
            cout<<it[2]<<"\n";
        }
    }

}