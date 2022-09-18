#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        map<long long, int> M;
        for(int i=0; i<n; i++) M[A[i]]++;

        A.clear();
        for(auto it : M) {
            if(it.second & 1) A.push_back(it.first);
        }

        long long int xor_sum = 0;
        for(int i : A) xor_sum ^= i;
        
        if(xor_sum == 0) cout << "Eleven\n";
        else if(A.size() & 1) cout<<"Demogorgon\n";
        else cout<<"Eleven\n";
    }
}