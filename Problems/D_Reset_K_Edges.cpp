/*
** Date: 29/12/2022 | Time: 13:03:47
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<vector<int>> A;
vector<int> p, u, l;
vector<array<int, 2>> lvl;

void dfs (int x) {
    for (int it : A[x]) {
        l[it] = l[x] + 1;
        dfs(it);
    }
}

void mark (int x) {
    u[x] = 1;
    for (int it : A[x]) {
        if (!u[it]) {
            mark(it);
        }
    }
}

bool f (int h) {
    u.assign(A.size(), 0);
    lvl.clear();
    for (int i = 2; i <= n; i++) {
        lvl.push_back({l[i], i});
    }

    int moves = k;
    sort (lvl.begin(), lvl.end());
    int idx = lvl.size() - 1;
    while (lvl[idx][0] > h) {
        if (!moves) return false;
        int v = lvl[idx][1];
        for (int i = 0; i < h - 1; i++) {
            v = p[v];
        }
        mark(v);
        moves--;
        while (idx >= 0 && u[lvl[idx][1]]) {
            idx--;
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        A.assign(n + 1, vector<int> ());
        p.resize(n + 1);
        l.resize(n + 1);

        l[1] = 0;
        p[1] = 1;

        for (int i = 2; i <= n; i++) {
            cin >> p[i];
            A[p[i]].push_back(i);
        }
        dfs(1);

        int L = 1, R = n - 1;
        int ans = n - 1;
        while (L <= R) {
            int m = (L + R) / 2;

            if (f(m)) {
                ans = m;
                R = m - 1;
            }
            else L = m + 1;
        }

        cout << ans << endl;
    }
}