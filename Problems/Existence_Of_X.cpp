#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int A[2][2][2];
    
    A[0][0][0] = 0;
    A[0][0][1] = 1;
    A[0][1][0] = 0;
    A[0][1][1] = 0;
    A[1][0][0] = 0;
    A[1][0][1] = 0;
    A[1][1][0] = 1;
    A[1][1][1] = 0;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = 0;
        int ca = 0;
        bool ok = true;
        for(int i=0; i < 28; i++) {
            int aa = ((a & (1 << i)) != 0);
            int bb = ((b & (1 << i)) != 0);
            int cc = ((c & (1 << i)) != 0);

            ca = (ca + A[aa][bb][cc]) % 2;
        }

        if(ca) cout << "NO\n";
        else cout << "YES\n";
    }
}