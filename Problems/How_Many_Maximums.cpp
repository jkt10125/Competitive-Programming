#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = "0" + s;
        int ctr = 1;
        for(int i=1; i<n; i++) {
            if(s[i] == '0' && s[i-1] == '1') {
                ctr++;
            }
        }

        cout<<ctr<<"\n";
    }
}