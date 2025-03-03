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



// 素因数分解。計算量はO(√n)

map<ll, ll> primefactor(ll n) {  // (nのi番目の素因数, その素因数の個数)のmapを返す(n = 720 = (2^4)*(3^2)*(5^1)なら{(2, 4), (3, 2), (5, 1)}のように)

    map<ll, ll> res;

    for(ll i = 2; i*i <= n; i++) {

        while(n%i == 0) {

            res[i]++;

            n /= i;

        }

    }

    if(n != 1) {

        res[n] = 1;

    }

    return res;

}



int main() {

    ll n;

    cin >> n;



    map<ll, ll> mp;

    exrep(x, 1, n) {

        map<ll, ll> mp2 = primefactor(x);

        for(auto p : mp2) {

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