#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class Trie {
	Trie *child[ALPHABET_SIZE];
	int terminating_number;
	public:
	Trie() {
		for(int i=0; i<ALPHABET_SIZE; i++) {
			child[i] = nullptr;
		}
		terminating_number = 0;
	}
	
	bool empty() {
		for(int i=0; i<ALPHABET_SIZE; i++) {
			if(child[i] != nullptr) return false;
		}
		return true;
	}

	void insert(string key) {
		Trie *A = this;
		for(char c : key) {
			int idx = c - 'a';
			if(A->child[idx] == nullptr) {
				A->child[idx] = new Trie;
			}
			A = A->child[idx];
		}
		A->terminating_number++;
	}

	void del(string key, int depth=0) {
		Trie *A = this;
		if(depth == key.size()) {
			if(A->terminating_number) A->terminating_number--;
			if(A->empty()) {
				delete A;
				A = nullptr;
			}
		}
		int idx = key[depth] - 'a';
		A->child[idx]->del(key, depth+1);
		if(A->empty() && !A->terminating_number) {
			delete A;
			A = nullptr;
		}
	}

	bool search(string key) {
		Trie *A = this;
		for(char c : key) {
			int idx = c - 'a';
			if(A->child[idx] == nullptr) return false;
			A = A->child[idx];
		}
		if(A->terminating_number) return true;
		return false;
	}
};

int main() {
	vector<string> A = {"hi", "hello", "jkt", "jay", "kumar", "thakur"};
	Trie T;
	for(string s : A) T.insert(s);
	if(T.search("ja")) cout<<"YES";
	else cout<<"No";
	return 0;
}