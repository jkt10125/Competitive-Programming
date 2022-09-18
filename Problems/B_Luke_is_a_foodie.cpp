#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<pair<int, int>> B(n);
        for(int i=0; i<n; i++) {
            B[i] = {A[i]-x, A[i]+x};
        }

        pair<int, int> intr = B[0];
        int ctr = 0;
        for(int i=1; i<n; i++) {
            if(intr.first > B[i].second || intr.second < B[i].first) {
                ctr++;
                intr = B[i];
            }
            else {
                intr.first = max(intr.first, B[i].first);
                intr.second = min(intr.second, B[i].second);
            }
        }

        cout<<ctr<<endl;
    }
    
}