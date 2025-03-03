#include <iostream>

#include <vector>

#include <cmath>

#include <iomanip>

#include <algorithm>



using namespace std;



template<typename T> class Rational {

private:

    static Rational make(const T& x, const T& y){

        Rational m; return m.num = x, m.den = y, m;

    }

public:

    friend ostream& operator<<(ostream& os, const Rational& rn) {

        return (os << rn.num << " / " << rn.den);

    }

    Rational& operator=(T val){ return *this = Rational(val); }

    bool operator<(const Rational& val) const { return num*val.den < den*val.num; }

    bool operator<(const T val) const { return *this < Rational(val); }

    friend bool operator<(const T val1, const Rational& val2){ return Rational(val1) < val2; }

    bool operator>(const Rational& val) const { return val < *this; }

    bool operator>(const T val) const { return *this > Rational(val); }

    friend bool operator>(const T val1, const Rational& val2){ return Rational(val1) > val2; }

    bool operator<=(const Rational& val) const { return !(*this > val); }

    bool operator<=(const T val) const { return *this <= Rational(val); }

    friend bool operator<=(const T val1, const Rational& val2){ return Rational(val1) <= val2; }

    bool operator>=(const Rational& val) const { return !(*this < val); }

    bool operator>=(const T val) const { return *this >= Rational(val); }

    friend bool operator>=(const T val1, const Rational& val2){ return Rational(val1) >= val2; }

    bool operator==(const Rational& val) const { return num*val.den == den*val.num; }

    bool operator==(const T val) const { return *this == Rational(val); }

    friend bool operator==(const T val1, const Rational& val2){ return Rational(val1) == val2; }

    bool operator!=(const Rational& val) const { return !(*this == val); }

    bool operator!=(const T val) const { return *this != Rational(val); }

    friend bool operator!=(const T val1, const Rational& val2){ return Rational(val1) != val2; }

    explicit operator bool() const noexcept { return num; }

    bool operator!() const noexcept { return !static_cast<bool>(*this); }

    Rational operator+() const { return *this; }

    Rational operator-() const { return make(-num, den); }

    friend Rational abs(const Rational& val){ return make(abs(val.num), val.den); }

    Rational operator+(const Rational& val) const { return make(num*val.den+val.num*den, den*val.den); }

    Rational operator+(T val) const { return *this + Rational(val); }

    friend Rational operator+(T a, const Rational& b){ return b + a; }

    Rational& operator+=(const Rational& val){ return *this = *this + val; }

    Rational& operator+=(const T& val){ return *this = *this + val; }

    Rational& operator++(){ return *this += 1; }

    Rational operator++(int){ return make(num + den, den); }

    Rational operator-(const Rational& val) const { return make(num*val.den-val.num*den, den*val.den); }

    Rational operator-(T val) const { return *this - Rational(val); }

    friend Rational operator-(T a, const Rational& b){ return Rational(a) - b; }

    Rational& operator-=(const Rational& val){ return *this = *this - val; }

    Rational& operator-=(const T& val){ return *this = *this - val; }

    Rational& operator--(){ return *this -= 1; }

    Rational operator--(int){ return make(num - den, den); }

    Rational operator*(const Rational& val) const { return make(num*val.num, den*val.den); }

    Rational operator*(T val) const { return *this * Rational(val); }

    friend Rational operator*(T a, const Rational& b){ return b * a; }

    Rational& operator*=(const Rational& val){ return *this = *this * val;}

    Rational& operator*=(const T& val){ return *this = *this * val; }

    Rational operator/(const Rational& val) const { return make(num*val.den, den*val.num); }

    Rational operator/(T val) const { return *this / Rational(val); }

    friend Rational operator/(T a, const Rational& b){ return Rational(a) / b; }

    Rational& operator/=(const Rational& val){ return *this / val; }

    Rational& operator/=(const T& val){ return *this = *this / val; }



    T num, den;



    Rational(){}

    Rational(T num_) : num(num_), den(1){}

    Rational(T num_, T den_) : num(num_), den(den_){ if(den < 0) num = -num, den = -den; }

};



int p, q, a, n;

int rec(Rational<int> f, int con, int bunbomax, int mul) {

    if (con == 0) { // 残り 0 回だったら f = 0 じゃなきゃダメ

        if (f == 0) return 1;

        else return 0;

    }

    if (f == 0) return 1; // 0 になったら終わり



    int res = 0;

    for (int i = a/mul; i >= bunbomax; --i) {

        if (f < Rational<int>(1, i)) break;

        res += rec(f - Rational<int>(1, i), con - 1, i, mul * i);

    }

    return res;

}





int main() {

    while (cin >> p >> q >> a >> n, n) {

        Rational<int> start(p, q);

        int res = rec(start, n, 1, 1);

        cout << res << endl;

    }

}


