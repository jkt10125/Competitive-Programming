#include <iostream>
using namespace std;

const int N = 200007;
int p[N], s[N];

void makeset(int n) {
    for(int i=0; i<n; i++) p[i] = i, s[i] = 1;
}

int findset(int x) {
    if(x == p[x]) return x;
    return p[x] = findset(p[x]);
}

bool unionset(int x, int y) {
    int X = findset(x), Y = findset(y);
    if(X == Y) return false;
    if(s[X] < s[Y]) swap(X, Y);
    p[Y] = X; s[X] += s[Y];
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        makeset(n+1);
        bool f = true;
        int ctr[n+1] = {0};
        for(int i=0; i<n; i++) {
            int x, y;
            cin >> x >> y;
            ctr[x]++; ctr[y]++;
            if(!unionset(x, y)) {
                if(s[findset(x)] & 1) f = false;
            }
        }
        for(int i=1; i<=n; i++) if(ctr[i]-2) {f = false; break; }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}