#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &A, int a, int b, int c) {
    int n = A.size();
    map<int, int> M1, M2, M3;
    for(int i=0; i<n; i+=3) {
        if(A[i] == a || A[i] == b || A[i] == c) {
            M1[A[i]]++;
        }
    }
    for(int i=1; i<n; i+=3) {
        if(A[i] == a || A[i] == b || A[i] == c) {
            M2[A[i]]++;
        }
    }
    for(int i=2; i<n; i+=3) {
        if(A[i] == a || A[i] == b || A[i] == c) {
            M3[A[i]]++;
        }
    }

    int ctr = 0;
    int bb = min(M1[b], M2[a]);
    ctr += bb;
    M1[b] -= bb; M1[a] += bb;
    M2[a] -= bb; M2[b] += bb;

    bb = min(M1[c], M3[a]);
    ctr += bb;
    M1[c] -= bb; M1[a] += bb;
    M3[a] -= bb; M3[c] += bb;
    
    bb = min(M2[c], M3[b]);
    ctr += bb;
    M2[c] -= bb; M2[b] += bb;
    M3[b] -= bb; M3[c] += bb;

    return n - M1[a] - M2[b] - M3[c] + ctr;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        if(n <= 3) {
            cout<<"ss"<<endl;
        }
        else {
            map<int, int> AA, BB, CC;
            for(int i=0; i<n; i+=3) AA[A[i]]++;
            for(int i=1; i<n; i+=3) BB[A[i]]++;
            for(int i=2; i<n; i+=3) CC[A[i]]++;

            int ans = INT_MAX;
            for(auto it1 : AA) {
                for(auto it2 : BB) {
                    for(auto it3 : CC) {
                        if(it1.first == it2.first || it2.first == it3.first || it3.first == it1.first)
                            continue;
                        ans = min(ans, f(A, it1.first, it2.first, it3.first));
                    }
                }
            } 

            if(ans == INT_MAX) {
                
            }

            cout<<ans<<endl;
        }
    }
}