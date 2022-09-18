#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a%3 == 0 || b%3 == 0) {
            cout<<"0\n";
            continue;
        }
        if(a == b) {
            cout<<"1\n";
            continue;
        }
        cout<<"2\n";
    }
}