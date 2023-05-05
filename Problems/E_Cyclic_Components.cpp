#include <bits/stdc++.h>

class dsu {
    std::vector<int> p, s;
    public:
    dsu(int n) { p.resize(n); std::iota(p.begin(), p.end(), 0); s.assign(n, 1); }
    int FIND(int x) { return (x == p[x]) ? x : p[x] = FIND(p[x]); }
    bool UNION(int x, int y) { int X = FIND(x), Y = FIND(y); if (X == Y) return false; if (s[X] < s[Y]) std::swap(X, Y); p[Y] = X; s[X] += s[Y]; return true; }
    int SIZE(int x) { return s[FIND(x)]; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    dsu d(n + 1);
    std::vector<std::vector<int>> AA(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        AA[u].push_back(v);
        AA[v].push_back(u);
        d.UNION(u, v);
    }
    std::map<int, std::vector<int>> A;
    for (int i = 1; i <= n; i++) {
        A[d.FIND(i)].push_back(i);
    }
    int cycles = A.size();
    for (auto it : A) {
        for (int iit : it.second) {
            if (AA[iit].size() != 2) {
                cycles--;
                break;
            }
        }
    }

    std::cout << cycles << std::endl;
}