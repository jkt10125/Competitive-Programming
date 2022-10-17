#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    reverse(s.begin(), s.end());
    while(s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    n = s.size();

    if(s.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int ctr = 0;
    while(ctr < n) {
        if(s[ctr] == '0') break;
        ctr++;
    }

    if(ctr >= ((n + 1) >> 1)) {
        while(n--) cout<<1;
        cout<<endl;
    }

    else {
        int a = ctr;
        while(ctr < n) {
            if(s[ctr] == '1') break;
            ctr++;
        }

        int b = ctr - a;
        ctr = a;
        // ctr = min(b, ctr);

        string ss = s;
        for(int i=0; i<ctr; i++) ss.pop_back();
        reverse(ss.begin(), ss.end());
        while(ctr--) ss.push_back('0');
        reverse(ss.begin(), ss.end());

        for(int i=0; i<n; i++) {
            if(s[i] == '1' || ss[i] == '1') ss[i] = '1';
            else ss[i] = '0';
        }

        ctr = b;

        string sss = s;
        for(int i=0; i<ctr; i++) sss.pop_back();
        reverse(sss.begin(), sss.end());
        while(ctr--) sss.push_back('0');
        reverse(sss.begin(), sss.end());

        for(int i=0; i<n; i++) {
            if(s[i] == '1' || sss[i] == '1') sss[i] = '1';
            else sss[i] = '0';
        }
        // cerr<<ss<<"\n"<<sss<<"\n\n";
        cout<<max(ss, sss);
        cout<<endl;
    }
}