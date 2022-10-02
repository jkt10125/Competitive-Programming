#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n / 16;
    int b = n % 16;
    if(a > 9) cout<<char('A'+a-10);
    else cout<<a;
    if(b > 9) cout<<char('A'+b-10);
    else cout<<b;
}