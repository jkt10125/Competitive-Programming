#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        if(x != 0 && y != 0) cout<<-1<<endl;
        else {
            if(x == 0 && y == 0) cout<<-1<<endl;
            else {
                x = x + y;
                if((n-1) % x != 0) cout<<-1<<endl;
                else {
                    int a = (n-1) / x;
                    int ctr = 1;
                    for(int i=0; i<a; i++) {
                        for(int j=0; j<x; j++) cout<<ctr<<" ";
                        if(!i) ctr = x+2;
                        else ctr += x;
                    }
                    cout<<endl;
                }
            }
        }
    }
}