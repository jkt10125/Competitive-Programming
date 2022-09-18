#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string J, N;
        cin >> J >> N;
        map<char, int> j, n;
        for(char c : J) j[c]++;
        for(char c : N) n[c]++;
        char ans = '?';
        for(auto it : j) {
            if(it.second > 1 && n[it.first] == 0) {
                ans = 'J';
                break;
            }
        }

        if(ans != '?') {
            cout<<ans<<endl;
            continue;
        }

        cout<<"N\n";
    }
}