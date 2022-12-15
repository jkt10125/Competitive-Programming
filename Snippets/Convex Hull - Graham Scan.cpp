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



    bool operator == (const point &P) const {
        return (x == P.x && y == P.y);
    }
};

vector<point> convexHull(vector<point> &A) {
    size_t idx = 0;
    int n = A.size();
    
    for (size_t i = 1; i < n; i++) {
        if (A[i].y < A[idx].y || (A[i].y == A[idx].y && A[i].x < A[idx].x)) {
            idx = i;
        }
    }
    swap(A[0], A[idx]);
    point p0 = A[0];

    sort (A.begin() + 1, A.end(), [&p0] (const point &p1, const point &p2) {
        int v = p0.cross (p1, p2);
        return ((!v) ? ((p1.x < p2.x) || (p1.y < p2.y)) : (v > 0));
    });

    idx = n - 1;
    while (!p0.cross (A[idx], A[idx - 1])) {
        if (idx == 1) break;
        idx--;
    }
    reverse (A.begin() + idx, A.end());
    A.push_back(A.front());

    vector<point> ST = {A[0], A[1]};
    for (int i = 2; i <= n; i++) {
        point p1, p2 = A[i];
        while (ST.size() > 1) {
            p0 = ST[ST.size()-2]; p1 = ST[ST.size()-1];
            if (p0.cross(p1, p2) <= 0) {
                // change the above sign to < if you want to preserve all points on periferi
                ST.pop_back();
            }
            else break;
        }
        ST.push_back(p2);
    }
    A.pop_back();
    assert(ST.front() == ST.back());
    ST.pop_back();
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