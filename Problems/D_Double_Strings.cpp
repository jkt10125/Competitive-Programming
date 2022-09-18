#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, set<string>> M;
        vector<string> V(n);
        for(int i=0; i<n; i++) {
            cin >> V[i];
            M[V[i].size()].insert(V[i]);
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            for(int ctr=1; ctr<V[i].size(); ctr++) {
                if(M[ctr].find(V[i].substr(0, ctr)) != M[ctr].end()) {
                    if(M[V[i].size()-ctr].find(V[i].substr(ctr, 10)) != M[V[i].size()-ctr].end()) {
                        ans[i]++;
                        break;
                    }
                }
            }
        }



        for(int i=0; i<n; i++) cout<<ans[i];
        cout<<endl;
    }
}