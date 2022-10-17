#include <bits/stdc++.h>
using namespace std;

vector<int> rand(int n) {
    vector<int> A(n);
    for(int i=0; i<n; i++) A[i] = i + 1;
    srand(time(NULL));
    while(n) {
        int idx = rand() % n;
        swap(A[idx], A[n-1]);
        n--;
    }
    return A;
}

signed main(int argc, char *argv[]) {
    srand(time(NULL));
    
    int n = atoi(argv[1]);

    vector<int> A = rand(n);
    for(auto it : A) cout << it << " ";
    cout<<endl;
    return 0;
}