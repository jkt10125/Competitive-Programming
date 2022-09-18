// Dependencies : Integer factorisation, Binary Exponentiation
// TC : O(Ans log(n) log(n))

// returns one of the possible primitive roots of m
int primitive_root(int m) {
	int phi = m-1; //Assuming m is prime
	vector<pair<int, int>> factor = factors(phi);
	for(int i=2; i<=m; i++) {
		bool flag = true;
		for(int j=1; j<factor.size(); j++) {
			if(power(i, phi/factor[j].first, m) == 1) { flag = false; break; }
		}
		if(flag) return i;
	}
	return -1;
}

// A slight change in the code gives all the possible primitive_root of m

vector<int> primitive_root(int m) {
	int phi = m-1; //Assuming m is prime
	vector<pair<int, int>> factor = factors(phi);
	vector<int> possible_roots;
	for(int i=2; i<=m; i++) {
		bool flag = true;
		for(int j=1; j<factor.size(); j++) {
			if(power(i, phi/factor[j].first, m) == 1) { flag = false; break; }
		}
		if(flag) possible_roots.push_back(i);
	}
	return possible_roots;
}

// NOTE : factors have a {0, 0} entry on the 0th index

