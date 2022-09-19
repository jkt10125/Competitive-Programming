#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i=0; i<n; i++) cin >> A[i];
        if(n == 1) {
            cout<<"0\n";
            continue;
        }
        vector<pair<int, int>> op;
        op.push_back({0, n-1});
        if((A[0] + A[n-1]) & 1) A[n-1] = A[0];
        else A[0] = A[n-1];

        for(int i=1; i<n-1; i++) {
            if((A[0]+A[i]) & 1) {
                op.push_back({0, i});
            }
            else op.push_back({i, n-1});
        }
        cout<<op.size()<<endl;
        for(auto it : op) {
            cout<<it.first+1<<" "<<it.second+1<<endl;
        }
    }
}