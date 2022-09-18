#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<vector<int>> T(n+1);
        for(int i=0; i<n; i++) {
            T[A[i]].push_back(i);
        }
        for(int i=1; i<=n; i++) {
            if(T[i].size() < 2) cout<<T[i].size()<<" ";
            else {
                int ctr = 1;
                for(int j=1; j<T[i].size(); j++) {
                    if((T[i][j]-T[i][j-1]) & 1) ctr++;
                }
                cout<<ctr<<" ";
            }
        }

        cout<<endl;
    }
}