#include <bits/stdc++.h>
using namespace std;

int MaxZeroMatrixArea(vector<vector<int>> A) {
    int n = A.size(), m = A[0].size();
    int ans = 0;
    vector<int> d(m, -1), d1(m), d2(m), st;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(A[i][j]) d[j] = i;
        }
        for(int j=0; j<m; j++) {
            while(!st.empty() && d[st.back()] <= d[j]) st.pop_back();
            d1[j] = st.empty() ? -1 : st.back();
            st.push_back(j);
        }
        st.clear();
        for(int j=m-1; j>=0; j--) {
            while(!st.empty() && d[st.back()] <= d[j]) st.pop_back();
            d2[j] = st.empty() ? m : st.back();
            st.push_back(j);
        }
        st.clear();
        for(int j=0; j<m; j++) {
            ans = max(ans, (i-d[j]) * (d2[j] - d1[j] - 1));
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int> (m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> A[i][j];
        }
    }
    cout<<MaxZeroMatrixArea(A);
}