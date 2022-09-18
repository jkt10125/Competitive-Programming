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

        map<int, int> M;
        for(int i=0; i<n; i++) M[A[i]]++;
        int ctr = 0;
        for(auto it : M) {
            if(it.second == 1) ctr++;
        }

        if(ctr == 1) {
            if((--M.end())->second % 2 == 0) {
                cout<<1;
            }
            else {
                int f = 1;
                for(auto it : M) {
                    if(it.first != (--M.end())->first) {
                        if(it.second != 2) { f = 0; break; }
                    }
                }
                if(f) cout<<"2";
                else cout<<1;
            }
        }
        else cout<<(ctr+1)/2;
        cout<<"\n";
    }
}