#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(m);
        for(int i=0; i<m; i++) cin >> A[i];
        sort(A.begin(), A.end());

        vector<int> V(m);
        for(int i=0; i<m-1; i++) {
            V[i] = A[i+1] - A[i] - 1;
        }
        V.back() = n - A[m-1] + A[0] - 1;

        sort(V.begin(), V.end());
        if(V.back() <= 1) {
            cout<<n-V.back()<<endl;
            continue;
        }
        if(V.back() == 2) {
            cout<<n-1<<endl;
            continue;
        }

        int sum = V.back()-1;
        int p = m-2;
        int inf_ctr = 4;
        while(p >= 0) {
            if(V[p] <= inf_ctr) { V[p] = -1; break; }
            V[p] -= inf_ctr;
            if(V[p] == 1) { sum++; V[p] = -1; break; }
            if(V[p] == 2) { sum++; V[p] = -1; break; }
            if(V[p] <= 4) { sum += 2; V[p] = -1; break; }
            inf_ctr += 4;
            p--;
        }
        // for(int i=0; i<m; i++) cerr<<V[i]<<" "; cerr<<endl;
        p = m-2;
        while(p >= 0) {
            if(V[p] <= 0) break;
            sum += V[p--];
        }
        cout<<n-sum<<endl;
    }
}