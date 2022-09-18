#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> ab, ba;
    for(int i=0; i<s.size()-1; i++) {
        if(s.substr(i, 2) == "AB") ab.push_back(i);
        if(s.substr(i, 2) == "BA") ba.push_back(i);
    }

    if(ab.size() == 0 || ba.size() == 0) cout<<"NO";
    else {
        if(ab.size() > 1 && ba.size() > 1) cout<<"YES";
        else {
            if(ab.size() > 2 || ba.size() > 2) cout<<"YES";
            else if()
            else if(abs(ab[0]-ba[0]) > 1) cout<<"YES";
            else cout<<"NO"; 
        }
    } 
}