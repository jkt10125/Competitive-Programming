#include <bits/stdc++.h>
using namespace std;

map<int, char> M; 
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107};

int e(string s) {
    int a = 0;
    a = (s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0');
    return a;
}

void f() {
    for(int i=0; i<26; i++) M[primes[i]] = 'a'+i;
    M[primes[26]] = ',';
    M[primes[27]] = '.';
}

void rotate() {
    char c = M[primes[27]];
    for(int i=27; i>0; i--) {
        M[primes[i]] = M[primes[i-1]];
    }
    M[primes[0]] = c;
}

int main()
{
	int T;
	f();
	scanf("%d", &T);
	while(T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		for(int i=0; i<3*n; i+=3) {
		    cout<<M[e(s.substr(i, 3))];
		    if(M[e(s.substr(i, 3))] == '.') rotate();
		}
		cout<<endl;
	}
}