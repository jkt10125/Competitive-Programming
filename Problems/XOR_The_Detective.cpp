#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
    int a;
    cout<<"? "<<x<<endl;
    cin>>a;
    return a;
}

int main() {
    int query[7];
    for(int i=0; i<7; i++) {
        query[i] = ask((1 << i));
    }
    int a_xor_b = query[0];

    int a[7], b[7];
    for(int i=6; i>=0; i--) {
        if(query[i] == a_xor_b) a[i] = b[i] = -1;
        else {
            if(query[i] == 1) {
                b[i] = 1;
                a[i] = 0;
            }
            else 
        }
    }
    
}