#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        s = s + s;
        int time = 0;
        int curr_c = -1;
        for(int i=0; i<2*n; i++) {
            if(s[i] == c) {
                if(curr_c == -1) curr_c = i;
            }
            if(s[i] == 'g') {
                if(curr_c != -1) time = max(time, i - curr_c);
                curr_c = -1;
            }
        }

        cout << time << endl;
    }
}