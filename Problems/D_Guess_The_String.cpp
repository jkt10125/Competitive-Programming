#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
    int a;
    cout<<"? 2 "<<l+1<<" "<<r+1<<endl;
    cin >> a;
    return a;
}

char ask(int i) {
    char a;
    cout<<"? 1 "<<i+1<<endl;
    cin >> a;
    return a;
}

int main() {
    int t=1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<char> A(n, '?');
        vector<int> hsh(26, -1);
        int min_bound = 0;
        for(int i=0; i<n; i++) {
            int j = i, ctr = 1;
            while(j > min_bound) {
                j = hsh[A[j-1]-'a'];
                int a = ask(j, i);
                if(a == ctr) {
                    A[i] = A[j];
                    break;
                }
                assert(a == ctr+1);
                ctr++;
            }
            if(A[i] == '?') {
                A[i] = ask(i);
            }
            hsh[A[i]-'a'] = i;
            for(int i=0; i<26; i++) {
                if(hsh[i] == -1) continue;
                min_bound = min(min_bound, hsh[i]); 
            }
        }
        cout<<"! ";
        for(char it : A) cout<<it;
        cout<<endl;
    } 
}