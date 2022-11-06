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

        int ctr = 0;
        for(char c : s) {
            if(c == 'Q') ctr++;
            else {
                if(ctr) ctr--;
            }
        }
        if(ctr) cout << "No\n";
        else cout << "Yes\n";
    }
}