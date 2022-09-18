#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    // reverse(A.begin(), A.end());

    vector<int> ans(n+1, -1);
    if(k == 1) {
        for(int i=0; i<n; i++) ans[A[i]] = i+1;
    }
    else {
        set<pair<int, int>> s; // {stack.top, stack_number}

        vector<stack<int>> st;
        for(int i=0; i<n; i++) {
            auto it = s.lower_bound({A[i], -1});
            if(it == s.end()) {
                stack<int> tmp;
                tmp.push(A[i]);
                st.push_back(tmp);
                s.insert({A[i], st.size()-1});
            }
            else {
                int idx = it->second;
                st[idx].push(A[i]);
                s.erase(it);
                s.insert({A[i], idx});
                if(st[idx].size() == k) {
                    while(!st[idx].empty()) {
                        ans[st[idx].top()] = i+1;
                        st[idx].pop();
                    }
                    s.erase({A[i], idx});
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout<<ans[i]<<endl;
    }
}