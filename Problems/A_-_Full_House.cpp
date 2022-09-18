#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> A;
    for(int i=0; i<5; i++) {
        int x;
        cin >> x;
        A[x]++;
    }

    if(A.size() == 2) {
        int f = false;
        for(auto it : A) {
            if(it.second == 2) f = true;
        }
        if(f) cout<<"Yes";
        else cout<<"No";
    }
    else cout<<"No";

}