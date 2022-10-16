#include <bits/stdc++.h>
using namespace std;

#define int long long

int lsb(int a) {
    return (a & -a);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            int ctr = 0;
            while(x % 2 == 0) {
                x /= 2;
                ctr++;
            }
            sum += ctr;
        }    

        vector<int> A;
        for(int i=2; i<= n; i+=2) A.push_back(log2(lsb(i)));
        
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        
        int moves = 0;
        for(int i=0; i<n/2; i++) {
            if(sum >= n) break;
            moves++;
            sum += A[i];
        }
        if(sum < n) cout<<-1;
        else cout << moves;
        cout<<endl;
    }
}