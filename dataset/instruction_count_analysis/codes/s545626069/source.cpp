#include"stdc++.h"

using namespace std;

#define ms(x,y) memset(x, y, sizeof(x))

#define lowbit(x) ((x)&(-x))

#define sqr(x) ((x)*(x))

typedef long long LL;

typedef pair<int,int> pii;

typedef pair<LL,LL> pll;



const LL MOD = 998244353;



void run_case() {

    int n;

    cin >> n;

    vector<pll> a(n), sta;

    for(auto &x: a) cin >> x.first >> x.second;

    sort(a.begin(), a.end());

    vector<LL> dp(n+1);

    dp[n] = 1;

    sta.emplace_back(n, 3e9);

    for(int i = n-1; i >= 0; --i) {

        while(sta.back().second < a[i].first + a[i].second)

            sta.pop_back();

        dp[i] = dp[sta.back().first];

        sta.emplace_back(i, a[i].first);

        dp[i] = (dp[i] + dp[i+1]) % MOD;

    }

    cout << dp[0];

}





int main() {

    ios::sync_with_stdio(false), cin.tie(0);

    cout.flags(ios::fixed);cout.precision(9);

    //int t; cin >> t;

    //while(t--)

    run_case();

    cout.flush();

    return 0;

}