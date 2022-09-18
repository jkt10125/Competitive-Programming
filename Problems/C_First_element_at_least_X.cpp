// #include <bits/stdc++.h>
// using namespace std;

// class segtree {
//     pair<int, int> range;
//     int data;
//     segtree *left, *right;
//     public:
//     segtree(vector<int> &A, pair<int, int> R){
//         range = R;
//         if(R.first == R.second) {
//             data = A[R.first];
//             left = right = NULL;
//         }
//         else {
//             int mid = (R.first + R.second) / 2;
//             left = new segtree(A, {R.first, mid});
//             right = new segtree(A, {mid+1, R.second});
//             data = max(left->data, right->data);
//         }
//     }

//     void update(int idx, int val) {
//         if(range.first == range.second) {
//             data = val;
//             return;
//         }
//         int mid = (range.first + range.second) / 2;
//         if(idx > mid) right->update(idx, val);
//         else left->update(idx, val);
//         data = max(left->data, right->data);
//     }

//     int query(int k) {
//         if(data < k) return -1;
//         if(range.first == range.second) return range.first;

//         if(left->data >= k) return left->query(k);
//         else return right->query(k);
//     }
// };

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> A(n);
//     for(int i = 0; i < n; i++) cin >> A[i];
//     segtree st(A, {0, n-1});
//     while(m--) {
//         int q, x;
//         cin >> q >> x;
//         if(q == 1) {
//             int y;
//             cin >> y;
//             st.update(x, y);
//         }
//         else {
//             cout << st.query(x) << endl;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

class segtree {
    pair<int, int> range;
    int data;
    segtree *left, *right;
    public:
    segtree(vector<int> &A, pair<int, int> R){
        range = R;
        if(R.first == R.second) {
            data = A[R.first];
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree(A, {R.first, mid});
            right = new segtree(A, {mid+1, R.second});
            data = max(left->data, right->data);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            data = val;
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = max(left->data, right->data);
    }

    int q(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->q(R);
        else if(R.second <= mid) return left->q(R);
        else return max(left->q(R), right->q(R));
    }

    int query(pair<int, int> R, int k) {
        if(data < k) return -1;
        if(range.first == range.second) return range.first;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R, k);
        else if(R.second <= mid) return left->query(R, k);
        
        if(q(make_pair(R.first, mid)) >= k) return left->query({R.first, mid}, k);
        else return right->query({mid+1, R.second}, k);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    segtree st(A, {0, n-1});
    while(m--) {
        int q, x, y;
        cin >> q >> x;
        if(q == 1) {
            cin >> y;
            st.update(x, y);
        }
        else {
            cout << st.query({0, n-1}, x) << endl;
        }
    }
}