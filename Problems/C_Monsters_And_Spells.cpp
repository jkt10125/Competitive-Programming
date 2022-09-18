#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

long long f(int h, int k) {
    return (k-h+1) * (k-h+2) / 2;
}

void solve() 
{
    int n;
    
    cin >> n;
    
    vector<int> K(n), H(n);
    
    for(int i=0; i<n; i++) 
        cin >> K[i];
    
    for(int i=0; i<n; i++) 
        cin >> H[i];

    for(int i=0; i<n; i++)
        H[i] = K[i] - H[i] + 1;

    vector<pair<int, long long>> A; // <H, f(H, K)>
    long long ans = 0;

    for(int i=0; i<n; i++) {
        while(A.size() != 0 && A.back().ff >= H[i]) {
            ans -= A.back().ss;
            A.pop_back();
        }
        A.push_back({H[i], f(H[i], K[i])});
        ans += A.back().ss;
    }
    cout<<ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    
}