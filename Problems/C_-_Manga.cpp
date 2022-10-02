#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    sort(A.begin(), A.end());
    int temp = 0;
    int curr = 1;
    for(int i=0; i<A.size(); i++) {
        if(A[i] < curr) temp++;
        else if(A[i] > curr) {
            if(A.size()-i + temp < 2) break;
            else {
                if(temp == 0) {
                    A.pop_back();
                    A.pop_back();
                }
                else if(temp == 1) {
                    A.pop_back();
                    temp = 0;
                }
                else temp -= 2;
                curr++;
                i--;
            }
        }
        else curr++;
    }
    curr += temp/2;
    cout<<curr-1;
}