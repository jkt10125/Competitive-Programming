#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, x;
        cin >> n >> k;
        map<int, int> A;
        for(int i=0; i<n; i++) {
            cin >> x;
            A[x]++;
        }
        int l, r, al, ar;
        l = r = al = ar = -1;

        for(auto it : A) {
            if(A[it-1] )
            if(it.second >= k) {
                if(l == -1) {
                    l = r = it.first;
                }
                else {
                    r = it.first;
                }
            }
            else {
                if(al != -1) {
                    if(ar - al < r - l) {
                        al = l; ar = r;
                    }
                }
                else {
                    al = l;
                    ar = r;
                }
                l = r = -1;
            }
        }

        if(al != -1) {
            if(ar - al < r - l) {
                al = l; ar = r;
            }
        }
        else {
            al = l;
            ar = r;
        }

        cout<<al<<" "<<ar<<endl;
    }
}