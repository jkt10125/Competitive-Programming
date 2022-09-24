#include <iostream>
#include <algorithm>
using namespace std;

struct dat {
    int x, i;
};

bool cmp(dat A, dat B) {
    return A.x < B.x;
}

int main() {
    int n, x;
    cin >> n >> x;
    dat A[n];
    for(int i=0; i<n; i++) {
        cin >> A[i].x;
        A[i].i = i;
    }
    sort(A, A+n, cmp);
    int p1=0, p2=n-1;
    while(p1<p2) {
        if(x == A[p1].x + A[p2].x) break;
        if(x > A[p1].x + A[p2].x) p1++;
        else p2--;
    }
    if(p1 == p2) cout<<"IMPOSSIBLE";
    else cout<<A[p1].i+1<<" "<<A[p2].i+1;
}