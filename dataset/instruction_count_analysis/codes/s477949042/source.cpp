#include "stdc++.h"



using namespace std;



#define endl "\n"

#define ll long long

#define ld long double

#define ull unsigned long long

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define for1n(i, n) for (int i = 1; i < (int)(n); ++i)

#define forln(i, n) for (long long i = 0; i < (long long)(n); ++i)

#define forl1n(i, n) for (long long i = 1; i < (long long)(n); ++i)



const ld EPS = 1e-9;

#define mod 1000000007



ll GetMod(ll n, ll z) { // func to get mod for positive num and negitive nums

    return (n % z + z) % z;

}



//          U   R  D  L

int dx[] = {-1, 0, 1, 0, -1, +1, +1, -1}; // dx for the 8 adjacent places in matrix

int dy[] = {0, 1, 0, -1, +1, +1, -1, -1};// dy for the 8 adjacent places in matrix



map<ll, ll> m;



ll fp(ll base, ll exp) {

    if (exp == 0)

        return 1;

    ll ans = fp(base, exp / 2);

    ans = (ans * ans) % mod;

    if (exp % 2 != 0)

        ans = (ans * (base % mod)) % mod;

    return ans;

}



void GetPrime(ll a) {

    map<ll, ll> m1;



    for (ll i = 2; i * i <= a; i++) {

        while (a % i == 0) {

            m1[i]++;

            a /= i;

        }

    }

    if (a > 1)m1[a]++;





    for (auto s = m1.begin(); s != m1.end(); s++) {

        ll dig = s->first;

        ll poww = s->second;

        if (m[dig] != 0) {

            m[dig] = max(poww, m[dig]);



        } else {

            m[dig] = poww;



        }



    }





}



ll GetLCM() {

    ll ans = 1;

    for (auto s = m.begin(); s != m.end(); s++) {

        ans = (ans * fp(s->first, s->second)) % mod;

    }

    return ans;

}



vector<ll> v;



int main() {



    ios_base::sync_with_stdio(false), cin.tie(NULL);

    ll n;

    cin >> n;

    v.resize(n);

    forn(i, n)cin >> v[i];

    forn(i, n) {

        GetPrime(v[i]);

    }

    ll res = GetLCM();





    ll sum = 0;

    forn(i, n) {

        ll z = (res * fp(v[i], mod - 2)) % mod;



        sum = (sum + z) % mod;

    }

    cout << sum;



}