#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<pair<int, int>, int> A[n];
    for(int i=0; i<n; i++) {
        cin >> A[i].first.first >> A[i].first.second;
        A[i].second = i;
    }

    sort(A, A+n);

    // for(auto it : A) cerr<<it.first<<" "<<it.second<<"\n";

    set<pair<int, int>> s;
    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        auto it = s.upper_bound({A[i].first.first, 0});
        if(it == s.begin()) {
            s.insert({A[i].first.second, s.size()+1});
            ans[A[i].second] = s.size();
        }
        else {
            it--;
            int aa = it->second;
            s.erase(it);
            s.insert({A[i].first.second, aa});
            ans[A[i].second] = aa;
        }
    }

    cout<<s.size()<<endl;
    for(auto i : ans) cout<<i<<" ";
}