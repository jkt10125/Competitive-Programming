#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int A[n+1];
    A[0] = 0;
    for(int i=1; i<=n; i++) cin >> A[i];
    for(int i=1; i<=n; i++) A[i] = A[i] ^ A[i-1];
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (A[b] ^ A[--a]) << endl;
    }
}