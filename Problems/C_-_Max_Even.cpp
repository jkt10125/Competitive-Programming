#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> o, e;
    while(n--) {
        int x;
        cin >> x;
        if(x & 1) o.push_back(x);
        else e.push_back(x);
    }

    sort(o.begin(), o.end());
    sort(e.begin(), e.end());

    int ans;
    int m = o.size();
    n = e.size();
    if(m > 1) {
        if(n > 1) {
            ans = max(o[m-1]+o[m-2], e[n-1]+e[n-2]);
        }
        else ans = o[m-1]+o[m-2];
    }
    else {
        if(n > 1) ans = e[n-1]+e[n-2];
        else ans = -1;
    }

    cout<<ans;
}