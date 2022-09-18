#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int ctr1 = 0;
        vector<int> zeros;
        int ones = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ones++;
            }
        }
        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                while(s[i] == '0' && i < n) {
                    ctr1++;
                    i++;
                }
                zeros.push_back(ctr1);
                ctr1 = 0;
            }
        }

        sort(zeros.rbegin(), zeros.rend());
        int sum = 0;
        int cc=0;
        for(int i : zeros) 
        {
            if(cc+2*i+1<=x)
            {
                sum+=i;
                cc+=2*i+1;
            }
            else{
                int dif=x-cc-1;
                if(dif>1)
                {
                    sum+=(dif/2);
                }
                break;

            }
        }

        cout<<sum+ones<<endl;        
    }
}