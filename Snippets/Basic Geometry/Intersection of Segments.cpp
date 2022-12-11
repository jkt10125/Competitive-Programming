#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point () { }
    point (int _x, int _y) : x(_x), y(_y) {}
    point operator - (const point &P) const {
        return point(x - P.x, y - P.y);
    }
    int cross (const point &P) const {
        return (x * P.y - y * P.x);
    }
    int cross (const point &P, const point &Q) const {
        return (P - *this).cross (Q - *this);
    }
};

int sgn (const int &x) {
    return (x >= 0) ? (x) ? 1 : 0 : -1;
}

bool checkIntersection (int a, int b, int c, int d) {
    if (a > b) swap (a, b);
    if (c > d) swap (c, d);
    return max (a, c) <= min (b, d);
}

bool checkIntersection (const point &a, const point &b, const point &c, const point &d) {
    if (!a.cross (b, c) && !a.cross(b, d)) {
        return checkIntersection (a.x, b.x, c.x, d.x) && checkIntersection (a.y, b.y, c.y, d.y);
    }
    return sgn (a.cross(b, c)) != sgn (a.cross(b, d)) && sgn (b.cross(a, c)) != sgn (b.cross(a, d));
}