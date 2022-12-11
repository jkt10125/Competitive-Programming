#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

// Ax + By + C = 0
// @returns {A, B, C}
array<int, 3> lineEquation (point &P, point &Q) {
    int A = P.y - Q.y;
    int B = Q.x - P.x;
    int C = -(A * P.x + B * P.y);

    int hcf = __gcd(A, __gcd(B, C));
    if (A < 0 || (A == 0 && B < 0)) {
        hcf = -hcf;
    }
    A /= hcf, B /= hcf, C /= hcf;
    return {A, B, C};
}