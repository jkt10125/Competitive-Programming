#include <iostream>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    int ans = -1;
    for(int i=1; i<32; i++) {
        int a = n - i * p;
        if(a >= i && i >= __builtin_popcount(a)) { ans = i; break; }
    }
    cout<<ans;
}