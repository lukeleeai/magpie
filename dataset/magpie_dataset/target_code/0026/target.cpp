#include "stdc++.h"



#define Solved int main()

#define pb push_back

#define mp make_pair

#define F first

#define S second

#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define forn(i, n) for(int i = 1; i <= n; i++)

#define rep(i, x, y) for(int i = x; i <= y; i++)

#define sz(x) (int)x.size()

#define pii pair<int, int>

#define ll long long

#define ull unsigned long long

#define ld long double

#define mii map<int, int>

#define all(x) x.begin(), x.end()

using namespace std;



inline ll bip(ll x,ll n,ll mod){ll res=1;while(n){if(n&1){res=(res*x)%mod;}x=(x*x)%mod;n>>=1;}return res;}



const int maxn = 1e9;

const ll inf = 1e18;

const int mod = 998244353;

//const int mod = 1e9 + 7;

const int N = 1e5 + 10;



int n, k;

ll a[N];

ll dp[N];



void solve() {

    cin >> n >> k;



    for (int i = 1; i <= n; i++)

        cin >> a[i];



    dp[2] = abs(a[2] - a[1]);

    for (int i = 3; i <= n; i++) {

        dp[i] = inf;

        for (int j = 1; j <= k; j++) {

            if (i > j) dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));

        }

    }

    cout << dp[n];

}



Solved {

    SpeedForce;

	int tt = 1;

    //cin >> tt;

	while (tt--) {

		solve();

		cout << '\n';

	}



}
