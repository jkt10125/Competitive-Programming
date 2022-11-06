#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << 1 << ' ';
        n--;
        while(n--) {
            cout << n + 2 << " ";
        }
        cout<<endl;
    }
}