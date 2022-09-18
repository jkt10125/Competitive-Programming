#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) cout<<"2\n";
        else {
            cout<<(n-1)/3 + 1<<endl;
        }
    }
}