#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        vector<int> A(t);
        for(int i=0; i<t; i++) cin >> A[i];
        int e=0, o=0;
    // st.print();
        for(int i=0; i<t; i++) {
            if(A[i] & 1) o++;
            else e++;
        }
        cout<<min(o, e)<<endl;
    }
}