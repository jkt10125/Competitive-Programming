#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        for(int i=1; i<n; i++) A[i] += A[i-1];

        while(q--) {
            int x;
            cin >> x;
            auto it = lower_bound(A.begin(), A.end(), x);
            if(it == A.end()) cout<<-1;
            else cout<<distance(A.begin(), it)+1;
            cout<<endl;
        }
    }
}