int power(int a, int b, int mod=0) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		if(mod) pow %= mod, a %= mod;
	}
	return pow;
}