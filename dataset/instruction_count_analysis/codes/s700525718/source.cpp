#include<algorithm>

#include<cmath>

#include<iomanip>

#include<iostream>

#include<map>

#include<numeric>

#include<queue>

#include<set>

#include<sstream>

#include<unordered_map>

#include<unordered_set>

#include<vector>

#include<random>

using ll = long long;

enum : ll { M = 998244353 };

using namespace std;

#ifdef LOCAL

#include"rprint2.hpp"

#include"debug_deque.hpp"

#define vector DebugDeque

#else

#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }

FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde) FUNC(printdu);

#endif

template <class S, class T>

istream& operator >> (istream& in, pair<S, T>& p){ return in >> p.first >> p.second; }

template <class T>

istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }



ll modPow(ll base, ll ex, ll m) {

	ll ret = 1;

	while(ex){

		if(ex & 1){

			ret = ret * base % m;

		}

		ex >>= 1;

		base = base * base % m;

	}

	return ret;

}

vector<ll> mFacts, mInvFacts;

ll modFact(int n){ return mFacts[n]; }

ll modInvFact(int n){ return mInvFacts[n]; }

ll modInv(int n, ll m){ return modPow(n, m - 2, m); }

ll modC(int n, int k, ll m){ return modFact(n) * modInvFact(k) % m * modInvFact(n - k) % m; }

void init(int n, ll m){

    mFacts.resize(n + 1);

    mInvFacts.resize(n + 1);

    mFacts[0] = 1;

    for(int i = 1; i <= n; i++){

        mFacts[i] = mFacts[i - 1] * i % m;

    }

    mInvFacts[n] = modInv(mFacts[n], m);

    for(int i = n - 1; i >= 0; i--){

        mInvFacts[i] = mInvFacts[i + 1] * (i + 1) % m;

    }

}



ll nn, kk, cnt;

void func(ll idx, ll num){

    if(idx == nn){ return; }

    cnt++;

    for(ll i = num; i <= kk; i++){

        func(idx + 1, i);

    }

}



ll memo[2048][2048];

ll func2(ll idx, ll num){

    if(idx == nn){ return 1; }

    if(num == kk){ return 1; }

    if(memo[idx][num]){ return memo[idx][num]; }

    prints(idx, num);

    ll ret = 0;

    for(ll i = num; i <= kk; i++){

        ret += func2(idx + 1, i);

        // printde(idx, num, ret);

    }

    ret %= M;

    return memo[idx][num] = ret;

}



ll memo2[2048][2048];

void init3(){

    vector<ll>  acc(2048, 1);

    for(int i = nn; i >= 0; i--){

        vector<ll> next(2048);

        for(int j = kk; j >= 0; j--){

            memo2[i][j] = acc[j];

            next[j] = (next[j + 1] + acc[j]) % M;

        }

        acc.swap(next);

    }

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    // ll k, n;

    // cin >> k >> n;

    // for(nn = 1; nn < 10; nn++){

    //     cnt = 0;

    //     func(0, 0);

    //     prints(cnt, func2(0, 0));

    // }

    // nn = 100;

    // prints(func2(0, 0));

    // kk = 1; nn = 3;

    // prints(func2(0, 1));

    // kk = 3; nn = 3;

    // prints(func2(0, 1));

    // prints(func2(2, 1));

    // prints(func2(2, 1));

    // prints(func2(2, 1) + func2(1, 2));

    // kk = 4; nn = 5;

    // prints(func2(0, 1));

    // prints(func2(2, 1));

    // prints(func2(2, 1) * 2 - func2(4, 1));

    // prints(func2(nn - 3, 1));



    init(2048, M);

    ll k, n;

    cin >> k >> n;

    kk = k; nn = n;

    init3();

    ll total = memo2[0][1];

    // ll total = func2(0, 1);

    // return 0;

    vector<ll> anss;

    for(ll i = 2; i <= k + 1; i++){

        ll sign = -1;

        ll ans = total;

        for(ll j = 2; j <= i; j += 2){

            if(j > n){ break; }

            ll coef = modC(i / 2, j / 2, M);

            // ll coef = i / j;

            ans = (ans + sign * memo2[j][1] * coef + M * 10000) % M;

            // ans = (ans + sign * func2(j, 1) * coef + M * 10000) % M;

            // ans = (ans + sign * func2(j, 1) + M) % M;

            sign *= -1;

            printd(total, i, j, ans);

        }

        anss.push_back(ans);

        // cout << (total - func2(2, 1) + M) % M << '\n';

        // cout << (total - func2(i / 2 * 2, 1) + M) % M << '\n';

    }

    for(ll i = 0; i < k; i++){

        cout << anss[i] << '\n';

    }

    for(ll i = k - 2; i >= 0; i--){

        cout << anss[i] << '\n';

    }

}
