#include <iostream>
#include <vector>
// #include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int n, q, x;
    cin >> n >> q >> x;
    int W[n];
    for(int i=0; i<n; i++) cin >> W[i];
    
    ll psum[n] = {W[0]};
    for(int i=1; i<n; i++) psum[i] = psum[i-1] + W[i];
    // for(int i=0; i<n; i++) cerr<<psum[i]<<" ";
    vector<int> A;
    // set<int> A;
    bool hsh[n]={0};
    x = x % psum[n-1];
    A.push_back(lower_bound(psum, psum+n, x) - psum);
    while(hsh[A.back()] == false) {
        hsh[A.back()] = true;
        cerr<<A.back()<<" ";
        if(psum[n-1] - psum[A.back()] >= x) A.push_back(lower_bound(psum+A.back()+1, psum+n, x+psum[A.back()]) - psum);
        else {
            int a = x - psum[n-1] + psum[A.back()];
            A.push_back(lower_bound(psum, psum+n, a) - psum);
        }
    }
    n = A.size();
    while(q--) {
        ll k;
        cin >> k;
        cout<<A[(k-1) % n]+1<<endl;
    }
}