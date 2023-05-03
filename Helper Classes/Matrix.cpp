#include <bits/stdc++.h>

class matrix {
    int **data, row, col;
    public:
    
    matrix (int n, int m, int val = 0) {
        row = n, col = m;
        data = (int **) malloc(row * sizeof(int *));
        for (int i = 0; i < row; i++) {
            data[i] = (int *) malloc(col * sizeof(int));
            for (int j = 0; j < col; j++) {
                data[i][j] = val;
            }
        }
    }
    
    matrix (const matrix &M) {
        *this = matrix(M.row, M.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[i][j] = M[{i, j}];
            }
        }
    }

    int &operator[] (std::pair<int, int> idx) const {
        // if (idx.first >= row || idx.second >= col || idx.first < 0 || idx.second < 0) {
        //     std::cerr << "Invalid Index([])\n";
        //     exit(0);
        // }
        return data[idx.first][idx.second];
    }

    matrix operator + (const matrix &rhs) {
        if (row != rhs.row || col != rhs.col) {
            std::cerr << "Dimensions mismatch(+)\n";
            exit(0);
        }
        matrix c(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                c[{i, j}] = data[i][j] + rhs[{i, j}];
            }
        }
        return c;
    }

    matrix operator - (const matrix &rhs) {
        if (row != rhs.row || col != rhs.col) {
            std::cerr << "Dimensions mismatch(-)\n";
            exit(0);
        }
        matrix c(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                c[{i, j}] = data[i][j] - rhs[{i, j}];
            }
        }
        return c;
    }

    matrix operator * (const matrix &rhs) {
        if (col != rhs.row) {
            std::cerr << "Dimensions mismatch(*)\n";
            exit(0);
        }
        matrix c(row, rhs.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < rhs.col; j++) {
                for (int k = 0; k < col; k++) {
                    c[{i, j}] += data[i][k] * rhs[{k, j}];
                }
            }
        }
        return c;
    }

    matrix operator % (const int &mod) {
        matrix c(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                c[{i, j}] = data[i][j] % mod;
            }
        }
        return c;
    }

    matrix operator | (const matrix &rhs) {
        if (col != rhs.row) {
            std::cerr << "Dimensions mismatch(/)\n";
            exit(0);
        }
        matrix c(row, rhs.col, INT_MAX);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < rhs.col; j++) {
                for (int k = 0; k < col; k++) {
                    c[{i, j}] = std::min(c[{i, j}], data[i][k] + rhs[{k, j}]);
                }
            }
        }
        return c;
    }

    matrix operator ! () {
        matrix res(col, row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res[{j, i}] = data[i][j];
            }
        }
        return res;
    }

    matrix identity(int n, int multiplier = 1) {
        matrix I(n, n, 0);
        for (int i = 0; i < n; i++) {
            I[{i, i}] = multiplier;
        }
        return I;
    }

    matrix dot_identity(int n) {
        matrix I(n, n, 1000000000);
        for (int i = 0; i < n; i++) {
            I[{i, i}] = 0;
        }
        return I;
    }

    matrix power(int exp) {
        matrix res = identity(row);
        matrix A = *this;
        while (exp) {
            if (exp & 1) {
                res = res * A;
            }
            A = A * A;
            exp >>= 1;
        }
        return res;
    }

    matrix dot_power(int exp) {
        matrix res = dot_identity(row);
        matrix A = *this;
        while (exp) {
            if (exp & 1) {
                res = res | A;
            }
            A = A | A;
            exp >>= 1;
        }
        return res;
    }

    friend std::ostream &operator << (std::ostream &os, const matrix &M) {
        for (int i = 0; i < M.row; i++) {
            for (int j = 0; j < M.col; j++) {
                os << M[{i, j}] << ' ';
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream &operator >> (std::istream &is, matrix &M) {
        for (int i = 0; i < M.row; i++) {
            for (int j = 0; j < M.col; j++) {
                is >> M[{i, j}];
            }
        }
        return is;
    }
};

int main() {
    matrix A(2, 4, 5);
    std::cin >> A;
    std::cerr << (!A);
}