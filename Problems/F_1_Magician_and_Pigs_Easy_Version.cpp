#include <bits/stdc++.h>
using namespace std;


#define int long long

const int N = 200002;
const int M = 998224353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(N, 0);
    set<int> born;
    int dmg = 0;
    while (n--) {
        int a, b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            A[b] = (A[b] + 1) % M;
            born.insert(b);
        }
        else if (a == 2) {
            cin >> b;
            dmg += b;
            set<int> born2;
            for (int i : born) {
                if (i <= b) {
                    A[i] = 0;
                }
                else {
                    A[i - b] = (A[i - b] + A[i]) % M;
                    A[i] = 0;
                    born2.insert(i - b);
                }
            }
            born.swap(born2);
        }
        else {
            set<int> tmp;
            for (auto it = born.rbegin(); it != born.rend(); it++) {
                if (*it <= dmg) break;
                else {
                    A[*it - dmg] = (A[*it - dmg] + A[*it]) % M;
                    tmp.insert(*it - dmg);
                }
            }
            for(int i : tmp) {
                born.insert(i);
            }
            if (dmg <= 1e7) {
                dmg *= 2;
            } 
        }

        // for (int i=1;i<=10;i++){
        //     cerr<<A[i]<<' ';
        // }
        // cerr<<endl;
    }
    
    int ans = 0;
    for (int i : born) {
        ans = (ans + A[i]) % M;
    }
    cout << ans << endl;
}