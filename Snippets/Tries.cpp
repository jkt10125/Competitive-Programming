#include <bits/stdc++.h>

class trie {
    public:
    char data;
    int end, string_flow_count;
    trie *child[26];
    
    
    trie(char Data = '?') {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        data = Data;
        end = string_flow_count = 0;
    }

    void insert(std::string s, int ptr) {
        string_flow_count++;
        if (ptr == s.size()) {
            end++;
            return;
        }
        int c = s[ptr] - 'a';
        if (child[c] == nullptr) {
            void *memory = malloc(sizeof(trie));
            child[c] = new (memory) trie(s[ptr]);
        }
        child[c]->insert(s, ++ptr);
    }

    bool erase(std::string s, int ptr) {
        if (ptr == s.size()) {
            if (end) { end--; return true; }
            else { return false; }
        }
        int c = s[ptr] - 'a';
        
        if (child[c] == nullptr) { return false; }
        
        bool res = child[c]->erase(s, ++ptr);
        if (res) { string_flow_count--; }

        if (!child[c]->string_flow_count) {
            delete child[c];
            child[c] = nullptr;
        }

        return res;
    }

    int search(std::string s, int ptr) {
        if (ptr == s.size()) {
            return end;
        }
        int c = s[ptr] - 'a';
        if (child[c] == nullptr) { return 0; }
        return child[c]->search(s, ++ptr);
    }
};

int main() {
    int n;
    std::cin >> n;
    trie t;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        t.insert(s, 0);
    }

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        t.erase(s, 0);
    }

    std::string tt;
    std::cin >> tt;

    std::cout << t.search(tt, 0) << std::endl;
    // if (t.child[1] == nullptr) {
    //     std::cerr << "INVALID" << std::endl;
    // }
    std::cout << t.string_flow_count;
    for (int i = 0; i < 26; i++) {
        if (t.child[i] != nullptr) {
            std::cerr << i << std::endl;
        }
    }

}