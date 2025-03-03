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

enum : int { M = 998244353 };

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



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    init(4096, M);

    int k, n;

    cin >> k >> n;

    ll total = modC(n + k - 1, k - 1, M);

    vector<int> anss;

    for(int i = 2; i <= k + 1; i += 2){

        int pairs = i / 2;

        ll ans = total;

        for(int j = 1; j <= pairs; j++){

            if(n < j * 2){ break; }

            ans = ans + (j & 1 ? -1 : 1) * modC(n + k - 1 - j * 2, k - 1, M) * modC(pairs, j, M) % M;

            ans = (ans + M) % M;

        }

        anss.push_back(ans);

        anss.push_back(ans);

    }

    for(int i = 0; i < k; i++){

        cout << anss[i] << '\n';

    }

    for(int i = k - 2; i >= 0; i--){

        cout << anss[i] << '\n';

    }

}
