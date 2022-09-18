// TC : O(p log(n))
int factorial_modulo(int n, int p) {
	int x = (n/p % 2) p-1 : 1;
	if(n < p) {
		for(int i=1; i<=n; i++) x = (x * i) % p;
		return x; 
	}
	return x * factorial_modulo(n/p, p);
}


// Description : How many times p appeared in n!
// TC : O(log n)
int multiplicity_factorial(int n, int p) {
	int ctr = 0;
	while(n) { n /= p, ctr += n; }
	return ctr;
}