#include <bits/stdc++.h>
using namespace std;

class BigInteger {
public:
    string value;
    bool sign;

    BigInteger(string VALUE="", bool SIGN=0) { value = VALUE; sign = SIGN; clean(); }

    BigInteger(long long a) {
        if(a < 0) { sign = 1; a = -a; }
        else sign = 0;
        value = to_string(a);  
    }
    
    BigInteger operator=(const string &s) { return (*this = BigInteger(s)); }

    BigInteger operator=(const long long &a) { return (*this = BigInteger(a)); }

    void allignRight(const long long a) {
        string zeroes;
        for(int i=0; i<a; i++) zeroes.push_back('0');
        value = zeroes + value;
    }

    void allignLeft(const long long a) { for(int i=0; i<a; i++) value.push_back('0'); }

    BigInteger operator-() { return BigInteger(value, !sign); }

    BigInteger operator++(int) { return (*this += 1); }

    BigInteger operator++() { return (*this += 1); }

    BigInteger operator--(int) { return (*this -= 1); }

    BigInteger operator--() { return (*this -= 1); }

    BigInteger operator+(const BigInteger &A) {
        BigInteger B = A;
        if(B.sign == 1) {
            if(sign == 0) return (*this - (-B));
            return -(-(*this) + (-B));
        }
        if(sign == 1) return -(-(*this) - B);

        if(*this < B) return B.operator+(*this);

        int numOfZeroes = value.size() - B.value.size();
        B.allignRight(numOfZeroes);

        bool carry = 0;
        for(int i=B.value.size()-1; i>=0; i--) {
            int val = B.value[i] + value[i] + carry - 96;
            B.value[i] = val % 10 + 48;
            carry = val / 10;
        }
        if(carry) B.value = "1" + B.value;

        return B;
    }

    BigInteger operator+(const long long &a) { return (*this + BigInteger(a)); }

    BigInteger operator+=(const long long &a) { return *this = (*this + a); }

    BigInteger operator+=(const BigInteger &A) { return *this = (*this + A); }

    BigInteger operator-(const BigInteger &A) {
        BigInteger B = A;
        if(B.sign == 1) { 
            if(sign == 0) return (*this + (-B)); 
            return -(-(*this) - (-B));
        }
        if(sign == 1) return -(-(*this) + B);
        if(*this < B) return -(B.operator-(*this));

        int numOfZeroes = value.size() - B.value.size();
        B.allignRight(numOfZeroes);

        bool carry = 0;
        for(int i=B.value.size()-1; i>=0; i--) {
            int val = value[i] - B.value[i] - carry;
            carry = 0;
            if(val < 0) { val += 10; carry = 1; }
            B.value[i] = val + 48;
        }
        B.clean();
        return B;
    }

    BigInteger operator-(const long long &a) { return (*this - BigInteger(a)); }

    BigInteger operator-=(const long long &a) { return *this = (*this - a); }

    BigInteger operator-=(const BigInteger &A) { return *this = (*this - A); }

    BigInteger operator*(const BigInteger &A) {
        BigInteger ans = 0ll;
        if(A.value == "0") return BigInteger();
        if(value == "0") return BigInteger();
        for(int i=A.value.size()-1; i>=0; i--) {
            BigInteger B = *this;
            int carry = 0, sum;
            for(int j=value.size()-1; j>=0; j--) {
                sum = (value[j] - 48) * (A.value[i] - 48) + carry;
                B.value[j] = sum % 10 + 48;
                carry = sum / 10;
            }
            if(carry) B.value = char(carry + 48) + B.value;
            B.allignLeft(A.value.size() - i - 1);
            ans += B;
        }
        ans.sign = sign ^ A.sign;
        return ans;
    }

    BigInteger operator*(const long long &a) { return (*this * BigInteger(a)); }

    BigInteger operator*=(const long long &a) { return *this = (*this * a); }

    BigInteger operator*=(const BigInteger &A) { return *this = (*this * A); }

    BigInteger operator/(const BigInteger &A) {
        if(A.value == "0") throw("Division by Zero");
        BigInteger ans = A;
        if(absolute() < ans.absolute()) return BigInteger();
        ans = BigInteger();
        BigInteger tmp = 0ll;
        long unsigned int idx = 0;
        while(tmp < A) { tmp = tmp * 10ll + (value[idx++] - 48); }
        while(idx < value.size()) {
            int ctr = 0;
            while(tmp >= A) { tmp -= A; ctr++; }
            tmp = tmp * 10ll + (value[idx++] - 48);
            ans = ans * 10ll + ctr;
        }
        ans = ans * 10ll;
        while(tmp >= A) { tmp -= A; ans++; }
        ans.sign = sign ^ A.sign;
        return ans;
    }

    BigInteger operator/(const long long &a) { return (*this / BigInteger(a)); }

    BigInteger operator/=(const long long &a) { return *this = (*this / a); }

    BigInteger operator/=(const BigInteger &A) { return *this = (*this / A); }

    BigInteger operator%(const BigInteger &A) {
        if(A.value == "0") throw("Modulo by Zero");
        return *this - *this / A * A;
    }

    BigInteger operator%(const long long &a) { return (*this % BigInteger(a)); }

    BigInteger operator%=(const long long &a) { return *this = (*this % a); }

    BigInteger operator%=(const BigInteger &A) { return *this = (*this % A); }

    bool operator>(const BigInteger &A) {
        if(sign < A.sign) return true;
        if(sign > A.sign) return false;
        if(value.size() > A.value.size()) return (1 ^ sign);
        if(value.size() == A.value.size()) {
            if(value > A.value) return (1 ^ sign);
        }
        return (0 ^ sign);
    }

    bool operator>(const long long &a) { return (*this > BigInteger(a)); }

    bool operator>=(const BigInteger &A) {
        if(*this > A) return true;
        return (*this == A);
    }

    bool operator>=(const long long &a) { return (*this >= BigInteger(a)); }

    bool operator<(const BigInteger &A) {
        if(sign > A.sign) return true;
        if(sign < A.sign) return false;
        if(value.size() < A.value.size()) return (1 ^ sign);
        if(value.size() == A.value.size()) {
            if(value < A.value) return (1 ^ sign);
        }
        return (0 ^ sign);
    }

    bool operator<(const long long &a) { return (*this < BigInteger(a)); }

    bool operator<=(const BigInteger &A) {
        if(*this < A) return true;
        return (*this == A);
    }

    bool operator<=(const long long &a) { return (*this <= BigInteger(a)); }

    bool operator==(const BigInteger &A) { return (value == A.value && sign == A.sign); }

    bool operator==(const long long &a) { return (*this == BigInteger(a)); }

    bool operator!=(const BigInteger &A) { return !(*this == A); }

    bool operator!=(const long long &a) { return (*this != BigInteger(a)); }

    BigInteger operator&(const BigInteger &A) {
        BigInteger B = A;
        if(*this < B) return B.operator&(*this); 
        string s = toBinary();
        B.value = B.toBinary();
        int k = s.size() - B.value.size();
        for(int i=B.value.size()-1; i>=0; i--) {
            B.value[i] = ((s[i+k] - 48) & (B.value[i] - 48)) + 48;
        }
        B.toNumber(B.value);
        return B;
    }

    BigInteger operator&(const long long &a) { return (*this & BigInteger(a)); }

    BigInteger operator&=(const BigInteger &A) { return *this = (*this & A); }

    BigInteger operator&=(const long long &a) { return *this = (*this & a); }

    BigInteger operator|(const BigInteger &A) {
        BigInteger B = A;
        if(*this > B) return B.operator|(*this); 
        string s = toBinary();
        B.value = B.toBinary();
        int k = B.value.size() - s.size();
        for(int i=s.size()-1; i>=0; i--) {
            B.value[i+k] = ((s[i] - 48) | (B.value[i+k] - 48)) + 48;
        }
        B.toNumber(B.value);
        return B;
    }

    BigInteger operator|(const long long &a) { return (*this | BigInteger(a)); }

    BigInteger operator|=(const BigInteger &A) { return *this = (*this | A); }

    BigInteger operator|=(const long long &a) { return *this = (*this | a); }

    BigInteger operator^(const BigInteger &A) {
        BigInteger B = A;
        if(*this > B) return B.operator^(*this); 
        string s = toBinary();
        B.value = B.toBinary();
        int k = B.value.size() - s.size();
        for(int i=s.size()-1; i>=0; i--) {
            B.value[i+k] = ((s[i] - 48) ^ (B.value[i+k] - 48)) + 48;
        }
        B.toNumber(B.value);
        return B;
    }

    BigInteger operator^(const long long &a) { return (*this ^ BigInteger(a)); }

    BigInteger operator^=(const BigInteger &A) { return *this = (*this ^ A); }

    BigInteger operator^=(const long long &a) { return *this = (*this ^ a); }

    BigInteger operator<<(const BigInteger &A) {
        if(A.sign == 1) throw("Shifting by a negative number");
        if(A.value == "1") return (*this * 2ll);
        BigInteger ans = *this;
        string s = toBinary();
        for(BigInteger i=0; i<A; i++) s.push_back('0');
        ans.toNumber(s);
        return ans;
    }

    BigInteger operator<<(const long long &a) { return (*this << BigInteger(a)); }
    
    BigInteger operator<<=(const BigInteger &A) { return *this = (*this << A); }
    
    BigInteger operator<<=(const long long &a) { return *this = (*this << a); }

    BigInteger operator>>(const BigInteger &A) {
        if(A.sign == 1) throw("Shifting by a negative number");
        if(A.value == "1") return (*this / 2ll);
        BigInteger ans = *this;
        string s = toBinary();
        for(BigInteger i=0; i<A && s.size() > 0; i++) s.pop_back();
        ans.toNumber(s);
        return ans;
    }

    BigInteger operator>>(const long long &a) { return (*this >> BigInteger(a)); }

    BigInteger operator>>=(const BigInteger &A) { return *this = (*this >> A); }

    BigInteger operator>>=(const long long &a) { return *this = (*this >> a); }

    BigInteger operator!() {
        BigInteger B = *this;
        B.value = B.toBinary();
        B.allignRight(100ll);
        for(int i=B.value.size()-1; i>=0; i--) B.value[i] = 1 - B.value[i] + 96;
        B.toNumber(B.value);
        return B;
    }

    friend ostream &operator<<(ostream &os, const BigInteger &A) {
        if(A.sign) os << "-";
        os << A.value;
        return os;
    }

    friend istream &operator>>(istream &is, BigInteger &A) {
        is >> A.value;
        A.sign = (A.value[0] == '-'); 
        A.clean();
        return is;
    }

    void clean() {
        long unsigned int ctr = 0;
        ctr = (value[0] == '-');
        while(value[ctr] == '0' && ctr < value.size()) ctr++;
        if(ctr != value.size()) value = &value[ctr];
        else value = "0";
    }

    BigInteger absolute() { return BigInteger(value, 0); }

    bool isOdd() { return (value.back()-48) % 2; }
    
    bool isEven() { return !isOdd(); }

    string toBinary() {
        string s;
        BigInteger A = absolute();

        while(A > BigInteger()) {
            if(A.isOdd()) s.push_back('1');
            else s.push_back('0');
            A >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    void toNumber(string s) {
        value = "0";
        const bool SIGN = sign;
        long unsigned int n = 0;
        while(n < s.size()) {
            *this <<= 1;
            if(s[n++] == '1') *this += 1;
        }
        sign = SIGN;
    }
};

vector<BigInteger> A;
BigInteger t;

bool f(BigInteger m) {
    BigInteger p("0");
    for(BigInteger i : A) {
        p += (m / i);
    }
    return (p >= t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> t;
    A.resize(n);
    for(BigInteger &i : A) cin >> i;

    BigInteger ans("200000000000000000000");

    BigInteger l("1"), r = ans;
    while(l <= r) {
        BigInteger m = (l + r) / 2ll;
        if(f(m)) {
            ans = m;
            r = m - 1ll;
        }
        else {
            l = m + 1ll;
        }
    }

    cout << ans;
}