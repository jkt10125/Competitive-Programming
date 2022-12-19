#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> A(n, vector<int> (m));
        int ctr = 0;
        vector<int> R(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
                ctr += A[i][j];
                R[i] += A[i][j];
            } 
        }

        if (ctr % n) cout << -1 << endl;
        else {
            int k = ctr / n;
            multiset<pair<int, int>> r;
            for (int i = 0; i < n; i++) {
                r.insert({R[i], i});
            }

            vector<array<int, 3>> op;

            while (r.begin()->first != k) {
                int xsr = (--r.end())->second;
                int dfr = (r.begin())->second;

                for (int i = 0; i < m; i++) {
                    if (A[xsr][i] && !A[dfr][i]) {
                        swap(A[xsr][i], A[dfr][i]);
                        op.push_back({xsr, dfr, i});
                        r.erase(r.find({R[xsr], xsr}));
                        r.erase(r.find({R[dfr], dfr}));
                        R[xsr]--;
                        R[dfr]++;
                        r.insert({R[xsr], xsr});
                        r.insert({R[dfr], dfr});
                        break;
                    }
                }
            }

            cout << op.size() << endl;
            for (auto [i, j, k] : op) {
                cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
            }
        }
    }
}