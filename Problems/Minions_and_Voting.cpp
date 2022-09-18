#include <bits/stdc++.h>
using namespace std;
void add(vector<int> &ans, int x, int y) {
    ans[x]++;
    ans[y+1]--;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n+1);
        for(int i=1; i<=n; i++) cin >> A[i];

        vector<int> p(n+1, 0), s(n+2, 0);
        for(int i=1; i<=n; i++) p[i] = p[i-1] + A[i];
        for(int i=n; i>0; i--) s[i] = s[i+1] + A[i];
        reverse(s.begin(), s.end());
        s.pop_back();

        vector<int> ans(n+2, 0);

        // n-i+1
        for(int i=2; i<n; i++) {
            int a = upper_bound(p.begin()+i+1, --p.end(), p[i]+A[i]) - p.begin() - i;
            int b = upper_bound(s.begin()+n-i+2, --s.end(), s[n-i+1]+A[i]) - s.begin() - (n-i+1);
            add(ans, i+1, i+a);
            add(ans, i-b, i-1);
        }
        int a = upper_bound(p.begin()+2, --p.end(), p[1]+A[1]) - p.begin() - 1;
        add(ans, 2, a+1);
        int b = upper_bound(s.begin()+2, --s.end(), s[1]+A[n]) - s.begin() - 1;
        add(ans, n-b, n-1);

        for(int i=1; i<=n; i++) ans[i] += ans[i-1];

        for(int i=0; i<n; i++) cout<<ans[i+1]<<" ";
        cout<<endl;
    }
}