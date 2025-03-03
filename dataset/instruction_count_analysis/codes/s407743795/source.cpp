// Why am I so dumb? :c

#include "stdc++.h"



#define pb push_back

#define mp make_pair



#define all(x) (x).begin(), (x).end()



#define fi first

#define se second



using namespace std;



typedef long long ll;



const int MAXN = 50 + 5;



int a[MAXN], b[MAXN];



ll pw[MAXN];



ll ans;



int n;



void pre() {

    pw[0] = 1;



    for (int i = 1; i <= 50; ++i) {

        pw[i] = (pw[i - 1] << 1);

    }

}



bool bit(ll m, int ps) {

    return m & pw[ps];

}



bool check(set<int> S) {

    for (int i = 1; i <= n; ++i) {

        ll m = pw[a[i]];



        for (auto it = S.rbegin(); it != S.rend(); ++it) {

            int x = *it;



            for (int p = 1; p <= 50; ++p) {

                if (bit(m, p)) {

                    m |= pw[p % x];

                }

            }

        }



        if (!bit(m, b[i])) {

            return 0;

        }

    }



    return 1;

}



void solve() {

    scanf("%d", &n);



    for (int i = 1; i <= n; ++i) {

        scanf("%d", &a[i]);

    }



    for (int i = 1; i <= n; ++i) {

        scanf("%d", &b[i]);

    }



    set<int> S;



    for (int i = 1; i <= 50; ++i) {

        S.insert(i);

    }



    if (!check(S)) {

        printf("-1\n");

        return;

    }



    for (int cur = 50; cur > 0; --cur) {

        S.erase(cur);



        if (!check(S)) {

            S.insert(cur);

        }

    }



    for (int x : S) {

        ans += pw[x];

    }



    printf("%lld\n", ans);

}



int main() {

    int tt = 1;



    pre();



    while (tt--) {

        solve();

    }



    return 0;

}