// Dependencies : Binary Exponentiation
// TC : O(sqrt(mod) log mod)
// Description : returns one of the value of x for which a^x = b (mod m)
	// returns -1 if answer doesnot exits

int descrete_log(int a, int b, int mod) {
	if(a == 0) return (b == 0) ? 1 : -1; //0^0 is undefined
	int n = ceil(sqrt(mod));
	map<int, int> f1;
	for(int p=1; p<=n; p++) f1[power(a, n*p, mod)] = p;
    for(int q=0; q<n; q++) {
		int f2_q = b * power(a, q, mod) % mod;
		if(f1[f2_q]) return (n * f1[f2_q] - q);
	}
    return -1;
}

vector<int> descrete_log(int a, int b, int mod) {
	if (a == 0) return (b == 0) ? vector<int>(1, 1) : vector<int>(); // 0^0 is undefined
	int n = ceil(sqrt(mod));
	map<int, int> f1;
	for(int p=1; p<=n; p++) f1[power(a, n*p, mod)] = p;
    vector<int> ans;
    for(int q=0; q<n; q++) {
		int f2_q = b * power(a, q, mod) % mod;
		if(f1[f2_q]) ans.push_back(n * f1[f2_q] - q);
	}
	sort(ans.begin(), ans.end());
    return ans;
}

// Optimisation can be done using unordered_map instead of map
