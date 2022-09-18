// Description : we have to find the values of x such that x^k = a (mod m)

int descrete_root(int x, int k, int mod) {
	int g = primitive_root(m);
	if(g == -1) return -1;
	int G = POWER(g, k, m);
	// now the equation reduces to G^y = a (mod m)
	int y0 = descrete_log(G, a, m);
	return POWER(g, y0, m);
}

// we do slight changes to our code to print all the descrete_root

vll descrete_root(ll k, ll a, ll m) {
	int g = primitive_root(m);
	if(g == -1) return vll();
	ll G = POWER((ll)g, k, m);
	// now the equation reduces to G^y = a (mod m)
	ll y0 = descrete_log(G, a, m);
	if(y0 == -1) return vll();
	ll x0 = POWER((ll)g, y0, m);
	vll possible_ans;
	possible_ans.pb(x0);

	ll phi = (m-1); // Assuming m to be prime
	ll change = phi / GCD(phi, k);
	FOR(i, y0 % change, m-2, change) {
		ll y = i;
		ll x = POWER((ll)g, y, m);
		possible_ans.pb(x);
	}
	sort(all(possible_ans));
	return possible_ans;
}