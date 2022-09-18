#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vpii vector<pii>
#define ff first
#define ss second


int main() {
    int n;
    cin >> n;
    vpii A(n);
    for(int i=0; i<n; i++) cin >> A[i].ff >> A[i].ss;
    sort(A.begin(), A.end(), [](pii a, pii b) { return (a.ff == b.ff) ? a.ss > b.ss : a.ff < b.ff; });
    
    int ctr = 0, idx = 0;
    for(int i=1; i<n; i++) {
        if(A[i].ff == A[idx].ff) ctr++;
        else {
            if(A[i].ss <= A[idx].ss) ctr++;
            else { idx = i; }
        }
    }

    cout << n - ctr << endl;
}