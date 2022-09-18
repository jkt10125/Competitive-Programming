#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> A;
    for(char c: s) A[c]++;
    char ans = '?';
    for(auto it : A) {
        if(it.second == 1) ans = it.first;
    }
    if(ans == '?') cout<<"-1";
    else cout<<ans;
}