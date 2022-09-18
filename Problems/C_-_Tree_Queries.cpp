#include <bits/stdc++.h>
using namespace std;

int ask(int u, int v) {
    int inp;
    cout<<"? "<<u<<" "<<v<<endl;
    cin>>inp;
    return inp;
}

void print(int n) {
    cout<<"! "<<n<<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> one(n+1), two(n+1);
    for(int i=3; i<=n; i++) one[i] = ask(1, i);
    for(int i=3; i<=n; i++) two[i] = ask(2, i);

    map<int, int> diff1, diff2;
    for(int i=3; i<=n; i++) diff1[one[i] - two[i]-1]++;
    for(int i=3; i<=n; i++) diff2[one[i] + two[i]+1]++;
    
    int mx = 0;
    for(auto it: diff1) {
        if(it.second > diff1[mx]) mx = it.first;
    }
    assert(diff1[mx] + diff2[mx] == n-2);
    print(abs(mx));
}