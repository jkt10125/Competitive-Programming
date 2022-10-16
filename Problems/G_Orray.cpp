#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n), b(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int ans = 0;
        vector<int> seq;
        for(int i=31; i>=0; i--) {
            if(ans & (1 << i)) continue;
            int idx = -1;
            for(int j=0; j<n; j++) {
                if(b[j]) continue;
                if(A[j] & (1 << i)) {
                    if(idx == -1) idx = j;
                    else {
                        if((ans | A[j]) > (ans | A[idx])) {
                            idx = j;
                        }
                    }
                }
            }
            if(idx != -1) {
                ans |= A[idx];
                seq.push_back(A[idx]);
                b[idx] = 1;
            }
        }
        for(int i=0; i<n; i++) {
            if(!b[i]) seq.push_back(A[i]);
        }
        for(auto it : seq) cout << it << " ";
        cout << endl;
    }
}