#include <bits/stdc++.h>
using namespace std;
int main() {
    string str = "atcoder";
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout<<str.substr(l, r-l+1);
}