#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

int main() {
    int t;
    cin >> t;
    for(int _i=1; _i<=t; _i++) {
        cout << "Case #" << _i << ": ";
        ll n, x, y;
        cin >> n >> x >> y;
        ll sum = n * (n+1) / 2;
        if(sum % (x+y)) {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        
        ll k = sum / (x+y);
        x = x*k;
        y = y*k;
        
        ll num = n;
        vll ans;
        while(x >= num) {
            ans.push_back(num);
            x = x - num;
            num--;
        }
        if(x) ans.push_back(x);
        
        cout<<"POSSIBLE\n";
        cout<<ans.size()<<"\n";
        for(ll it : ans) cout<<it<<" ";
        cout<<endl;
    }
}