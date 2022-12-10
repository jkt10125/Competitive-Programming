#include <bits/stdc++.h>
using namespace std;

const int K = 26;

struct Vertex {
	int next[K], go[K];
	int p, link;
	char pch;
	bool leaf;

	Vertex (int p = -1, char ch = '$') : p(p), pch(ch) {
		fill (go, go + K, -1);
		fill (next, next + K, -1);
		leaf = false;
		link = -1;
	}
};

class Trie {
	vector<Vertex> trie;
	public:
	Trie() {
		trie.resize(1);
	}

	void addString (string &s) {
		int v = 0;
		for (char c : s) {
			int i = c - 'a';
			if (trie[v].next[i] == -1) {
				trie[v].next[i] = trie.size();
				trie.emplace_back(v, c);
			}
			v = trie[v].next[i];
		}
		trie[v].leaf = true;
	}

	int getLink (int v) {
		if (trie[v].link == -1) {
			if (v == 0 || trie[v].p == 0) {
				trie[v].link = 0;
			}
			else {
				trie[v].link = go(getLink(trie[v].p), trie[v].pch);
			}
		}
		return trie[v].link;
	}

	int go (int v, char ch) {
		int i = ch - 'a';
		if (trie[v].go[i] == -1) {
			if (trie[v].next[i] != -1) {
				trie[v].go[i] = trie[v].next[i];
			}
			else {
				trie[v].go[i] = (v == 0) ? 0 : go (getLink (v), ch);
			}
		}
		return trie[v].go[i];
	}

	int countOccurence (string &s) {
		int v = 0;
		
	}
};

