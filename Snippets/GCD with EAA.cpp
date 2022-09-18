int Extended_GCD(int a, int b, int &x, int &y) {
	if(b == 0) { x=1; y=0; return a; }
	int x1, y1, hcf;
	hcf = Extended_GCD(b, a % b, x1, y1);
	x = y1; y = x1 - y1 * (a / b);
	return hcf;
}

#define GCD __gcd

// ax + by = c
// GCD(a, b) = g

// if(c % g != 0) no solution
// else inf solution : a(x+b/g) + b(y-a/g) = c
