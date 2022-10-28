#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    vector<pair<int, int>> B(n);
    for(int i=0; i<n; i++) B[i] = {A[i], i};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    bool ok = false;
    for(int i=0; i<n; i++) {
        int t = x - A[i];
        int p1 = i + 1, p2 = n - 1;
        while(p2 > p1) {
            int sum = A[p2] + A[p1];
            if(sum > t) p2--;
            else if(sum < t) p1++;
            else {
                cout << B[i].second + 1 << ' ' << B[p1].second + 1 << ' ' << B[p2].second + 1;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }

    if(!ok) cout << "IMPOSSIBLE\n";
}