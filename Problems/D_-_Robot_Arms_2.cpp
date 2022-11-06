#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> &A, int a) {
    int g[20001] = {0};
    g[10000] = 1;
    for(int x : A) {
        for(int i = 0; i<20001; i++) {
            if(g[i] == 1 || g[i] == 3) {
                if(i + x >= 0) {
                    if(g[i+x] == 0 || g[i+x] == 1) g[i+x]+=2;
                }
                if(i - x < 20001) { 
                    if(g[i-x] == 0 || g[i-x] == 1) g[i-x]+=2;
                }
                g[i]--;
            }
        }
        for(int i=0; i<20001; i++) {
            if(g[i] == 2 || g[i] == 3) g[i] = 1;
            else g[i] = 0; 
        }
    }
    return g[a + 10000];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    int x;
    cin >> x;
    a -= x;
    vector<int> A, B;
    for(int i=1; i<n; i++) {
        cin >> x;
        if(i & 1) B.push_back(x);
        else A.push_back(x);
    }

    if(f(A, a) & f(B, b)) cout << "Yes";
    else cout << "No";
}