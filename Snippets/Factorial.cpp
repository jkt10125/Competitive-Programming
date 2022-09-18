// TC : O(n)
// Generates all factorials from 1 to n
vector<int> factorial(int n, int mod=0) {
	vector<int> fact(n+1, 1);
	for(int i=1; i<=n; i++) {
		factorial[i] = factorial[i-1] * i;
		if(mod) factorial[i] %= mod;
	}
	return fact;
}
