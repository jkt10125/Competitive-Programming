// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, m;
//         cin >> n >> m;
//         vector<int> A(n);
//         vector<pair<int, int>> Q(m);
//         for(int i=0; i<n; i++) cin >> A[i];
//         for(int i=0; i<m; i++) {
//             cin >> Q[i].first;
//             Q[i].second = i;
//         }
//         sort(Q.begin(), Q.end());

//         int height = 0, ctr = 0;
//         vector<int> ans(m);
//         for(int i=0; i<m; i++) {
//             while(A[ctr] <= Q[i].first && ctr < n) {
//                 height += A[ctr];
//                 ctr++;
//             }
//             ans[Q[i].second] = height;
//         }   

//         for(int i=0; i<m; i++) cout << ans[i]<<" ";
//         cout<<endl;
//     }
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long 

int bin(vector<pair<int,int>>A, int x){
    int lo=0;
    int hi=A.size()-1;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(A[mid].first<=x){
            lo=mid+1;
            ans=A[mid].second;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> vec(n);
    vector<int> query(q);
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        vec[i].first=x;
    }
    vec[0].second=vec[0].first;
    // cout<<vec[0].second<<" ";
    for(int i=1; i<n; i++){
        vec[i].second+=(vec[i-1].second+vec[i].first);
        // cout<<vec[i].second<<" ";
    }
    for(int i=0; i<q; i++){
        cin>>query[i];
    }
    for(int i=1; i<n; i++){
        vec[i].first=max(vec[i].first,vec[i-1].first);
    }
    for(auto x:query){
        cout<<bin(vec,x)<<" ";
    }
    cout<<"\n";

}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}