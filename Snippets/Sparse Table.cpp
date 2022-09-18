template <typename T, T (*func) (T, T)>
class SparseTable {
	vvT TABLE;
public:
	SparseTable(vT &arr) {
		int n = arr.size();
		TABLE = vvT (log2(n)+1, vT (n, 0)); // TABLE[i][j] : min(arr[j..2^i+j-1])

		TABLE[0] = arr;
		int ctr = 1;
		F1R(i, log2(n)) {
			F0R(j, n-ctr) TABLE[i][j] = func(TABLE[i-1][j], TABLE[i-1][j + ctr]);
			ctr = ctr << 1;
		}
		cerr << TABLE;
	}

	T query(int l, int r, const T constant) { // Query ranges from A[l...r-1]
		int a = r - l;
		int ctr = 0;
		T ans = constant;
		while(a) {
			if(a & 1) {	ans = func(ans, TABLE[ctr][l]); l += (1 << ctr); }
			ctr++; a >>= 1;
		}
		return ans;
	}
};