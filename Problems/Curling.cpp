#include <bits/stdc++.h>
using namespace std;

#define int long long

struct point {
    int x, y;
};

int dist(point p) {
    return p.x * p.x + p.y * p.y;
}

bool cmp(point a, point b) {
    return (dist(a) < dist(b));
}

signed main() {
    int t;
    cin >> t;
    for(int ii=0; ii<t; ii++) {
        cout << "Case #" << ii + 1 << ": ";
        int rs, rh;
        cin >> rs >> rh;
        
        int n, m;
        vector<point> r, y;
        
        cin >> n;
        for(int i=0; i<n; i++) {
            point p;
            cin >> p.x >> p.y;
            if(dist(p) <= (rs + rh) * (rs + rh)) {
                r.push_back(p);
            }
        }
        
        cin >> m;
        for(int i=0; i<m; i++) {
            point p;
            cin >> p.x >> p.y;
            if(dist(p) <= (rs + rh) * (rs + rh)) {
                y.push_back(p);
            }
        }

        sort(r.begin(), r.end(), cmp);
        sort(y.begin(), y.end(), cmp);

        int R = 0, Y = 0;
        int pr=0, py=0;
        if(r.empty()) Y = y.size();
        else if(y.empty()) R = r.size();
        else if(dist(r[0]) > dist(y[0])) {
            while(dist(y[py]) < dist(r[pr]) && py < y.size()) {
                Y++;
                py++;
            }
        }
        else if(dist(r[0]) < dist(y[0])) {
            while(dist(r[pr]) < dist(y[0]) && pr < r.size()) {
                R++;
                pr++;
            }
        }
        else {
            while(dist(r[pr]) == dist(r[0]) && pr < r.size()) {
                R++;
                pr++;
            }
            while(dist(y[py]) == dist(y[0]) && py < y.size()) {
                Y++;
                py++;
            }
        }

        cout << R << " " << Y << endl;
    }
}