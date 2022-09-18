#include <bits/stdc++.h>
using namespace std;

int time_diff(pair<int, int> A, pair<int, int> B) {
    int h = A.first;
    int m = A.second;
    int tim1 = 60*h + m;
    h = B.first;
    m = B.second;
    int tim2 = 60*h + m;

    int diff = tim2 - tim1;
    if(diff >= 0) return diff;
    else return 24*60 + diff;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, h, m;
        cin >> n >> h >> m;
        vector<pair<int, int>> A(n);
        for(int i=0; i<n; i++) {
            cin>> A[i].first;
            cin >> A[i].second;
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            ans = min(ans, time_diff({h, m}, A[i]));
        }

        cout<<ans/60<<" "<<ans%60<<endl;
    }
}