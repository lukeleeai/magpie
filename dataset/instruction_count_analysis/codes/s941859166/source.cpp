#include "stdc++.h"

using namespace std;



#define fi first

#define se second

#define pb push_back

#define sz(a) (int)(a).size()

#define mp(a, b) make_pair((a), (b))

using ll = long long;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

using vi = vector<int>;

using vvi = vector<vi>;

using vll = vector<ll>;

using vvll = vector<vll>;



const ll MOD = 1e9 + 7;

const ll INF = 1e18;

const ll IINF = INT_MAX;



const int N = 1e5 + 5;



vi fac[N];

ll cnt[N];



ll fpow(ll a, ll b) {

    if (b == 0) return 1;

    if (b == 1) return a % MOD;

    ll ret = fpow(a, b / 2);

    ret = (ret * ret) % MOD;

    if (b & 1) ret = (ret * a) % MOD;

    return ret;

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n, k;

    cin >> n >> k;



    for (int i = 1; i <= k; i++) {

        for (ll j = 1; j * j <= 1ll * i; j++) {

            if (i % j == 0) {

                fac[i].pb(j);

                if (j != i / j && j != 1) fac[i].pb(i / j);

            }

        }

    }

    

    ll ans = 0;

    for (int i = k; i >= 1; i--) {

        int banyak = k / i;

        cnt[i] = (cnt[i] + fpow(banyak, n)) % MOD; 

        ans = (ans + 1ll * i * cnt[i]) % MOD;

        // cout << i << ": ";

        for (int fa: fac[i]) {

            // cout << fa << ' ' << cnt[fa] << " | ";

            cnt[fa] = (cnt[fa] - cnt[i] + MOD) % MOD;

            // cout << cnt[fa] << ' ';

        }

        // cout << '\n';

    }

    cout << ans << '\n';

    return 0;

}