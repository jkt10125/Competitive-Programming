#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout<<n<<endl;
        vector<int> A(n+1);
        for(int i=1; i<=n; i++) A[i] = i;

        for(int i=1; i<=n; i++) cout<<A[i]<<" ";
        cout<<endl;
        // for(int i=0; i<n; i++) {
            for(int j=n; j>1; j--) {
                swap(A[j], A[j-1]);
                for(int i=1; i<=n; i++) cout<<A[i]<<" ";
                cout<<endl;
            }
        // }
    }
}