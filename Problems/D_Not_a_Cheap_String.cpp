#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        int p;
        cin >> s >> p;
        int n = s.size();
        vector<pair<char, int>> V;
        for(int i=0; i<n; i++) V.push_back({s[i], i});
        sort(V.begin(), V.end());
        
        int value = 0;
        for(char c : s) {
            value += c - 'a' + 1;
        }
        vector<bool> hsh(n, true);
        int ctr = n-1;
        while(value > p) {
            value -= (V[ctr].first - 'a' + 1);
            hsh[V[ctr].second] = false;
            ctr--;
        }

        for(int i=0; i<n; i++) {
            if(hsh[i]) cout<<s[i];
        }

        cout<<endl;
    }
}