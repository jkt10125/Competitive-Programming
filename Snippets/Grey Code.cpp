int grey_code(int n) {
	return (n ^ (n >> 1));
}

int rev_grey_code(int n) {
	int ans = 0;
	while(n) { ans = ans ^ n; n >>= 1; }
	return ans;
}