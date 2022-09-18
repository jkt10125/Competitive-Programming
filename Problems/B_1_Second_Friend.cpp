#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int _t=1; _t<=t; _t++) {
        cout<<"Case #"<<_t<<": ";
        int n, m;
        cin >> n >> m;
        char A[n][m];
        int ctr = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> A[i][j];
                ctr += (A[i][j] == '^');
            }
        }
        if(n == 1 || m == 1) {
            if(ctr) cout<<"Impossible\n";
            else {
                cout<<"Possible\n";
                char c = (n == 1) ? ' ' : '\n';
                for(int i=0; i<max(n, m); i++) cout<<'.'<<c;
                if(c != '\n') cout<<"\n";
            }
        }
        else {
            cout<<"Possible\n";
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    cout<<"^";
                }
                cout<<endl;
            }
        }
    }
}