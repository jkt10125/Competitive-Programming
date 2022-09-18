#include <bits/stdc++.h>
using namespace std;

class point {
    public:
    int x, y;
};

point p0;

bool cmp(point p1, point p2) {
    int v = (p1.y - p0.y) * (p2.x - p0.x) - (p1.x - p0.x) * (p2.y - p0.y);
    return (v == 0) ? (p1.y < p2.y) : (v < 0);
}

vector<point> convex_hull(vector<point> &A) {
    p0 = A[0];
    int n = A.size();
    for(int i=1; i<n; i++) {
        if(A[i].y < p0.y) p0 = A[i];
        else if(A[i].y == p0.y) {
            p0.x = min(p0.x, A[i].x);
        }
    }
    sort(A.begin(), A.end(), cmp);

    vector<point> ST = {A[0], A[1]};
    for(int i=2; i<n; i++) {
        point p0, p1, p2 = A[i];
        while(ST.size() > 1) {
            p0 = ST[ST.size()-2]; p1 = ST[ST.size()-1];
            if((p1.y - p0.y) * (p2.x - p0.x) >= (p1.x - p0.x) * (p2.y - p0.y)) {
                // change the camparison above to > if you want to keep all points on periferi
                ST.pop_back();
            }
            else break;
        }
        ST.push_back(p2);
    }
    return ST;
}