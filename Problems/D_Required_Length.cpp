#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long

vi digit(ll n) {
    vi A;
    while(n) {
        A.push_back(n%10);
        n /= 10;
    }
    return A;
}

set<ll> exceptions;

int main() {
    ll n, x;
    cin >> n >> x;
    if(log10(x) == n) {
        cout<<"0"<<endl;
        return 0;
    }

    

    while(log10(x) != n) {
        vi A = digit(x);
        if(*max_element(A.begin(), A.end()) <= 1) {
            cout<<"-1\n";
            return 0;
        }

         
    }
}