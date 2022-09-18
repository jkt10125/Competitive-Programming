#include <bits/stdc++.h>
using namespace std;

check sub_str()

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> S(n), T(m);
    for(int i=0; i<n; i++) cin >> S[i];
    for(int i=0; i<m; i++) cin >> T[i];
    int siz = 0;
    for(auto str : S) siz += str.size();
    int no_ = 16-siz;
    int free_ = no_ - n + 1;
    sort(T.begin(), T.end());
    if(n == 1) {
        if(S[0] == T[0]) cout<<-1;
        else cout<<S[0];
    }
    else {

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                auto it = lower_bound(T.begin(), T.end(), S[i]);

            }
        }
        if(!free_) {

        }
    }
}