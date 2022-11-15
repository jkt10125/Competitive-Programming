#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A, B;
vector<int> a;

const int N = 1e9;
int final_node;
void dfs(int n) {
    for (int it : A[n]) {
        if (it == final_node) {
            if (binary_search(B[n].begin(), B[n].end(), it)) {
                a[it] = min(a[it], a[n]);
            }
            else {
                a[it] = min(a[it], a[n] + 1);
            }
        }

        else if (a[it] == N) {
            if (binary_search(B[n].begin(), B[n].end(), it)) {
                a[it] = a[n];
                dfs(it);
            }
            else {
                a[it] = a[n] + 1;
                dfs(it);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    final_node = n;
    A.resize(n + 1);
    a.resize(n + 1, N);
    B.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        B[u].push_back(v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(B[i].begin(), B[i].end());
    }

    a[1] = 0;
    dfs(1);

    cout << a[n];
}