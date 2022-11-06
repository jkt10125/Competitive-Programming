#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> &A, int k) {
    vector<int> a;
    for(int &i : A) {
        int ctr = 0;
        while(i % k == 0) {
            ctr++;
            i /= k;
        }
        a.push_back(ctr);
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    auto two = f(A, 2), three = f(A, 3);

    int mintwo = *min_element(two.begin(), two.end());
    int minthree = *min_element(three.begin(), three.end());

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += two[i] - mintwo;
        ans += three[i] - minthree;
    }
    bool ok = true;
    for(int i=1; i<n; i++) {
        if(A[i] != A[0]) ok = false;
    }

    if(ok) cout << ans;
    else cout << -1;
}