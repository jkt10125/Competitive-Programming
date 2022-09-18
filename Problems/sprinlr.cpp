#include <bits/stdc++.h>
using namespace std;

struct node{
    node* links[26];
    int tf;
    node(){
        for(int i=0; i<26; i++) links[i] = NULL;
        tf = 0;
    }
};
class trie{
    node* root;
public:
    trie(){
        root = new node();
    }
    void insert(string &s, int f){
        node* curr = root;
        for(auto c: s){
            if(curr->links[c-'a'] == NULL) curr->links[c-'a'] = new node();
            curr = curr->links[c-'a'];
            curr->tf+=f;
        }
    }
    void update(string &s, int f){
        node* curr = root;
        for(auto c: s){
            curr = curr->links[c-'a'];
        }
        curr->tf = f;
    }
    int query(string &s){
        node* curr = root;
        for(auto c: s){
            curr = curr->links[c-'a'];
        }
        return curr->tf;
    }
};
int main(){
    int n;
    cin >> n;
    trie t;
    while(n--){
        char q;
        cin >> q;
        if(q == 'I'){
            string s;
            int f;
            cin >> s >> f;
            t.insert(s, f);
        }else if(q == 'Q'){
            string s;
            cin >> s;
            cout<<t.query(s)<<endl;
        }else{
            string s;
            int f;
            cin >> s >> f;
            t.update(s, f);
        }
    }
}