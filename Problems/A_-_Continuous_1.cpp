#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int cnt0=0, cnt1=0, cnt2=0, cnt3=0;
    for(int i=0; i<n; i++){
        if(str[i]=='1') cnt1++;
    }

    for(int i=0; i<k; i++){
        if(str[i]=='0') cnt0++;
        else if(str[i]=='?') cnt3++;
    }
    
    if(cnt0==0 && cnt3==k-cnt1) cnt2+=1;
    for(int i=1; i<n-k+1; i++){
        if(str[i-1]=='0') cnt0--;
        if(str[i+k-1]=='0') cnt0++;
        if(str[i-1]=='?') cnt3--;
        if(str[i+k-1]=='?') cnt3++;
        if(cnt0==0 && cnt3==k-cnt1) cnt2+=1;
    }

    if(cnt2==1) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
