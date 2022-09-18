// "Integer Factorisation.cpp"
// TC : O(sqrt(n))
int number_of_divisors(int n) {
	vector<pair<int, int>> factor = factors(n);
	int ans = 1;
	for(int i=1; i<factor.size(); i++) ans *= (factor[i].ss + 1);
	return ans;
}

// Dependencies : Integer Factorisation.cpp, Binary Exponentiation.cpp
int sum_of_divisors(int n) {
	vector<pair<int, int>> factor = factors(n);
	int ans = 1;
	for(int i=1; i<factor.size(); i++) {
		ans *= (power(factor[i].ff, factor[i].ss + 1) - 1) / (factor[i].ff - 1);
	}
	return ans;
}
