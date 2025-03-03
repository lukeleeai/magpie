#include <iostream>

#include <algorithm>

#include <map>

#include <set>

#include <queue>

#include <stack>

#include <numeric>

#include <bitset>

#include <cmath>



static const int MOD = 1000000007;

using ll = long long;

using u32 = unsigned;

using u64 = unsigned long long;

using namespace std;



template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;



template<u32 M = 1000000007>

struct modint{

    u32 val;

    modint(): val(0){}

    template<typename T>

    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}



    modint pow(ll k) const {

        modint res(1), x(val);

        while(k){

            if(k&1) res *= x;

            x *= x;

            k >>= 1;

        }

        return res;

    }

    template<typename T>

    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}

    modint inv() const {return pow(M-2);}

    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}

    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}

    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}

    modint& operator/=(modint a){return (*this) *= a.inv();}

    modint operator+(modint a) const {return modint(val) +=a;}

    modint operator-(modint a) const {return modint(val) -=a;}

    modint operator*(modint a) const {return modint(val) *=a;}

    modint operator/(modint a) const {return modint(val) /=a;}

    modint operator-(){return modint(M-val);}

    bool operator==(const modint a) const {return val == a.val;}

    bool operator!=(const modint a) const {return val != a.val;}

    bool operator<(const modint a) const {return val < a.val;}

};

using mint = modint<MOD>;





class Factorial {

    vector<mint> facts, factinv;

public:

    explicit Factorial(int n) : facts(n+1), factinv(n+1) {

        facts[0] = 1;

        for (int i = 1; i < n+1; ++i) facts[i] = facts[i-1] * mint(i);

        factinv[n] = facts[n].inv();

        for (int i = n-1; i >= 0; --i) factinv[i] = factinv[i+1] * mint(i+1);

    }

    mint fact(int k) const {

        if(k >= 0) return facts[k]; else return factinv[-k];

    }

    mint operator[](const int &k) const {

        if(k >= 0) return facts[k]; else return factinv[-k];

    }

    mint C(int p, int q) const {

        if(q < 0 || p < q) return 0;

        return facts[p] * factinv[q] * factinv[p-q];

    }

    mint P(int p, int q) const {

        if(q < 0 || p < q) return 0;

        return facts[p] * factinv[p-q];

    }

    mint H(int p, int q) const {

        if(p < 0 || q < 0) return 0;

        return q == 0 ? 1 : C(p+q-1, q);

    }

};

Factorial f(100000);

void solve(){

    int n;

    cin >> n;

    if(n < 5) {

        puts("0");

        return;

    }

    n -= 5;

    mint ans = 0;

    if(n <= 50000){

        for (int i = 0; i <= 11; ++i) {

            if(n < i || (n-i)&1) continue;

            ans += f.C(11, i)*f.C((n-i)/2+15, 15);

        }

    }else {

        auto comb = [&](int a) -> mint{ // binom(a+15, 15);

            mint ans = 1;

            for (int i = 1; i <= 15; ++i) {

                ans *= mint(a+i);

                ans /= mint(i);

            }

            return ans;

        };

        for (int i = 0; i <= 11; ++i) {

            if(n < i || (n-i)&1) continue;

            ans += f.C(11, i)*comb((n-i)/2);

        }

    }

    cout << ans.val << "\n";

}



int main() {

    int t;

    cin >> t;

    while(t--){

        solve();

    }

    return 0;

}