#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> A(9);
        vector<int> B;
        B = {2, 4, 1, 3};
        A[4] = B;
        B = {2, 4, 1, 3, 5};
        A[5] = B;
        B = {2, 4, 1, 5, 3, 6};
        A[6] = B;
        B = {2, 4, 1, 5, 7, 3, 6};
        A[7] = B;

        if(n < 4) cout<<-1;
        else {
            int a = 4 + n % 4;
            for(int i=0; i<n-a; i+=4) {
                for(auto it : A[4]) cout<<it+i<<" ";
            }
            for(auto it : A[a]) cout<<it+n-a<<" ";
        }
        cout<<endl;
    }
}