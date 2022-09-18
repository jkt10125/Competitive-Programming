// Description : converts a number to the base of 3

string BT_encode(int num) {
	string s;
	const bool SIGN = (num < 0);
	num = abs(num);
	while(num > 0) {
		s.push_back(num % 3 + '0');
		num /= 3;
	}
	s.push_back('0');
	reverse(s.begin(), s.end());
	for(int i=s.size()-1; i>=0; i--) {
		if(s[i] == '2') { s[i] = 'Z'; s[i-1]++; }
		if(s[i] == '3') { s[i] = '0'; s[i-1]++; }
	}
	if(SIGN) for(int i=s.size()-1; i>=0; i--) {
		if(s[i] == '1') s[i] = 'Z';
		else if(s[i] == 'Z') s[i] = '1';
	}
	return s;
}

int BT_decode(string s) {
	int ans = 0, ctr = 1;
	for(int i=s.size()-1; i>=0; i--) {
		if(s[i] == 'Z') ans -= ctr;
		else ans += (s[i]-'0') * ctr;
		ctr *= 3;
	} 
	return ans;
}