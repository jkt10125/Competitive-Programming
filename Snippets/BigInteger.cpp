#include <bits/stdc++.h>
using namespace std;

class BigInteger {
public:
    string value;
    bool sign;

    BigInteger (string Value = "", bool Sign = 0) {
        value = Value;
        sign = Sign;
        clean();
    }

    BigInteger (long long a) {
        sign = (a < 0);
        a = abs (a);
        value = to_string(a);  
    }
    
    BigInteger &operator = (const string &rhs) {
        return *this = BigInteger (rhs);
    }

    BigInteger &operator = (const long long &rhs) {
        return *this = BigInteger (rhs);
    }

    void allignRight (const long long a) {
        string zeroes;
        for (int i = 0; i < a; i++) {
            zeroes.push_back('0');
        }
        value = zeroes + value;
    }

    void allignLeft (const long long a) {
        for (int i = 0; i < a; i++) {
            value.push_back('0');
        }
    }

    BigInteger operator - () {
        return BigInteger (value, !sign);
    }

    BigInteger &operator ++ (int) {
        return (*this += 1);
    }

    BigInteger &operator ++ () {
        return (*this += 1);
    }

    BigInteger &operator -- (int) {
        return (*this -= 1);
    }

    BigInteger &operator -- () {
        return (*this -= 1);
    }

    BigInteger operator + (const BigInteger &rhs) {
        BigInteger B = rhs;
        if (B.sign) {
            if (!sign) {
                return (*this - (-B));
            }
            else {
                return -(-(*this) + (-B));
            }
        }
        if (sign) {
            return -(-(*this) - B);
        }

        if ((*this) < B) {
            return B.operator + (*this);
        }

        int numOfZeroes = value.size() - B.value.size();
        B.allignRight (numOfZeroes);

        bool carry = 0;
        for (int i = B.value.size() - 1; i >= 0; i--) {
            int val = B.value[i] + value[i] + carry - 96;
            B.value[i] = val % 10 + 48;
            carry = val / 10;
        }

        if (carry) {
            B.value = "1" + B.value;
        }

        return B;
    }

    BigInteger operator + (const long long &rhs) {
        return (*this + BigInteger (rhs));
    }

    BigInteger &operator += (const long long &rhs) {
        return (*this = (*this + rhs));
    }

    BigInteger &operator += (const BigInteger &rhs) {
        return (*this = (*this + rhs));
    }

    BigInteger operator - (const BigInteger &rhs) {
        BigInteger B = rhs;
        if(B.sign) { 
            if(!sign) {
                return (*this + (-B));
            } 
            else {
                return -(-(*this) - (-B));
            }
        }
        if (sign) {
            return -(-(*this) + B);
        }
        
        if ((*this) < B) {
            return -(B.operator - (*this));
        }

        int numOfZeroes = value.size() - B.value.size();
        B.allignRight (numOfZeroes);

        bool carry = 0;
        for (int i = B.value.size() - 1; i >= 0; i--) {
            int val = value[i] - B.value[i] - carry;
            carry = 0;
            if (val < 0) {
                val += 10;
                carry = 1;
            }
            B.value[i] = val + 48;
        }
        B.clean ();
        return B;
    }

    BigInteger operator - (const long long &rhs) {
        return (*this - BigInteger(rhs));
    }

    BigInteger &operator -= (const long long &rhs) {
        return (*this = (*this - rhs));
    }

    BigInteger &operator -= (const BigInteger &rhs) {
        return *this = (*this - rhs);
    }

    BigInteger operator * (const BigInteger &rhs) {
        BigInteger ans = 0ll;
        if (rhs.value == "0") return BigInteger ();
        if (value == "0") return BigInteger ();
        for (int i = rhs.value.size() - 1; i >= 0; i--) {
            BigInteger B = *this;
            int carry = 0, sum;
            for (int j = value.size() - 1; j >= 0; j--) {
                sum = (value[j] - 48) * (rhs.value[i] - 48) + carry;
                B.value[j] = sum % 10 + 48;
                carry = sum / 10;
            }
            if (carry) {
                B.value = char(carry + 48) + B.value;
            }
            B.allignLeft (rhs.value.size() - i - 1);
            ans += B;
        }
        ans.sign = sign ^ rhs.sign;
        return ans;
    }

    BigInteger operator * (const long long &rhs) {
        return (*this * BigInteger(rhs));
    }

    BigInteger &operator *= (const long long &rhs) {
        return *this = (*this * rhs);
    }

    BigInteger &operator *= (const BigInteger &rhs) {
        return *this = (*this * rhs);
    }

    BigInteger operator / (const BigInteger &rhs) {
        if (rhs.value == "0") {
            throw("Division by Zero");
        }
        BigInteger ans = rhs;
        if (absolute() < ans.absolute()) {
            return BigInteger ();
        }
        ans = BigInteger ();
        BigInteger tmp = 0ll;
        long unsigned int idx = 0;
        while (tmp < rhs) {
            tmp = tmp * 10ll + (value[idx++] - 48);
        }
        while (idx < value.size()) {
            int ctr = 0;
            while (tmp >= rhs) {
                tmp -= rhs; ctr++;
            }
            tmp = tmp * 10ll + (value[idx++] - 48);
            ans = ans * 10ll + ctr;
        }
        ans = ans * 10ll;
        while (tmp >= rhs) {
            tmp -= rhs;
            ans++;
        }
        ans.sign = sign ^ rhs.sign;
        return ans;
    }

    BigInteger operator / (const long long &rhs) {
        return (*this / BigInteger(rhs));
    }

    BigInteger &operator /= (const long long &rhs) {
        return *this = (*this / rhs);
    }

    BigInteger &operator /= (const BigInteger &rhs) {
        return *this = (*this / rhs);
    }

    BigInteger operator % (const BigInteger &rhs) {
        if(rhs.value == "0") {
            throw("Modulo by Zero");
        }
        return *this - *this / rhs * rhs;
    }

    BigInteger operator % (const long long &rhs) {
        return (*this % BigInteger(rhs));
    }

    BigInteger &operator %= (const long long &rhs) {
        return *this = (*this % rhs);
    }

    BigInteger &operator %= (const BigInteger &rhs) {
        return *this = (*this % rhs);
    }

    bool operator > (const BigInteger &rhs) const {
        if (sign < rhs.sign) return true;
        if (sign > rhs.sign) return false;
        if (value.size() > rhs.value.size()) return (!sign);
        if (value.size() == rhs.value.size()) {
            if (value > rhs.value) return (!sign);
        }
        return (sign);
    }

    bool operator > (const long long &rhs) {
        return (*this > BigInteger(rhs));
    }

    bool operator >= (const BigInteger &rhs) {
        return (*this > rhs) ? true : (*this == rhs);
    }

    bool operator >= (const long long &rhs) {
        return (*this >= BigInteger(rhs));
    }

    bool operator < (const BigInteger &rhs) {
        return (rhs.operator > (*this));
    }

    bool operator < (const long long &rhs) {
        return (*this < BigInteger(rhs));
    }

    bool operator <= (const BigInteger &rhs) {
        return (*this < rhs) ? true : (*this == rhs);
    }

    bool operator <= (const long long &rhs) {
        return (*this <= BigInteger(rhs));
    }

    bool operator == (const BigInteger &rhs) {
        return (value == rhs.value && sign == rhs.sign);
    }

    bool operator == (const long long &rhs) {
        return (*this == BigInteger(rhs));
    }

    bool operator != (const BigInteger &rhs) {
        return !(*this == rhs);
    }

    bool operator != (const long long &rhs) {
        return (*this != BigInteger(rhs));
    }

    BigInteger operator & (const BigInteger &rhs) {
        BigInteger B = rhs;
        if (*this < B) {
            return B.operator & (*this); 
        }
        string s = toBinary ();
        B.value = B.toBinary ();
        int k = s.size() - B.value.size();
        for (int i = B.value.size() - 1; i >= 0; i--) {
            B.value[i] = ((s[i + k] - 48) & (B.value[i] - 48)) + 48;
        }
        B.toNumber (B.value);
        return B;
    }

    BigInteger operator & (const long long &rhs) {
        return (*this & BigInteger(rhs));
    }

    BigInteger &operator &= (const BigInteger &rhs) {
        return *this = (*this & rhs);
    }

    BigInteger &operator &= (const long long &rhs) {
        return *this = (*this & rhs);
    }

    BigInteger operator | (const BigInteger &rhs) {
        BigInteger B = rhs;
        if (*this > B) {
            return B.operator | (*this);
        } 
        string s = toBinary ();
        B.value = B.toBinary ();
        int k = B.value.size() - s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            B.value[i + k] = ((s[i] - 48) | (B.value[i + k] - 48)) + 48;
        }
        B.toNumber(B.value);
        return B;
    }

    BigInteger operator | (const long long &rhs) {
        return (*this | BigInteger(rhs));
    }

    BigInteger &operator |= (const BigInteger &rhs) {
        return *this = (*this | rhs);
    }

    BigInteger &operator |= (const long long &rhs) {
        return *this = (*this | rhs);
    }

    BigInteger operator ^ (const BigInteger &rhs) {
        BigInteger B = rhs;
        if (*this > B) return B.operator ^ (*this); 
        string s = toBinary ();
        B.value = B.toBinary ();
        int k = B.value.size() - s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            B.value[i + k] = ((s[i] - 48) ^ (B.value[i + k] - 48)) + 48;
        }
        B.toNumber(B.value);
        return B;
    }

    BigInteger operator ^ (const long long &rhs) {
        return (*this ^ BigInteger(rhs));
    }

    BigInteger &operator ^= (const BigInteger &rhs) {
        return *this = (*this ^ rhs);
    }

    BigInteger &operator ^= (const long long &rhs) {
        return *this = (*this ^ rhs);
    }

    BigInteger operator << (const BigInteger &rhs) {
        if (rhs.sign == 1) {
            throw("Shifting by a negative number");
        }
        if (rhs.value == "1") {
            return (*this * 2ll);
        }
        BigInteger ans = *this;
        string s = toBinary ();
        for (BigInteger i=0; i<rhs; i++) {
            s.push_back('0');
        }
        ans.toNumber (s);
        return ans;
    }

    BigInteger operator << (const long long &rhs) {
        return (*this << BigInteger(rhs));
    }
    
    BigInteger &operator <<= (const BigInteger &rhs) {
        return *this = (*this << rhs);
    }
    
    BigInteger &operator <<= (const long long &rhs) {
        return *this = (*this << rhs);
    }

    BigInteger operator >> (const BigInteger &rhs) {
        if (rhs.sign == 1) {
            throw("Shifting by a negative number");
        }
        if (rhs.value == "1") {
            return (*this / 2ll);
        }
        BigInteger ans = *this;
        string s = toBinary ();
        for (BigInteger i = 0; i < rhs && s.size() > 0; i++) {
            s.pop_back();
        }
        ans.toNumber(s);
        return ans;
    }

    BigInteger operator >> (const long long &rhs) {
        return (*this >> BigInteger(rhs));
    }

    BigInteger &operator >>= (const BigInteger &rhs) {
        return *this = (*this >> rhs);
    }

    BigInteger &operator >>= (const long long &rhs) {
        return *this = (*this >> rhs);
    }

    BigInteger operator ! () {
        BigInteger B = *this;
        B.value = B.toBinary();
        B.allignRight (100ll);
        for (int i = B.value.size() - 1; i >= 0; i--) {
            B.value[i] = 1 - B.value[i] + 96;
        }
        B.toNumber (B.value);
        return B;
    }

    friend ostream &operator << (ostream &os, const BigInteger &A) {
        if (A.sign) os << "-";
        os << A.value;
        return os;
    }

    friend istream &operator >> (istream &is, BigInteger &A) {
        is >> A.value;
        A.sign = (A.value[0] == '-'); 
        A.clean ();
        return is;
    }

    void clean () {
        long unsigned int ctr = 0;
        ctr = (value[0] == '-');
        while (value[ctr] == '0' && ctr < value.size()) {
            ctr++;
        }
        if (ctr != value.size()) {
            value = &value[ctr];
        }
        else value = "0";
    }

    BigInteger absolute() {
        return BigInteger(value, 0);
    }

    bool isOdd() {
        return (value.back()-48) % 2;
    }
    
    bool isEven() {
        return !isOdd();
    }

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