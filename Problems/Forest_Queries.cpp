#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int A[n+1][n+1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char c;
            cin >> c;
            A[i][j] = (c == '*');
        }
    }
    for(int i=0; i<=n; i++) A[i][0] = A[0][i] = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    }
    
    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int X1 = min(x1, x2), X2 = max(x1, x2);
        int Y1 = min(y1, y2), Y2 = max(y1, y2);

        cout << A[Y2][X2] - A[Y1-1][X2] - A[Y2][X1-1] + A[Y1-1][X1-1] << endl;
    }
}