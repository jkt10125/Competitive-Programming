#include <bits/stdc++.h>
using namespace std;

// code taken from : https://cp-algorithms.com/graph/mpm.html
// O(V^3)

#define int long long

vector<pair<int, int>> A;

struct MPM {
    struct FlowEdge{
        int v, u;
        int cap, flow;
        FlowEdge() {}
        FlowEdge(int _v, int _u, int _c, int _f=0)
            : v(_v), u(_u), cap(_c), flow(_f) {}        
    };

    const int flow_inf = INT_MAX;  // in some cases (flow_inf > int_max) Watch out!
    vector<FlowEdge> edges;
    vector<int> ex, alive, Pin, Pout, lvl, q;
    vector<list<int>> in, out;
    vector<vector<int>> adj; 
    int n, m = 0, s, t, qh, qt;
    void resize(int _n) {
        n = _n;
        ex.resize(n);
        q.resize(n);
        Pin.resize(n);
        Pout.resize(n);
        adj.resize(n);
        lvl.resize(n);
        in.resize(n);
        out.resize(n);
    }

    MPM() {}
    MPM(int _n, int _s, int _t) { s = _s; t = _t; resize(_n); }
    
    void add_edge(int from, int to, int cap) {
        edges.push_back(FlowEdge(from, to, cap));
        edges.push_back(FlowEdge(to, from, 0));
        adj[from].push_back(m++);
        adj[to].push_back(m++);
    }

    bool bfs() {
        while(qh < qt) {
            int v = q[qh++];
            for(int id : adj[v]) {
                if(edges[id].cap <= edges[id].flow) continue;
                if(lvl[edges[id].u] != -1) continue;
                lvl[edges[id].u] = lvl[v] + 1;
                q[qt++] = edges[id].u;
            }
        }
        return lvl[t] != -1;
    }

    int potential(int v) {
        return min(Pin[v], Pout[v]);
    }

    void remove_node(int v) {
        for(int i : in[v]) {
            int u = edges[i].v;
            auto it = find(out[u].begin(), out[u].end(), i);
            out[u].erase(it);
            Pout[u] -= (edges[i].cap - edges[i].flow);
        }
        for(int i : out[v]) {
            int u = edges[i].u;
            auto it = find(in[u].begin(), in[u].end(), i);
            in[u].erase(it);
            Pin[u] -= (edges[i].cap - edges[i].flow);
        }
    }

    void push(int from, int to, int f, int isForward) {
        qh = qt = 0;
        ex.assign(n, 0);
        ex[from] = f;
        q[qt++] = from;
        while(qh < qt) {
            int v = q[qh++];
            if(v == to) break;
            int must = ex[v];
            auto it = isForward ? out[v].begin() : in[v].begin();
            while(true) {
                int u = isForward ? edges[*it].u : edges[*it].v;
                int pushed = min(must, edges[*it].cap - edges[*it].flow);
                if(!pushed) break;
                if(isForward) { Pout[v] -= pushed; Pin[u] -= pushed; }
                else { Pin[v] -= pushed; Pout[u] -= pushed; }
                if(!ex[u]) q[qt++] = u;
                ex[u] += pushed;
                edges[*it].flow += pushed;
                edges[(*it)^1].flow -= pushed;
                must -= pushed;
                if(edges[*it].cap == edges[*it].flow) {
                    auto jt = it;
                    jt++;
                    if(isForward) {
                        auto kt = find(in[u].begin(), in[u].end(), *it);
                        A.push_back({u, edges[*kt].v});
                        in[u].erase(kt);
                        out[v].erase(it);
                    }
                    else {
                        out[u].erase(find(out[u].begin(), out[u].end(), *it));
                        in[v].erase(it);
                    }
                    it = jt;
                }
                else break;
                if(!must) break;
            }
        }
    }

    int get_maxflow() {
        int ans = 0;
        while(true) {
            Pin.assign(n, 0);
            Pout.assign(n, 0);
            lvl.assign(n, -1);
            alive.assign(n, true);
            lvl[s] = 0;
            qh = 0, qt = 1;
            q[0] = s;
            if(!bfs()) break;
            for(int i=0; i<n; i++) {
                out[i].clear();
                in[i].clear();
            }
            for(int i=0; i<m; i++) {
                if(edges[i].cap == edges[i].flow) continue;
                int v = edges[i].v, u = edges[i].u;
                if(lvl[u] == lvl[v] + 1 && (lvl[u] < lvl[t] || u == t)) {
                    in[u].push_back(i);
                    out[v].push_back(i);
                    Pin[u] += edges[i].cap - edges[i].flow;
                    Pout[v] += edges[i].cap - edges[i].flow;
                }
            }
            Pin[s] = Pout[t] = flow_inf;
            while(true) {
                int v = -1;
                for(int i=0; i<n; i++) {
                    if(!alive[i]) continue;
                    if(v == -1 || potential(i) < potential(v)) v = i;
                }
                if(v == -1) break;
                    
                if(potential(v)) {
                    int f = potential(v);
                    ans += f;

                    push(v, s, f, false);
                    push(v, t, f, true);
                }
                
                alive[v] = false;
                remove_node(v);
            }
        }
        return ans;
    }
};

int n, m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    MPM G(n, 0, n-1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.add_edge(a, b, 1);
    }
    cout<<G.get_maxflow()<<endl;
    for(auto it : A) {
        cout<<it.first<<" "<<it.second<<"\n";
    }
}

// 