#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> A, pair<int, int> B) {
    if(A.first == B.first) return A.second > B.second;
    return A.first < B.first;
}

int solve(int n, int A[], int D[]) {
    int N = 0;
    for(int i=0; i<n; i++) N = max(N, D[i]);
    int profit[N+1] = {0};
    pair<int, int> arr[n];
    for(int i=0; i<n; i++) {
        arr[i] = {D[i], A[i]};
    }
    sort(arr, arr+n);
    int ctr = N, aa = N;
    for(int i=n-1; i>=0; i--) {
        ctr = min(ctr, arr[i].first);
        if(aa != arr[i].first) {
            aa = arr[i].first;
            ctr = aa;
        } 
        if(!ctr) break;
        profit[ctr] = arr[i].second;
        ctr--;
    }
    int sum = 0;
    for(int i=0; i<=N; i++) sum += profit[i];
    return sum;
}

int main() {
    int n;
    cin >> n;
    int A[n], D[n];
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n; i++) cin >> D[i];

    cout<<solve(n, A, D);
}