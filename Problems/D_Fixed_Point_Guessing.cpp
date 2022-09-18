#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int l=1, r=n;
        while(l < r) {
            int m = (l+r)/2;
            cout<<"? "<<l<<" "<<m<<endl;
            int ctr = 0;
            for(int i=0; i<m-l+1; i++) {
                int x;
                cin >> x;
                if(x >= l && x <= m) ctr++;
            }
            if(ctr & 1) r = m;
            else l = m+1;
        }
        cout<<"! "<<r<<endl;
    }
}