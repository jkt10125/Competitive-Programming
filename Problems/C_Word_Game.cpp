#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> M;
        vector<vector<string>> S(3, vector<string> (n));
        for(int i=0; i<3; i++) {
            for(int j=0; j<n; j++) {
                cin >> S[i][j];
                M[S[i][j]]++;
            }
        }

        int ans[3] = {0};
        for(int i=0; i<3; i++) {
            for(int j=0; j<n; j++) {
                if(M[S[i][j]] == 1) ans[i] += 3;
                if(M[S[i][j]] == 2) ans[i]++;
            }
        }

        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
    }
}