#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second

void print(vector<pii> A) {
    for(auto it : A) {
        cout<<it.ff<<" "<<it.ss<<"\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi A(n), B(n);
        for(int i=0; i<n; i++) cin >> A[i];
        for(int i=0; i<n; i++) cin >> B[i];

        map<int, multiset<int>> M;
        for(int i=0; i<n; i++) {
            M[A[i]].insert(B[i]);
        }

        vi C;
        for(auto it : M) {
            for(auto it2 : it.ss) {
                C.push_back(it2);
            }
        }

        bool flag = true;
        for(int i=1; i<n; i++) {
            if(C[i] < C[i-1]) {
                flag = false;
                break;
            }
        }
        if(!flag) { cout<<"-1\n"; continue; }



    }
}