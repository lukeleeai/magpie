#include "stdc++.h"

#define REP(i,n) for (int i = 0; i < (n); ++i)

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}

template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

using namespace std;

using ll = long long;

using P = pair<int,int>;

using Pl = pair<long long,long long>;

using veci = vector<int>;

using vecl = vector<long long>;

using vecveci = vector<vector<int>>;

using vecvecl = vector<vector<long long>>;





template <typename T>

struct PrimeFact {

    vector<T> spf;

    PrimeFact(T N) { init(N); }

    void init(T N) { // 前処理。spf を求める

        spf.assign(N + 1, 0);

        for (T i = 0; i <= N; i++) spf[i] = i;

        for (T i = 2; i * i <= N; i++) {

            if (spf[i] == i) {

                for (T j = i * i; j <= N; j += i) {

                    if (spf[j] == j) {

                        spf[j] = i;

                    }

                }

            }

        }

    }

    map<T, T> get(T n) { // nの素因数分解を求める

        map<T, T> m;

        while (n != 1) {

            m[spf[n]]++;

            n /= spf[n];

        }

        return m;

    }

};



int main() {

    ll N; cin >> N;

    ll ans = 0;

    PrimeFact<ll> PF(N);

    for(ll i = 1; i <= N; i++) {

        map<ll,ll> res = PF.get(i);

        ll cost = 1;

        for(auto p : res) {

            cost *= p.second + 1;

        }

        ans += i*cost;

    }

    cout << ans << endl;

}