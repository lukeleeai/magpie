#include "stdc++.h"

using namespace std;

constexpr int MOD = 1e9+7;

template<int mod> struct ModInt {

    int x;

    ModInt() : x(0) {}

    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }

    ModInt &operator-=(const ModInt &p) { if((x += mod-p.x) >= mod) x -= mod; return *this; }

    ModInt &operator*=(const ModInt &p) { x = (int)(1LL*x*p.x%mod); return *this; }

    ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const{

        int a = x, b = mod, u = 1, v = 0, t;

        while(b > 0) { t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }

        return ModInt(u);

    }

    ModInt pow(int e){

        long long a = 1, p = x;

        while(e > 0) {

            if(e%2 == 0) {p = (p*p) % mod; e /= 2;}

            else {a = (a*p) % mod; e--;}

        }

        return ModInt(a);

    }

    friend ostream &operator<<(ostream &os, const ModInt<mod> &p) {

        return os << p.x;

    }

    friend istream &operator>>(istream &is, ModInt<mod> &a) {

        long long x;

        is >> x;

        a = ModInt<mod>(x);

        return (is);

    }

};





int main() {

    using mint = ModInt<MOD>;

    int n, m;

    cin >> n >> m;

    vector<int> lx(n), ly(m);

    for (auto& e : lx) cin >> e;

    for (auto& e : ly) cin >> e;

    

    vector<int> x, y;

    for (int i = 0; i < n-1; i++) x.push_back(abs(lx[i] - lx[i+1]));

    for (int i = 0; i < m-1; i++) y.push_back(abs(ly[i] - ly[i+1]));

    

    mint sx = 0, sy = 0;

    for (long long i = 0; i < n-1; i++) {

        mint res = ((i+1) * (n - (i+1)));

        sx += (res * x[i]);

    }

    for (long long i = 0; i < m-1; i++) {

        mint res = ((i+1) * (m - (i+1)));

        sy += (res * y[i]);

    }

    

    mint ans = sx * sy;

    cout << ans << endl;

    return 0;

}
