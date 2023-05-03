#include <bits/stdc++.h>

std::vector<std::vector<std::pair<int, int>>> A;
std::vector<int> dist;
std::vector<bool> vis;


// returns false if negative cycle is detected
// Complexity O(n * m)p
bool bellmanFord_SPFA(int s) {
    int n = A.size();
    std::vector<int> cnt(n, 0);
    std::vector<bool> inQ(n, 0);
    std::queue<int> Q;

    Q.push(s);
    dist[s] = 0;
    inQ[s] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inQ[u] = false;
        for (std::pair<int, int> p : A[u]) {
            if (dist[u] + p.second < dist[p.first]) {
                dist[p.first] = dist[u] + p.second;
                if (!inQ[p.first]) {
                    Q.push(p.first);
                    inQ[p.first] = true;
                    cnt[p.first]++;
                    if (cnt[p.first] > n) return false;
                }
            }
        }
    }
    return true;
}