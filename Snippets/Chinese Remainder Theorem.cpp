// Dependencies : Extended_GCD
int CRT(vector<int> &num, vector<int> &rem) {
	int tmp, n = num.size();
	int prod = 1;
	for(int i=0; i<n; i++) prod *= num[i];

	vector<int> pp(n);
	for(int i=0; i<n; i++) pp[i] /= num[i];

	vector<int> inv(n);
	for(int i=0; i<n; i++) {
		int hcf = Extended_GCD(pp[i], num[i], inv[i], tmp);
		if(hcf != 1) return -1;
		inv[i] = (inv[i] + num[i]) % num[i];
	}

	int x = 0;
	for(int i=0; i<n; i++) x = (x + pp[i]*rem[i]*inv[i]) % prod;

	return x;
}