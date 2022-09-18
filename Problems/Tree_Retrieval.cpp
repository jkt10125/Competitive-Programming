#include <bits/stdc++.h>
using namespace std;

pair<int, int> ask(set<int> &A) {
    cout<<"? "<<A.size();
    for(int i: A) cout<<' '<<i;
    cout<<endl;
    pair<int, int> res;
    cin >> res.first >> res.second;
    return res;
}

int print(vector<int> &edges) {
    cout<<"!"<<endl;
    for(int i=1; i<edges.size(); i++) {
        cout<<edges[i]<<" "<<edges[i-1]<<endl;
    }
    int res;
    cin >> res;
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // int sum = n * (n+1) / 2;
        vector<int> A(n);
        set<int> s;
        for(int i=1; i<=n; i++) s.insert(i);
        int p1=0, p2=n-1;
        pair<int, int> res = ask(s);
        A[p1++] = res.first;
        A[p2--] = res.second - res.first;

        while(p1 <= p2) {
            s.erase(A[p1-1]);
            res = ask(s);
            if(res.first == A[p2+1]) A[p1++] = res.second - res.first;
            else A[p1++] = res.first;
        }

        if(print(A) == 1) continue;
        return 0;
    }
}