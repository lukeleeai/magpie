#include"stdc++.h"

#define rep(i, n) for(int i = 1; i <= n; ++i)

using namespace std;

#define int long long

const int maxn = 1020;

int n, x[maxn], y[maxn], odd, even;

namespace sol{

    int a[59], k, ham;

    const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

    const char dr[] = "DULR";

    void dfs(int x, int y, int cur) {

        if(cur == 0) return;

        int chg = 1LL << (cur - 1);

        for(int dir = 0; dir < 4; ++dir) {

            int xf = x + dx[dir] * chg, yf = y + dy[dir] * chg;

            if(abs(xf) + abs(yf) < (1LL << (cur - 1)) ) {

                putchar(dr[dir]);

                dfs(xf, yf, cur - 1);

                break;

            }

        }

    }

    inline void solve() {

        rep(i, n) ham = max(ham, x[i] + y[i]) + 2;

        for(k = 0; (1LL << k) < ham; ++k) ;

        if(even) printf("%lld\n1 ", ++k + 1);

        else printf("%lld\n", ++k);

        for(int i = k; i ; --i) {

            a[i] = 1LL << (i - 1);

            printf("%lld%c", a[i], i == 1LL ? '\n' : ' ');

        }

        for(int i = 1; i <= n; ++i){

            if(even) putchar('L'), x[i]++;

            dfs(x[i], y[i], k);

            putchar('\n');

        }

    }

}

signed main(){

    scanf("%lld", &n);

    odd = even = true;

    rep(i, n) scanf("%lld%lld", &x[i], &y[i]);

    rep(i, n) {

        int sum = abs(x[i]) + abs(y[i]);

        if(sum & 1) even = false; else odd = false;

    }

    if((odd | even) == 0) {puts("-1"); return 0;}

    sol::solve();

    return 0;

}