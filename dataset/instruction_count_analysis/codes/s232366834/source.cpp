#include <iostream>

#include <cstdio>

#include <string>

#include <algorithm>

#include <utility>

#include <cmath>

#include <vector>

#include <queue>

#include <set>

#include <map>

#include <numeric>

#include <functional>

using namespace std;

typedef long long ll;

typedef vector<ll> vl;

typedef vector<vector<ll>> vvl;

typedef pair<ll, ll> P;

#define rep(i, n) for(ll i = 0; i < n; i++)

#define exrep(i, a, b) for(ll i = a; i <= b; i++)

#define out(x) cout << x << endl

#define exout(x) printf("%.10f\n", x)

#define chmax(x, y) x = max(x, y)

#define chmin(x, y) x = min(x, y)

#define all(a) a.begin(), a.end()

#define rall(a) a.rbegin(), a.rend()

#define pb push_back

#define re0 return 0

const ll mod = 1000000007;

const ll INF = 1e16;

const ll MAX_N = 100010;



struct Eratosthenes {

    ll n;

    vector<ll> f;  // f[i] : iを割りきる最小の素因数

    vector<ll> primes;  // primes[i] : i番目(iは0-index)の素数

    Eratosthenes(ll n = 1): n(n), f(n+1) {

        f[0] = f[1] = -1;

        for(ll i = 2; i <= n; ++i) {

            if(f[i]) {

                continue;

            } 

            primes.pb(i);

            f[i] = i;

            for(ll j = i*i; j <= n; j += i) {

                if(!f[j]) {

                    f[j] = i;

                } 

            }

        }

    }

    bool isPrime(ll x) {  // xが素数ならtrueを返す

         return f[x] == x;

    }

    vector<ll> factorList(ll x) {  // xの素因数を重複も許して昇順に列挙したvectorを返す(x = 720 = (2^4)*(3^2)*(5^1)なら{2,2,2,2,3,3,5}のように)

        vector<ll> res;

        while(x != 1) {

            res.pb(f[x]);

            x /= f[x];

        }

        return res;

    }

    vector<P> factor(ll x) {  // (xのi番目の素因数, その素因数の個数)のvectorを返す(x = 720 = (2^4)*(3^2)*(5^1)なら{(2, 4), (3, 2), (5, 1)}のように)

        vector<ll> fL = factorList(x);

        if(fL.size() == 0) {

            return {};

        } 

        vector<P> res(1, make_pair(fL[0], 0));

        for(auto p : fL) {

            if(res.back().first == p) {

                res.back().second++;

            } 

            else {

                res.emplace_back(p, 1);

            }

        }

        return res;

    }

};



int main() {

    ll n;

    cin >> n;



    Eratosthenes era(MAX_N);

    map<ll, ll> mp;

    exrep(x, 1, n) {

        auto f = era.factor(x);

        for(auto p : f) {

            mp[p.first] += p.second;

        }

    }

    

    ll ans = 1;

    for(auto p : mp) {

        ans *= (p.second + 1);

        ans %= mod;

    }



    out(ans);

    re0;

}