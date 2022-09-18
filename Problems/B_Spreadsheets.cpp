#include <iostream>
using namespace std;

int f(int a, char b) { return 10*a + b - '0'; }

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s[1] <= '9' && s[1] >= '0') {
            int a = 0, b = 0;
            int i=1;
            while(s[i] <= '9' && s[i] >= '0') a = f(a, s[i++]);
            i++;
            while(s[i] <= '9' && s[i] >= '0') b = f(b, s[i++]);
        }
    }
}