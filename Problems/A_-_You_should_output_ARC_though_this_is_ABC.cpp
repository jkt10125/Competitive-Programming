#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int A[3][3];
    for(int i=1; i<3; i++) {
        for(int j=1; j<3; j++) {
            cin >> A[i][j];
        }
    }
    cout<<A[r][c]<<endl;
}