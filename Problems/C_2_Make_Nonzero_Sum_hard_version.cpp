#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int ctr = 0;
        for(int i : A) {
            if(i == 1 || i == -1) ctr++;
        }

        if(ctr & 1) cout << -1 << endl;
        else {
            vector<pair<int, int>> v;
            int sum = 0;
            for(int i=0; i<n; i++) {
                if(!sum) {
                    v.push_back({i, i});
                    sum = A[i];
                }
                else {
                    int j = i;
                    while(j < n && !A[j]) j++;
                    
                    if(A[j] == sum) {
                        if(j == i) v.back().second++;
                        else if((j - i) & 1) v.push_back({i, j});
                        else {
                            v.push_back({i, j-2});
                            v.push_back({j-1, j});
                        }
                    }
                    else {
                        if(j == i) v.push_back({i, i});
                        else if((j - i) & 1) {
                            v.push_back({i, j-1});
                            v.push_back({j, j});
                        }
                        else v.push_back({i, j});
                    }
                    sum = 0;
                    i = j;
                }
            }

            cout << v.size() << endl;
            for(auto p : v) cout << p.first + 1 << ' ' << p.second + 1 << endl;
        }
    }
}