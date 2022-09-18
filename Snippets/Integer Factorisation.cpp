// TC : O(sqrt(n))
vector<pair<int, int>> factors(int n) {
	vector<pair<int, int>> factor(1);
	for(int i=2; i*i <= n; i++) {
		while(n % i == 0) {
			if(factor.back().first == i) factor.back().second++;
			else factor.push_back({i, 1});
			n /= i;
		}
	}
	if(n > 1) factor.push_back({n, 1});
	return factor;
}


// TC : O(sqrt(n)) : MORE OPTIMISED
vector<int> trial_division3(int n) {
    vector<int> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (int d = 7; d*d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if(i == 8) i = 0;
    }
    if(n > 1) factorization.push_back(n);
    return factorization;
}

// NOTE : we can actually reduce the stress on the machine if we have multiple same values
// by maintaining a hash_map of vectors