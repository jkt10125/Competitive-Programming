#include <bits/stdc++.h>
using namespace std;

// function to print the partition of an array according to the given indexes
void print(vector<int> A, int n) {
    cout<<"1 "<<A[1]<<"\n";
    for(int i=2; i<A.size(); i++) {
        cout<<A[i-1]+1<<" "<<A[i]<<"\n";
    }
    cout<<A.back()+1<<" "<<n<<"\n";
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    print(A, 8);
}