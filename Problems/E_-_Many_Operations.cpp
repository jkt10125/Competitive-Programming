#include <iostream>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int X = c;
    for(int i=0; i<n; i++) {
        int t, o;
        cin >> t >> o;
        if(t == 1) {
            X = X & o;
            cout<<X;
        }
        if(t == 2) {
            X = X | o;
            cout<<X;
        }
        if(t == 3) {
            cout<<(X^o);
        }
        cout<<endl;
    }
}