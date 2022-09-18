#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e15

class PushRelabel {
    public:
    int n, s, t;
    vector<vector<int>> flow, cap;
    vector<int> height, excess;
    PushRelabel(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        height.assign(n, 0);
        excess.assign(n, 0);
        flow.assign(n, vector<int> (n, 0));
        height[s] = n;
        excess[s] = inf;
    }

    void push(int u, int v) {
        int d = min(excess[u], cap[u][v] - flow[u][v]);
        flow[u][v] += d; flow[v][u] -= d;
        excess[u] -= d;
        excess[v] += d;
    }

    void relabel(int u) {
        int d = inf;
        for(int i=0; i<n; i++) {
            if(cap[u][i] - flow[u][i] > 0) {
                d = min(d, height[i]);
            }
        }
        if(d < inf) height[u] = d + 1;
    }

    vector<int> find_max_height_vertices() {
        vector<int> max_height;
        int mx = INT_MIN;
        for(int i=0; i<n; i++) {
            if(i == s || i == t) continue;
            if(height[i] > mx && excess[i] > 0) {
                mx = height[i];
            } 
        }
        for(int i=0; i<n; i++) {
            if(i == s || i == t) continue;
            if(height[i] == mx && excess[i] > 0) max_height.push_back(i);
        }
        return max_height;
    }

    int get_maxflow() {
        for(int i=0; i<n; i++) {
            if(i != s) push(s, i);
        }
        vector<int> current;
        while(!(current = find_max_height_vertices()).empty()) {
            for(int i : current) {
                bool pushed = false;
                for(int j=0; j<n && excess[i]; j++) {
                    if(cap[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1) {
                        push(i, j);
                        pushed = true;
                    }
                }
                if(!pushed) {
                    relabel(i);
                    break;
                }
            }
        }

        int max_flow = 0;
        for(int i=0; i<n; i++) max_flow += flow[i][t];
        return max_flow;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    PushRelabel pr(n, 0, n-1);
    pr.cap.resize(n, vector<int> (n, 0));
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        pr.cap[u][v] = w;
        // pr.cap[v][u] = w;//
    }
    cout<<pr.get_maxflow();
}