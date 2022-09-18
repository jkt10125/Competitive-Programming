
// Dependencies : Extended_GCD
// ax = b (mod n)
// ax + nk = b
// TC: O(log n)
int LCE(int a, int b, int n) {
	int x, k, hcf;
	hcf = Extended_GCD(a, n, x, k);
	if(b % hcf != 0) ERROR;
	return (b / hcf) * x;
}

// Note : here only one possible answer is returned 
// 	The other possible answers would be x - i*(n/hcf) where i ranging from [0, hcf-1]