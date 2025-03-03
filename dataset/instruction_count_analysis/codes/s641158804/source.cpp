#pragma GCC optimize(3, "Ofast", "inline")



#include "stdc++.h"



#define start ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long

#define int ll

#define ls st<<1

#define rs st<<1|1

#define pii pair<int,int>

#define rep(z, x, y) for(int z=x;z<=y;++z)

#define com bool operator<(const node &b)

using namespace std;

const int maxn = (ll) 3e5 + 5;

const int mod = 1000000007;

const int inf = 0x3f3f3f3f;

int T = 1;

int cntb, cnta, cntab;

int fac[maxn];



void solve() {

    fac[0] = 1;

    rep(i, 1, 2e5 + 5)fac[i] = fac[i - 1] * 2 % mod;

    map<pii, int> mp;

    int n;

    cin >> n;

    rep(i, 1, n) {

        int a, b;

        cin >> a >> b;

        if (a * b == 0) {

            if (a == 0 && b == 0)

                ++cntab;

            else if (a == 0)

                ++cnta;

            else if (b == 0)

                ++cntb;

            continue;

        }



//        if (a * b > 0) {

//            a = abs(a), b = abs(b);

//            int gcd = __gcd(a, b);

//            ++mp[pair<int,int>(a / gcd, b / gcd)];

//        } else {

//            a = abs(a), b = abs(b);

//            int gcd = __gcd(a, b);

//            ++mp[pair<int,int>(-a / gcd, b / gcd)];

//        }



        int gcd = __gcd(a, b);

        a /= gcd, b /= gcd;

        if (a * b > 0) {

            a = abs(a), b = abs(b);

            ++mp[pair<int,int>(a, b)];

        } else {

            a = abs(a), b = abs(b);

            ++mp[pair<int,int>(-a, b)];

        }



    }

    int ans = (fac[cnta] + fac[cntb] - 1 + mod) % mod;

    for (auto &to:mp) {

        if (to.second == 0)

            continue;

        int a = to.first.first, b = to.first.second;

        int num = to.second;

        pii j = a > 0 ? pii(-b, a) : pii(b, -a);

        if (mp[j] == 0)

            ans = ans * fac[num] % mod;

        else

            ans = ans * (fac[num] + fac[mp[j]] - 1 + mod) % mod;

        //cout << a << ' ' << b << ' ' << ans << ' ' << mp[j] << endl;

        mp[j] = to.second = 0;

    }

    cout << (ans - 1 + cntab + mod) % mod;

}



signed main() {

    start;

    //cout<<__gcd(4,6)<<' '<<__gcd(-4,6)<<' '<<__gcd(4,-6)<<' '<<__gcd(-4,-6)<<endl;

    while (T--)

        solve();

    return 0;

}
