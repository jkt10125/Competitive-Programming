#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    array<int, 26> next;
    char ch;
    int par;
    int out = -1;
    int link = -1;
    bool leaf = false;
    Vertex(int p, char c) : par(p), ch(c) {
        fill (next.begin(), next.end(), -1);
    }
};

class Trie {
    vector<Vertex> trie;
    vector<int> vis;
    public:
    Trie () {
        trie.emplace_back(Vertex(0, '$'));
        vis.resize(1e5 + 7);
    }

    void addString (string &s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back (Vertex(v, ch));
            }
            v = trie[v].next[c];
        }
        trie[v].leaf = true;
    }

    void updateLinks () {
        int n = trie.size();
        for (int i = 1; i < n; i++) {
            int u = trie[i].par;
            int c = trie[i].ch - 'a';
            if (u == 0) {
                trie[i].link = 0;
            }
            else {
                u = trie[u].link;
                while (trie[u].next[c] == -1 && u) {
                    u = trie[u].link;
                }
                trie[i].link = trie[u].next[c];
                if (trie[i].link == -1) {
                    trie[i].link = 0;
                }
            }
            u = trie[i].link;
            trie[i].out = (trie[u].leaf) ? u : trie[u].out;
        }    
    }

    vector<int> countMatches (string &t) {
        vector<int> Match;
        int v = 0;
        for (char ch : t) {
            int c = ch - 'a';
            if (trie[v].next[c] != -1) {
                v = trie[v].next[c];
            }
            else if (!v) continue; 
            else {
                if (trie[v].link) {
                    v = trie[v].link;
                }
            }
            if (trie[v].leaf) {
                if (!vis[v]) {
                    Match.push_back(v);
                    vis[v] = true;
                }
                else continue;
            }
            int u = v;
            while (trie[u].out != -1) {
                u = trie[u].out;
                if (!vis[u]) {
                    Match.push_back(u);
                    vis[u] = true;
                }
                else break;
            }
        }
        for (int i : Match) vis[i] = false;
        return Match;
    }

    string retrieveString (int v) {
        string s;
        while (v) {
            s.push_back(trie[v].ch);
            v = trie[v].par;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    void print() {
        for (int i = 0; i < trie.size(); i++) {
            cerr << trie[i].leaf << ' ' << trie[i].out << ' ' << trie[i].link << ' ' << trie[i].ch << ' ' << i << endl;
        }
    }

};

int main() {
    int n;
    string s;
    cin >> n;
    Trie t;
    while (n--) {
        cin >> s;
        t.addString(s);
    }
    t.updateLinks();
    t.print();
    cin >> s;
    for (int i : t.countMatches(s)) {
        cout << t.retrieveString(i) << '\n';
    }
}