#include <bits/stdc++.h>
using namespace std;

int main() {
    string S[] = {" ", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    string s;
    cin >> s;
    int ctr = 0;
    for(int i=5; i>0; i--) {
        ctr++;
        if(S[i] == s) break;
    }

    cout<<ctr;
}