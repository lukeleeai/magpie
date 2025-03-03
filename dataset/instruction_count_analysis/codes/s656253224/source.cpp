#include "stdc++.h"

#define rep(i, a, n) for(int i = a; i < n; i++)

#define REP(i, n) rep(i, 0, n)

#define repb(i, a, b) for(int i = a; i >= b; i--)

#define all(a) a.begin(), a.end()

#define int long long

#define chmax(x, y) x = max(x, y)

#define chmin(x, y) x = min(x, y)

using namespace std;

typedef pair<int, int> P;

const int mod = 1000000007;

const int INF = 1e12;



struct RollingHash {

    typedef long long ll;

    typedef pair<ll,ll> pll;



    ll base1, base2, mod1, mod2;

    vector<ll> hash1, hash2, pow1, pow2;



    RollingHash() : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}



    void init(const string &s) {

        int n = s.size();



        hash1.assign(n+1,0);

        hash2.assign(n+1,0);

        pow1.assign(n+1,1);

        pow2.assign(n+1,1);



        for(int i=0;i<n;i++) {

            hash1[i+1] = (hash1[i]+s[i]) * base1 % mod1;

            hash2[i+1] = (hash2[i]+s[i]) * base2 % mod2;

            pow1[i+1] = pow1[i] * base1 % mod1;

            pow2[i+1] = pow2[i] * base2 % mod2;

        }

    }

    //[l, r)

    pll get(int l,int r) {

        ll t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;

        ll t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;

        return make_pair(t1, t2);

    }



    RollingHash::pll concat(pll h1, pll h2, int h2_len) {

        return make_pair((h1.first*pow1[h2_len]+h2.first)%mod1, (h1.second*pow2[h2_len]+h2.second)%mod2);

    }



};



string s[310], t[310];

RollingHash rs[310], rt[310];

P rsh[310][310], rth[310][310];



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    int n;

    cin >> n;

    rep(i, 0, n){

        cin >> s[i];

        rep(j, 0, n) t[j] += s[i][j];

    }

    rep(i, 0, n){

        s[i] += s[i];

        t[i] += t[i];

        rs[i].init(s[i]);

        rt[i].init(t[i]);

        rep(j, 0, n){

            rsh[i][j] = rs[i].get(j, j + n);

            rth[i][j] = rt[i].get(j, j + n);

        }

    }

    int ans = 0;

    rep(i, 0, n){

        rep(j, 0, n){

            bool f = true;

            rep(k, 0, n){

                if(rsh[(i + k) % n][j] != rth[(j + k) % n][i]) f = false;

            }

            if(f) ans++;

        }

    }

    cout << ans << endl;

}