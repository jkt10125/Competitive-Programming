const int BLOCK_SIZE = 450;

vi H(1 << 21);

void add(int v) {
    // Do Something
    H[v]++;
}

void del(int v) {
    // Do Something
    H[v]--;
}

void reset(int v) {
    // Do Something
    H[v] = 0;
}

ll res;



int main() {
    int n, m;
    cin >> n >> m;
    vi A(n);
    cin >> A;

    vvppiii B(n / BLOCK_SIZE + 1);
    F0R(i, m) {
        int l, r;
        cin >> l >> r;
        B[l / BLOCK_SIZE].pb({{r, l}, i});
    }
    for(auto &it : B) sort(all(it));
    
    vi ans(m);

    F0R(i, B.size()) {
        int l, r;
        l = r = i * BLOCK_SIZE;
        F0R(i, n) reset(A[i]);
        res = 0;
        for(auto &q : B[i]) {
            while(r <= q.ff.ff) {
                add(A[r]);
                r++;
            }
            while(l < q.ff.ss) {
                del(A[l]);
                l++;
            }
            while(l > q.ff.ss) {
                l--;
                add(A[l]);
            }
            ans[q.ss] = res;
        }
    }
}