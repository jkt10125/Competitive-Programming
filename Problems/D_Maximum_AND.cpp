#include <bits/stdc++.h>
using namespace std;

int ans, e, n;
vector<int> A, B;
bool cmp(int a, int b) {
    return ((a & (1 << e)) < (b & (1 << e)));
}

void solve(int l, int r, int &e) {
    if(e < 0 || l > r) return;
    

    int a=0, b=0;
    for(int i=l; i<=r; i++) {
        if(A[i] & (1 << e)) a++;
        if(B[i] & (1 << e)) b++;
    }
    if(a + b != r-l+1) solve(l, r, --e);
    else {
        sort(A.begin()+l, A.begin()+r+1, cmp);
        sort(B.begin()+l, B.begin()+r+1, cmp);
        reverse(B.begin()+l, B.begin()+r+1);
        e--;
        solve(l, l+b-1, e);
        solve(l+b, r, e);
    } 
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        A.resize(n);
        B.resize(n);
        for(int i=0; i<n; i++) cin >> A[i];
        for(int i=0; i<n; i++) cin >> B[i];

        e = 29;
        solve(0, n-1, e);

        ans = (1 << 30) - 1;
        for(int i=0; i<n; i++) {
            int a = A[i] ^ B[i];
            ans = ans & a;
        }

        for(int i : A) cerr<<i<<" ";
        cerr<<endl;
        for(int i : B) cerr << i << " ";
        cerr<<endl;
        

        cout<<ans<<endl;
    }
}