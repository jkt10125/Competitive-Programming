#include <bits/stdc++.h>
using namespace std;

vector<int> sa, sb;
int x;

void f (vector<int> &A, int q) {
    int n = A.size();
    for (int i = 0; i < (1 << n); i++) {
        int ctr = 0;
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j)) {
                ctr += A[j];
            }
            if (ctr > x) break;
        }
        if (ctr > x) continue;

        if(q) sa.push_back(ctr);
        else sb.push_back(ctr);
    }
}

void pr(map<int, int> &m) {
    for(auto [a, b] : m) {
        cerr << a << " : " << b << endl;
    }
}

int main() {

    int n;
    cin >> n >> x;
    vector<int> A, B;
    for(int i=0; i<n; i++) {
        int z;
        cin >> z;
        if(i < 20) A.push_back(z);
        else B.push_back(z);
    }
    f(A, 1);
    f(B, 0);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    long long ans = 0;
    for(int a : sb) {
        if(a > x) break;
        ans += ;
    }

    cout << ans;
}