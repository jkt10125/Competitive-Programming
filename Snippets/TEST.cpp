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

vector<Vertex> trie(1, Vertex (0, '$'));

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

void calcLink () {
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

int getLink (int v) {
    if (trie[v].link == -1) {
        int u = trie[v].par;
        int c = trie[v].ch - 'a';
        if (u == 0) {
            trie[v].link = 0;
        }
        else {
            u = getLink (u);
            while (trie[u].next[c] == -1 && u) {
                u = getLink (u);
            }
            trie[v].link = trie[u].next[c];
            if (trie[v].link == -1) {
                trie[v].link = 0;
            }
        }
    }
    return trie[v].link;
}

int getOutLink (int v) {
    if (!v) return trie[v].out;
    if (trie[v].out == -1) {
        int u = getLink (v);
        trie[v].out = (trie[u].leaf) ? u : getOutLink (u);
    }
    return trie[v].out;
}

int countMatches (string &s) {
    int ctr = 0;
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            while (trie[v].next[c] == -1 && v) {
                v = getLink (v);
                if (trie[v].leaf) ctr++;
            }
            if (!v) continue;
        }
        v = trie[v].next[c];
        if (trie[v].leaf) ctr++;
    }
    return ctr;
}

void print() {
    // for (int i = 0; i < trie.size(); i++) {
    //     cout << trie[i].ch << ' ' << i << endl;
    // }

    for (int i = 0; i < trie.size(); i++) {
        cout << trie[i].out << ' ' << trie[i].link << ' ' << trie[i].ch << ' ' << i << endl;
    }
}

int main() {
    string s, t;
    cin >> s;
    addString(s);
    cin >> s;
    addString(s);
    cin >> s;
    addString(s);
    cin >> s;
    addString(s);
    for(int i = 0; i < trie.size() ; i++) {
        // getLink(i);
        getOutLink(i);
        // calcLink();
    }
    // getLink(trie.size()-1);
    // cin >> t;
    // cout << countMatches(t);
    print();
    // cerr << trie[5].par << ' ' << trie[9].link;
    // cerr << trie[9].ch;
}