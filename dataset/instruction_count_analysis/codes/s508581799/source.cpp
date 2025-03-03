#include <iostream>

#include <cstdio>

#include <cassert>

#include <cstring>

#include <vector>

#include <valarray>

#include <array>

#include <queue>

#include <set>

#include <unordered_set>

#include <map>

#include <unordered_map>

#include <algorithm>

#include <cmath>

#include <complex>

#include <random>

 

using namespace std;

using ll = long long;

using ull = unsigned long long;

template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

template<class T> using V = vector<T>;



ll gcd(ll _a, ll _b) {

    ull a = abs(_a), b = abs(_b);

    while (b) {

        swap(a, b);

        b %= a;

    }

    return a;

}



/// g:gcd(a, b), ax+by=g

struct EG { ll g, x, y; };

EG ext_gcd(ll a, ll b) {

    if (b==0) {

        if (a >= 0) return EG{a, 1, 0};

        else return EG{-a, -1, 0};

    } else {

        auto e = ext_gcd(b, a%b);

        return EG{e.g, e.y, e.x-a/b*e.y};

    }

}



ll inv_mod(ll x, ll md) {

    auto z = ext_gcd(x, md).x;

    return (z % md + md) % md;

}



template<class T, class U>

T pow_mod(T x, U n, T md) {

    T r = 1 % md;

    x %= md;

    while (n) {

        if (n & 1) r = (r * x) % md;

        x = (x * x) % md;

        n >>= 1;

    }

    return r;

}



bool is_prime(ll n) {

    if (n <= 1) return false;

    if (n == 2) return true;

    if (n % 2 == 0) return false;

    ll d = n-1;

    while (d % 2 == 0) d /= 2;

    vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37}; // n < 2^64

    for (ll a: alist) {

        if (n <= a) break;

        ll t = d;

        ll y = pow_mod<__int128_t>(a, t, n); //over

        while (t != n-1 && y != 1 && y != n-1) {

            y = __int128_t(y)*y % n; //flow

            t <<= 1;

        }

        if (y != n-1 && t % 2 == 0) {

            return false;

        }

    }

    return true;

}



ll pollard_single(ll n){

    auto f = [&](ll x){ return (__int128_t(x)*x + 1) % n; };

    if (is_prime(n)) return n;

    if (n % 2 == 0) return 2;

    ll st = 0;

    while (true) {

        st++;

        ll x = st, y = f(x);

        while (true) {

            ll p = gcd((y-x+n), n);

            if (p == 0 || p == n) break;

            if (p != 1) return p;

            x = f(x);

            y = f(f(y));

        }

    }

}



V<ll> pollard(ll n) {

    if (n == 1) return {};

    ll x = pollard_single(n);

    if (x == n) return {x};

    V<ll> le = pollard(x);

    V<ll> ri = pollard(n/x);

    le.insert(end(le), begin(ri), end(ri));

    return le;

}



 

ll mul(ll a, ll b) {

    if (TEN(12)/a < b) return TEN(12);

    return a*b;

}

 

int main() {

    using P = pair<ll, ll>;

    map<ll, P> g;

    int n;

    scanf("%d", &n);

    bool one = false;

    for (int i = 0; i < n; i++) {

        ll s;

        scanf("%lld", &s);

        auto facv = pollard(s);

        map<ll, int> fac;

        for (auto d: facv) fac[d]++;

//        map<ll, int> fac = pr.fact(s);

        ll d0 = 1, d1 = 1;

        for (auto p: fac) {

            p.second %= 3;

            if (p.second == 1) {

                d0 = mul(d0, p.first);

                d1 = mul(d1, p.first);

                d1 = mul(d1, p.first);

            } else if (p.second == 2) {

                d0 = mul(d0, p.first);

                d0 = mul(d0, p.first);

                d1 = mul(d1, p.first);

            }

        }

        if (d0 == 1) {

            one = true;

            continue;

        }

        if (d0 < d1) {

            g[d0].first++;

        } else {

            g[d1].second++;

        }

    }

 

    int ans = 0;

    for (auto p: g) {

        ans += max(p.second.first, p.second.second);

    }

    cout << ans + (one ? 1 : 0) << endl;

    return 0;

}
