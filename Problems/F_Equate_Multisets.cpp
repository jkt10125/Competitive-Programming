#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
using safe_map = unordered_map<int, T, custom_hash>;
using safe_set = unordered_set<int, custom_hash>;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
            while(a[i] % 2 == 0) a[i] /= 2;
        }
        for(int i=0; i<n; i++) cin >> b[i];

        safe_map<int> M;
        for(int i=0; i<n; i++) M[a[i]]++;

        int f = true;
        for(int i=0; i<n; i++) {
            while(b[i]) {
                if(M[b[i]]) { M[b[i]]--; break; }
                b[i] >>= 1;
            }
            if(!b[i]) f = false;
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}