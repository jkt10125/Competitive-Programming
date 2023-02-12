#include <bits/stdc++.h>
using namespace std;

using matrix = vector<vector<int>>;

matrix operator + (const matrix &lhs, const matrix &rhs) {
    if(lhs.size() != rhs.size() || lhs[0].size() != rhs[0].size()) {
        throw("wrong dimensions (+)");
    }
    matrix C(lhs.size(), vector<int> (lhs[0].size(), 0));
    for(int i = 0; i < lhs.size(); i++) {
        for(int j = 0; j < lhs[0].size(); j++) {
            C[i][j] = lhs[i][j] + rhs[i][j];
        }
    }
    return C;
}

matrix operator - (const matrix &lhs, const matrix &rhs) {
    if(lhs.size() != rhs.size() || lhs[0].size() != rhs[0].size()) {
        throw("wrong dimensions (-)");
    }
    matrix C(lhs.size(), vector<int> (lhs[0].size(), 0));
    for(int i = 0; i < lhs.size(); i++) {
        for(int j = 0; j < lhs[0].size(); j++) {
            C[i][j] = lhs[i][j] - rhs[i][j];
        }
    }
    return C;
}

matrix operator * (const matrix &lhs, const matrix &rhs) {
    if(lhs[0].size() != rhs.size()) {
        throw("wrong dimensions (*)");
    }
    matrix C(lhs.size(), vector<int> (rhs[0].size(), 0));
    for (int i = 0; i < lhs.size(); i++) {
        for (int j = 0; j < rhs[0].size(); j++) {
            for (int k = 0; k < lhs[0].size(); k++) {
                C[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return C;
}

matrix operator % (const matrix &lhs, int mod) {
    matrix C(lhs.size(), vector<int> (lhs[0].size(), 0));
    for (int i = 0; i < lhs.size(); i++) {
        for (int j = 0; j < lhs[0].size(); j++) {
            C[i][j] = lhs[i][j] % mod;
        }
    }
    return C;
}

istream &operator >> (istream &is, matrix &A) {
    for (vector<int> &it : A) {
        for (int &val : it) {
            is >> val;
        }
    }
    return is;
}

ostream &operator << (ostream &os, const matrix &A) {
    for (vector<int> it : A) {
        for (int &val : it) {
            os << val << ' ';
        }
        os << endl;    
    }
    return os;
}

matrix power(matrix A, int n) {
	matrix res(A.size(), vector<int> (A[0].size(), 0));
    for (int i = 0; i < A.size(); i++) res[i][i] = 1;

	while(n) {
		if(n & 1) res = res * A;
		n = n >> 1; A = A * A;
	}
	return res;
}

int main() {
    
    return 0;
}
