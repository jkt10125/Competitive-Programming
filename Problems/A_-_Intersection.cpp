#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans;
    if(x2 > x1) {
        if(x2 > y1) ans = 0;
        else ans = min(y1, y2) - x2;
    }
    else {
        if(x1 > y2) ans = 0;
        else ans = min(y1, y2) - x1;
    }
    cout<<ans;
}   