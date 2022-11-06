#include <bits/stdc++.h>
using namespace std;

#define int long long

class pc {
    public:
    int low_sum, up_sum;
    multiset<int> low, up;

    pc() { low_sum = up_sum = 0; }

    int median() {
        assert(!low.empty());
        return *low.rbegin();
    }

    void adjust() {
        while(up.size() > low.size()) {
            int moving = *up.begin();
            up_sum -= moving;
            low_sum += moving;
            up.erase(up.find(moving));
            low.insert(moving);
        }
        while(low.size() > up.size() + 1) {
            int moving = *low.rbegin();
            low_sum -= moving;
            up_sum += moving;
            low.erase(low.find(moving));
            up.insert(moving);
        }
    }

    void insert(int val) {
        if(low.empty()) {
            low.insert(val);
            low_sum += val;
        }
        else {
            if(val > median()) {
                up.insert(val);
                up_sum += val;
            }
            else {
                low.insert(val);
                low_sum += val;
            }
            adjust();
        }
    }

    void erase(int val) {
        if(up.find(val) != up.end()) {
            up.erase(up.find(val));
            up_sum -= val;
        }
        else {
            low.erase(low.find(val));
            low_sum -= val;
        }
        adjust();
    }
};

signed main() {
    int n, k;
    cin >> n >> k;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    pc p;
    for(int i=0; i<k; i++) p.insert(A[i]);

    cout << p.up_sum - p.low_sum + (k & 1) * p.median() << ' ';

    for(auto it : p.low) cerr << it << ' ';

    for(int i=k; i<n; i++) {
        p.insert(A[i]);
        p.erase(A[i-k]);
        cout << p.up_sum - p.low_sum + (k & 1) * p.median() << ' ';
    }
}