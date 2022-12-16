#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    bool operator < (const point &A) {
        return (x == A.x) ? (y < A.y) : (x < A.x);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        point A[3];
        cin >> A[0].x >> A[0].y;
        cin >> A[1].x >> A[1].y;
        cin >> A[2].x >> A[2].y;
    
        sort(A, A + 3);

        bool ok = false;

        if (A[0].x == A[1].x || A[1].x == A[2].x || A[2].x == A[0].x) {
            if (A[0].y == A[1].y || A[1].y == A[2].y || A[2].y == A[0].y) {

            }
            else ok = true;
        }
        else {
            ok = true;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";

    }


}