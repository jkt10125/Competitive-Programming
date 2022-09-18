#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s[0] == '1') cout<<"No";
    else {
        int col[8] = {0};
        col[1] = s[6]-'0';
        col[2] = s[3] - '0';
        col[3] = s[1] - '0' + s[7] - '0';
        col[4] = s[4] - '0';
        col[5]
    }
}