#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> M;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        if(M[s] != 0) cout<<s<<"("<<M[s]<<")\n";
        else cout<<s<<"\n";
        M[s]++;
    }
}