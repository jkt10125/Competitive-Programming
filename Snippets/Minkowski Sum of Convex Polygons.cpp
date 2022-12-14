#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point () { }
    point (int _x, int _y) : x(_x), y(_y) {}
    point operator + (const point &P) const {
        return point(x + P.x, y + P.y);
    }
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

void reorder_polygon (vector<point> &P){
    size_t idx = 0;
    int n = P.size();
    for (size_t i = 1; i < n; i++) {
        if (P[i].y < P[idx].y || (P[i].y == P[idx].y && P[i].x < P[idx].x)) {
            idx = i;
        }
    }
    rotate(P.begin(), P.begin() + idx, P.end());
}

vector<point> minkowski(vector<point> &P, vector<point> &Q){
    // the first vertex must be the lowest
    reorder_polygon (P);
    reorder_polygon (Q);
    // we must ensure cyclic indexing
    P.push_back (P[0]);
    P.push_back (P[1]);
    Q.push_back (Q[0]);
    Q.push_back (Q[1]);
    // main part
    vector<point> result;
    size_t i = 0, j = 0;
    size_t n = P.size(), m = Q.size();
    while (i < n || j < m){
        result.push_back(P[i] + Q[j]);
        int cross = (P[i + 1] - P[i]). cross(Q[j + 1] - Q[j]);
        if(cross >= 0) {
            i++;
        }
        if(cross <= 0) {
            j++;
        }
    }
    return result;
}

int main() {

}