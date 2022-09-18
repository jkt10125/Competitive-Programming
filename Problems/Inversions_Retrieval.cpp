#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    // int ctr = n-1;
    // if(true) {
    //     cout<<n*(n-1)+1<<endl;
    //     for(int i=0; i<n; i++) {
    //         for(int j=i+1; j<n; j++) {
    //             cout<<"compare "<<i<<" "<<j<<endl;
    //             ctr++;
    //             if(ctr != n) {
    //                 cout<<"add "<<ctr<<" "<<ctr+1<<endl;
    //                 ctr++;
    //             }
    //         }
    //     }
    //     cout<<"put "<<n*(n-1)/2<<endl;
    //     cout<<"subtract "<<ctr+1<<" "<<ctr<<endl;
    // }

    int ctr = n-1;
    for(int i=n-1; i>0; i--) {
        cout<<"compare "<<i<<" "<<i-1<<endl;
        ctr++;
        
    }
}