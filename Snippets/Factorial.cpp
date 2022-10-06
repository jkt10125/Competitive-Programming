// TC : O(n)
// Generates all factorials from 1 to n
vector<int> factorial(int n, int mod=0) {
	vector<int> fact(n+1, 1);
	for(int i=1; i<=n; i++) {
		fact[i] = fact[i-1] * i;
		if(mod) fact[i] %= mod;
	}
	return fact;
}
