#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int solve(int l, int r, char c) {
    if(l == r) return s[l] != c;
    int a = (r-l+1) / 2;
    map<char, int> M, N;
    for(int i=0; i<a; i++) M[s[l+i]]++;
    for(int i=0; i<a; i++) N[s[r-i]]++;
    return min(a-M[c]+solve(l+a, r, c+1), a-N[c]+solve(l, r-a, c+1));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cin >> s;
        cout<<solve(0, n-1, 'a')<<endl;
    }
}