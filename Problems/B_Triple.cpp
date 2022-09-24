#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> A;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            A[x]++;
        }
        int ctr = 0;
        for(auto it : A) {
            if(it.second >= 3) ctr = it.first;
        }
        if(!ctr) cout<<-1;
        else cout<<ctr;
        cout<<endl;
    }
}