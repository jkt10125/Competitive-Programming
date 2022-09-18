#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int A[n];
        for(int i=0; i<n; i++) cin >> A[i];
        long long sum = 0;
        for(int i=0; i<n; i++) sum += A[i];

        if(sum > m) cout<<sum-m<<"\n";
        else cout<<"0\n";
    }
}