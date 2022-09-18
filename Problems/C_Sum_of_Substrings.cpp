#include <bits/stdc++.h>
using namespace std;

int convert(char a, char b) {
    return (a-'0')*10 + (b-'0');
}

long long F(string s) {
    long long ans = 0;
    for(int i=0; i<s.size()-1; i++) {
        ans += convert(s[i], s[i+1]);
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if(k == 0) {cout << F(s); return;}

    int ctr = 0;
    for(auto it : s) if(it == '1') ctr++;

    if(!ctr) {cout << 0; return;}
    
    int f = 0, b = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '0') f++;
        else break;
    }

    for(int i=n-1; i>=0; i--) {
        if(s[i] == '0') b++;
        else break;
    }

    if(ctr > 1) {
        if(k >= b) {
            swap(s[n-1], s[n-1-b]);
            k-=b;
        }
        
        if(k >= f) {
            swap(s[0], s[f]);
            k-=f;
        }
    }

    else {
        if(k >= b) {
            swap(s[n-1], s[n-1-b]);
            k-=b;
        }
        
        if(k >= f && s.back() == '0') {
            swap(s[0], s[f]);
            k-=f;
        }
    }
    cout << F(s);
    cerr << s<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout <<"\n";
    }
}