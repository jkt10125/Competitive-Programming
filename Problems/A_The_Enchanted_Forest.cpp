#include <bits/stdc++.h>
using namespace std;

int f(vector<int> A, int idx, int k, bool isright) {
    int sum = 0;
    if(isright) {
        for(int i=0; i<k; i++) {
            if(idx + i == A.size()) {
                sum += f(A, A.size()-1, k-i+1, 0);
                sum -= A.back();
                break;
            }
            sum += A[idx + i];
            A[idx + i] = 0;
        }
        return sum;
    }
    else {
        for(int i=0; i<k; i++) {
            if(idx - i == -1) {
                sum += f(A, 0, k-i+1, 1);
                sum -= A.front();
                break;
            }
            sum += A[idx - i];
            A[idx - i] = 0;
        }
        return sum;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        int idx = max_element(A.begin(), A.end()) - A.begin();

        cerr << f(A, idx, 7, 1) <<endl;
    }
}