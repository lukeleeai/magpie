// writer: w33z8kqrqk8zzzx33

#include "stdc++.h"

using namespace std;

 

#define iter(i, a, b) for(int i=(a); i<(b); i++)

#define rep(i, a) iter(i, 0, a)

#define rep1(i, a) iter(i, 1, (a)+1)

#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl

#define all(a) a.begin(), a.end()

#define fi first

#define se second

#define pb push_back

#define mp make_pair

 

using ll=long long;

using pii=pair<int, int>;

//#define int ll

const int MOD = 1000000007;



int fac[2000006], inv[2000006], invfac[2000006];



int calc(int r, int c) {

    // -1 + r+c+2 choose r+1

    return ((1ll * fac[r+c+2] * invfac[r+1] % MOD * invfac[c+1] % MOD) + MOD - 1) % MOD;

}



signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

    fac[0] = 1; invfac[0] = 1;

    inv[0] = 1; inv[1] = 1;

    rep1(i, r2+c2+2) {

        if(i != 1) inv[i] = 1ll * inv[MOD % i] * (MOD - MOD/i) % MOD;

        fac[i] = 1ll * fac[i-1] * i % MOD;

        invfac[i] = 1ll * invfac[i-1] * inv[i] % MOD;

    }

    cout << (4ll*MOD + calc(r2, c2) - calc(r1-1, c2) - calc(r2, c1-1) + calc(r1-1, c1-1)) % MOD << endl;

}


