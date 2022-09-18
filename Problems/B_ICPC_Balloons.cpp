#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int hsh[26] = {0};
        for(int i=0; i<n; i++) {
            hsh[s[i]-'A']++;
        }
        int sum = 0;
        for(int i=0; i<26; i++) {
            if(hsh[i]) sum += hsh[i]+1;
        }

        cout<<sum<<"\n";
    }
}