#include <bits/stdc++.h>
using namespace std;

int n, x;

void OR(int a, int b) {
    cout<<"1 "<<a<<" "<<b<<"\n";
    n--;
}

void XOR(int a, int b) {
    cout<<"2 "<<a<<" "<<b<<"\n";
    n--;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        if(n == 2) {
            if(x == 3) cout<<"2 1 2\n";
            else cout<<"-1\n";
            continue;
        }
        int msb_n, msb_x;
        for(int i=0; i<17; i++) {
            if(n & (1 << i)) msb_n = i;
            if(x & (1 << i)) msb_x = i;
        }

        if(msb_n < msb_x) {
            cout<<"-1\n";
            continue;
        }

        if(msb_n > msb_x && (n == (1 << msb_n))) {
            cout<<"-1\n";
            continue;
        }

        if(n > 4) {
            int a = n;
            int ctr = 1;
            
            if(n & (n-1)) {
                for(int i=1; i<a; i++) {
                    if(i & (i-1)) OR(ctr, n);
                    else ctr++;
                }
            }
            else {
                ctr = 3;
                OR(ctr, n-1);
                for(int i=4; i<a; i++) {
                    if(i & (i-1)) OR(ctr, n);
                    else ctr++;
                }
            }
        }

        while(n != 1) {
            if(x & 1) OR(1, n);
            else XOR(1, n);
            x >>= 1;
        }

        assert(n == 1);
    }
}