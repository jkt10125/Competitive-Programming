#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    queue<int> Q;
    set<int> S;

    int ans = 0, ctr = 0;
    for(int i=0; i<n; i++) {
        if(S.find(A[i]) == S.end()) {
            S.insert(A[i]);
            Q.push(A[i]);
        }

        else {
            while(Q.front() != A[i]) {
                S.erase(Q.front());
                Q.pop();
            }
            Q.pop();
            Q.push(A[i]);
        }
        ans = max(ans, (int)Q.size());
    }

    cout<<ans;
}