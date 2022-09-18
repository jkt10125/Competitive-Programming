#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> A;

void f(int x) {
    if(x > m) return;
    if(A.size() == n) {
        for(auto it : A) cout<<it<<" ";
        cout<<endl;
        return;
    }

    for(int i=x; i<=m; i++) {
        A.push_back(i);
        f(i+1);
        A.pop_back();
    }
}

int main() {
    cin >> n >> m;
    m++;
    f(1);
}