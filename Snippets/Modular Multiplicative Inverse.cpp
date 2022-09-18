// Dependencies : Extended_GCD
// TC : O(log n)
int MMI(int a, int mod) {
	int x, y;
	int hcf = Extended_GCD(a, mod, x, y);
	if(hcf != 1) ERROR;
	x = (x % mod + mod) % mod;
	return x; 
}

// TC : O(n)
vector<int> MMIs(int n, int mod) {
	vector<int> inv(n+1);
	inv[1] = 1;
	for(int i=2; i<=n; i++) {
		inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
	}
	return inv;
}

// Dependencies : MMI of a number
// TC : O(n)
template <typename int>
vll modular_inverse_of_array(vll &A, int mod) {
	int n = A.size();
	
	vll prefix(n, 1), suffix(n, 1);
	prefix.front() = A.front(); suffix.back() = A.back();
	F1R(i, n-1) { prefix[i] = prefix[i-1] * A[i]; prefix[i] %= mod; }
	F0Rn(i, n-1) { suffix[i] = suffix[i+1] * A[i]; suffix[i] %= mod; }
	
	ll mmi_prod = 1;
	F0R(i, n) { mmi_prod *= A[i]; mmi_prod %= mod; }
	mmi_prod = MMI(mmi_prod, mod);

	vll inv(n);
	F1R(i, n-2) inv[i] = ((prefix[i-1] * suffix[i+1]) / mmi_prod) % mod;
	inv[0] = (suffix[1] / mmi_prod) % mod;
	inv[n-1] = (prefix[n-2] / mmi_prod) % mod;

	return inv;
}
