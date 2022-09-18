#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int> A, pair<char, int> B) {
    if(A.first == B.first) return A.second > B.second;
    return A.first < B.first;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<pair<char, int>> A;
        if(s.front() > s.back()) {
            for(int i=1; i<n-1; i++) {
                if(s[i] <= s.front() && s[i] >= s.back()) {
                    A.push_back({s[i], i});
                }
            }
            sort(A.begin(), A.end(), cmp);
            cout<<s.front()-s.back()<<" "<<A.size()+2<<endl;
            cout<<1<<" ";
            for(int i=A.size()-1; i>=0; i--) {
                cout<<A[i].second+1<<" ";
            }
            cout<<n;
            cout<<endl;
        }
        else {
            for(int i=1; i<n-1; i++) {
                if(s[i] >= s.front() && s[i] <= s.back()) {
                    A.push_back({s[i], i});
                }
            }
            sort(A.begin(), A.end(),cmp);
            cout<<s.back()-s.front()<<" "<<A.size()+2<<endl;
            cout<<1<<" ";
            for(int i=0; i<(int)A.size(); i++) {
                cout<<A[i].second+1<<" ";
            }
            cout<<n;
            cout<<endl;
        }
    }
}