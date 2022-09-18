template <typename T = int>
class Matrix {
public:
	int row, coloumn;
	vector<vector<T>> matrix;
	Matrix(int r=0, int c=0, int val=0) {
		if(r <= 0 || c <= 0) cout<<"ERROR!";
		row = r; coloumn = c;
		matrix = vector<vector<T>> (r, vector<T> (c, val));
	}
	
	Matrix operator!() {
		Matrix<T> A(coloumn, row);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				A.matrix[j][i] = this->matrix[i][j];
			}
		}
		return A;
	}

	Matrix operator+(const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) return Matrix<T> (0, 0);
		Matrix<T> C(row, coloumn);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				C.matrix[i][j] = this->matrix[i][j] + A.matrix[i][j];
			}
		}
		return C;
	}

	Matrix operator+(const T &val) {
		Matrix<T> C(row, coloumn);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				C.matrix[i][j] = this->matrix[i][j] + val;
			}
		}
		return C;
	}

	Matrix operator+() {
		return *this;
	}

	Matrix operator+=(const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) return Matrix<T> (0, 0);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				this->matrix[i][j] = this->matrix[i][j] + A.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator+=(const T &val) {
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				this->matrix[i][j] += val;
			}
		}
		return *this;
	}

	Matrix operator-(const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) return Matrix<T> (0, 0);
		Matrix<T> C(row, coloumn);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				C.matrix[i][j] = this->matrix[i][j] - A.matrix[i][j];
			}
		}
		return C;
	}

	Matrix operator-(const T &val) {
		return *this + (-val);
	}

	Matrix operator-() {
		Matrix<T> C(row, coloumn);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				C.matrix[i][j] = -this->matrix[i][j];
			}
		}
		return C;
	}

	Matrix operator-=(const Matrix &A) {
		if(this->row != A.row || this->coloumn != A.coloumn) return Matrix<T> (0, 0);
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				this->matrix[i][j] = this->matrix[i][j] - A.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator-=(const T &val) {
		for(int i=0; i<row; i++) {
			for(int j=0; j<coloumn; j++) {
				this->matrix[i][j] -= val;
			}
		}
		return *this;
	}

	Matrix operator*(const Matrix &A) {
		if(this->coloumn != A.row) return Matrix<T> (0, 0);
		Matrix<T> C(this->row, A.coloumn);
		F0R(i, this->row) {
			F0R(j, A.coloumn) {
				F0R(k, this->coloumn) {
					C.matrix[i][j] += this->matrix[i][k] * A.matrix[k][j];
				}
			}
		}
		return C;
	}

	Matrix operator=(const Matrix &A) {
		this->row = A.row;
		this->coloumn = A.coloumn;
		this->matrix = A.matrix;
		return *this;
	}

	bool operator==(const Matrix &A) {
		return (this->matrix == A.matrix);
	}

	friend istream &operator>>(istream &is, Matrix &A) {
		is >> A.matrix;
		return is;
	}

	friend ostream &operator<<(ostream &os, const Matrix &A) {
		os << A.matrix;
		return os;
	}
};

template <typename T>
Matrix<T> POWER(Matrix<T> A, int n) {
	Matrix<T> ans(A.row, A.coloumn, 0);
	ans.matrix[0][0] = ans.matrix[1][1] = 1;

	while(n) {
		if(n & 1) ans *= A;
		n = n >> 1; A = A * A;
	}
	return ans;
}