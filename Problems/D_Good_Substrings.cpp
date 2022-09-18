#include <bits/stdc++.h>
using namespace std;
string s, t;
set<string> S;
int k;

bool check(string ss) {
    int ctr = 0;
    for(char c : ss) {
        if(t[c-'a'] == '0') ctr++;
    }
    return ctr <= k;
}

int main() {
    cin >> s >> t >> k;
    for(int len=1; len<=(int)s.size(); len++) {
        for(int i=0; i<(int)s.size()-len+1; i++) {
            if(check(s.substr(i, len))) S.insert(s.substr(i, len));
        }
    }
    cout<<S.size();
}