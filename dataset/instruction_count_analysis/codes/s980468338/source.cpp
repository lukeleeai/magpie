#include "bits/stdc++.h"

using namespace std;



typedef long long ll;

typedef vector<int> vi;

typedef vector<vi> mat;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)

#define rep(i,n) FOR(i,0,n)

#define mset(a,x) memset(a,x,sizeof(a))



const int MOD = int(1e9 + 7);

ll n;



int main() {

    cin >> n;

    vector<ll> t(n), a(n);

    rep(i, n) scanf("%lld", &t[i]);

    rep(i, n) scanf("%lld", &a[i]);



    if(t[n - 1] != a[0]) {

        puts("0"); return 0;

    }



    if(n == 1) {

        puts(t[0] == a[0] ? "1" : "NO");

        return 0;

    }



    vector<ll> mi(n, 1145141919810);

    mi[0] = mi[n - 1] = 1;

    FOR(i, 1, n-1) {

        if(t[i] != t[i - 1]) {

            mi[i] = 1;

        }

    }



    for(int i = n - 2; i >= 1; --i) {

        if(mi[i] == 1 && t[i] > a[i]) {

            puts("0"); return 0;

        }

        if(a[i] != a[i + 1]) mi[i] = 1;

        if(mi[i] == 1) continue;

        mi[i] = min(t[i], a[i]);

    }



    ll ans = 1;

    rep(i, n) {

        ans *= mi[i];

        ans %= MOD;

    }



    cout << ans << endl;



    return 0;

}