#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &A, int &a, int &b) {
    a = b = A.front();
    int max_score = 1;
    int current_max_score = 1;
    int l=A[0], r=A[0];
    for(int i=1; i<A.size(); i++) {
        r = A[i];
        current_max_score -= (A[i] - A[i-1] - 2);
        if(current_max_score < 1) {
            current_max_score = 1;
            l = r;
        }
        if(current_max_score > max_score) {
            max_score = current_max_score;
            a = l; b = r;
        }
    }
    return max_score;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        map<int, vector<int>> M;
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            M[x].push_back(i+1);
        }
        int ans = 0;
        int a, l, r;
        for(auto it : M) {
            int s, e;
            int g = f(it.second, s, e);
            if(ans < g) {
                ans = g;
                l=s; r=e;
                a=it.first;
            }
        }
        cout<<a<<" "<<l<<" "<<r<<endl;
    }
}