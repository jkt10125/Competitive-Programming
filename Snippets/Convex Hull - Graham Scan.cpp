#include <bits/stdc++.h>
using namespace std;

// class point {
//     public:
//     int x, y;
// };

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

point p0;

bool cmp(point p1, point p2) {
    int v = p0.cross (p1, p2);
    return (!v) ? (p1.y < p2.y) : (v > 0);
}

vector<point> convexHull(vector<point> &A) {
    p0 = A[0];
    int n = A.size();
    for(int i=1; i<n; i++) {
        if(A[i].y < p0.y) p0 = A[i];
        else if(A[i].y == p0.y) {
            p0.x = min(p0.x, A[i].x);
        }
    }
    sort(A.begin(), A.end(), cmp);
    for (point p : A) {
        cerr << p.x << ' ' << p.y << endl;
    }
    vector<point> ST = {A[0], A[1]};
    for(int i=2; i<n; i++) {
        point p0, p1, p2 = A[i];
        while(ST.size() > 1) {
            p0 = ST[ST.size()-2]; p1 = ST[ST.size()-1];
            if (p0.cross(p1, p2) <= 0) {
                // change the camparison above to < if you want to keep all points on periferi
                ST.pop_back();
            }
            else break;
        }
        ST.push_back(p2);
    }
    return ST;
}

int main() {
    int n;
    cin >> n;
    vector<point> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
    }
    for (point p : convexHull(A)) {
        cout << p.x << ' ' << p.y << endl;
    }
}