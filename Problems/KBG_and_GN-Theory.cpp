#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)

template <typename T>
vector<pair<int, int>> factors(T n) {
	vector<pair<int, int>> factor(1);
	FOR(i, 2, sqrt(n), 1) {
		while(n % i == 0) {
			if(factor.back().ff == i) factor.back().ss++;
			else factor.push_back({i, 1});
			n /= i;
		}
	}
	if(n > 1) factor.push_back({n, 1});
	return factor;
}

int mega_solve(int u, int v) {
    if(u == v) return 0;
    int hcf = __gcd(u, v);
    int a = mega_solve(v, hcf);
    
    u = u / hcf;
    vector<pair<int, int>> fact = factors(u);
    int ans = 0;
    for(auto it : fact) {
        ans += (it.ff) * (it.ss);
    }

    return ans + a;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        while(q--) {
            int u, v;
            cin >> u >> v;
            if(u < v) swap(u, v); 
            cout<<mega_solve(u, v);
            cout<<endl;
        }
    }
}