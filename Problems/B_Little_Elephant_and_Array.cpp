#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int H[100005];
int N, M;
const int BLOCK_SIZE = 320;
long long res;

void add(int x) {
    if(x > 100000) return;
    res -= (x == H[x]);
    H[x]++;
    res += (x == H[x]);
}

void del(int x) {
    if(x > 100000) return;
    res -= (x == H[x]);
    H[x]--;
    res += (x == H[x]);
}

void reset(int v) {
    if(v > 100000) return;
    H[v] = 0;
}

int main()
{
    cin >> N >> M;
    
    vector<int> A(N);
    
    for(int i=0; i<N; i++) 
        cin >> A[i];

    vector<vector<pair<int, pair<int, int>>>> B(N / BLOCK_SIZE + 1);
    for(int i=0; i<M; i++) 
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        B[l / BLOCK_SIZE].push_back({r, {l, i}});
    }

    for(auto &it : B) 
        sort(it.begin(), it.end());

    vector<int> ans(M);

    for(int i=0; i<B.size(); i++) {
        int l, r;
        l = r = i * BLOCK_SIZE;
        
        res = 0;
        
        for(int i=0; i<N; i++) 
            reset(A[i]);


        for(auto &Q : B[i]) {
            while(r <= Q.ff) {
                add(A[r]);
                r++;
            }
            while(l < Q.ss.ff) {
                del(A[l]);
                l++;
            }
            while(l > Q.ss.ff) {
                l--;
                add(A[l]);
            }
            
            ans[Q.ss.ss] = res;
        }
    }

    for(int i=0; i<M; i++) 
        cout << ans[i] << endl;
}