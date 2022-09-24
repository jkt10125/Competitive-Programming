#include <bits/stdc++.h>
using namespace std;

int diff(string a, string b) {
    int n = a.size();
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += abs(a[i]-b[i]);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        int mn = INT_MAX;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                mn = min(mn, diff(A[i], A[j]));
            }
        }
        cout<<mn<<endl;
    }
}