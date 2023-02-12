#include <bits/stdc++.h>
using namespace std;

class Matrix {
public:
	int row, coloumn;
	vector<vector<int>> matrix;
	
    Matrix() {}
    
    Matrix(int r, int c, int val=0) {
		if(r <= 0 || c <= 0) {
            throw("wrong dimensions ()");
        }
		row = r; coloumn = c;
		matrix = vector<vector<int>> (r, vector<int> (c, val));
	}
	
    // Matrix transpose
	Matrix operator!() {
		Matrix A(coloumn, row);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				A.matrix[j][i] = this->matrix[i][j];
			}
		}
		return A;
	}

	Matrix operator + (const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) {
            throw("wrong dimensions (+)");
        }
		Matrix C(row, coloumn);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				C.matrix[i][j] = this->matrix[i][j] + A.matrix[i][j];
			}
		}
		return C;
	}

	Matrix operator+() {
		return *this;
	}

	Matrix operator += (const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) {
            throw("wrong dimensions (+=)");
        }
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				this->matrix[i][j] = this->matrix[i][j] + A.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator - (const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) {
            throw("wrong dimensions (-)");
        }
		Matrix C(row, coloumn);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				C.matrix[i][j] = this->matrix[i][j] - A.matrix[i][j];
			}
		}
		return C;
	}

	Matrix operator - () {
		Matrix C(row, coloumn);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				C.matrix[i][j] = -this->matrix[i][j];
			}
		}
		return C;
	}

	Matrix operator -= (const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) {
            throw("wrong dimensions (-=)");
        }
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				this->matrix[i][j] = this->matrix[i][j] - A.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator * (const Matrix &A) {
		if(this->coloumn != A.row) {
            throw("wrong dimensions (*)");
        }
		Matrix C(this->row, A.coloumn);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < A.coloumn; j++) {
				for (int k = 0; k < this->coloumn; k++) {
					C.matrix[i][j] += this->matrix[i][k] * A.matrix[k][j];
				}
			}
		}
		return C;
	}

	Matrix operator = (const Matrix &A) {
		this->row = A.row;
		this->coloumn = A.coloumn;
		this->matrix = A.matrix;
		return *this;
	}

	bool operator == (const Matrix &A) {
		return (this->matrix == A.matrix);
	}

	friend istream &operator >> (istream &is, Matrix &A) {
		for (vector<int> &it : A.matrix) {
            for (int &val : it) {
                is >> val;
            }
        }
		return is;
	}

	friend ostream &operator << (ostream &os, const Matrix &A) {
		for (vector<int> it : A.matrix) {
            for (int &val : it) {
                os << val << ' ';
            }
            os << endl;    
        }
		return os;
	}
};

template <typename int>
Matrix<int> POWER(Matrix<int> A, int n) {
	Matrix<int> ans(A.row, A.coloumn, 0);
	ans.matrix[0][0] = ans.matrix[1][1] = 1;

	while(n) {
		if(n & 1) ans *= A;
		n = n >> 1; A = A * A;
	}
	return ans;
}
