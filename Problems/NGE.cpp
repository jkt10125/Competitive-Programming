#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    vector<int> st, ans(n);
    for(int i=0; i<n; i++) {
        while(st.size() != 0) {
            if(A[st.back()] >= A[i]) break;
            ans[st.back()] = A[i];
            st.pop_back();
        }
        st.push_back(i);
    }

    while(st.size() != 0) ans[st.back()] = -1, st.pop_back();
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
}