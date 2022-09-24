#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> A, pair<int, int> B) {
    if(A.second == B.second) return A.first > B.first;
    return A.second < B.second;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for(int i=0; i<n; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end(), cmp);
    int x = A[0].second;
    int ctr = 1;
    for(int i=1; i<n; i++) {
        if(A[i].first >= x) {
            ctr++;
            x = A[i].second;
        }
    }

    cout<<ctr;
}