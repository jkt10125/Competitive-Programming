#include <bits/stdc++.h>

std::vector<std::vector<int>> A;
std::set<std::pair<int, int>> markedEdges;
std::vector<int> ans;

std::pair<int, int> orderedPair(int x, int y) {
    if (x > y) std::swap(x, y);
    return std::make_pair(x, y);
}

void dfs(int x) {
    for (int it : A[x]) {
        if (markedEdges.find(orderedPair(x, it)) == markedEdges.end()) {
            markedEdges.insert(orderedPair(x, it));
            dfs(it);
        }
    }
    ans.push_back(x);
}

int main() {
    int n, m;
    std::cin >> n >> m;

    A.assign(n, std::vector<int> ());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    
}