#include <bits/stdc++.h>
using namespace std;

int dist (int a, int b, int x, int y) {
    return abs(a-x) + abs(b-y);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        bool f = false;
        {
            bool a = true;
            for(int i=2; i<=n; i++) {
                if(dist(i, 1, x, y) <= d) a = false;
            }
            for(int i=2; i<=m; i++) {
                if(dist(n, i, x, y) <= d) a = false;
            }
            if(a) f = true;

            bool b = true;
            for(int i=2; i<=m; i++) {
                if(dist(1, i, x, y) <= d) b = false;
            }
            for(int i=2; i<=n; i++) {
                if(dist(i, m, x, y) <= d) b = false;
            }
            if(b) f = true;

        }
        if(f) cout << n+m-2 << endl;
        else cout << -1 << endl;
    }   
}