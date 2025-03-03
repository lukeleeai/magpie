#include "stdc++.h"

using namespace std;

using ll = long long;

using PII = pair<ll, ll>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)

#define ALL(x) x.begin(), x.end()

template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }

template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }

struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;

#ifdef DEBUG_ 

#include "../program_contest_library/memo/dump.hpp"

#else

#define dump(...)

#endif

const ll INF = 1LL<<60;



template<ll MOD>

struct modint {

    ll x;

    modint(): x(0) {}

    modint(ll y) : x(y>=0 ? y%MOD : y%MOD+MOD) {}

    static constexpr ll mod() { return MOD; }

    // e乗

    modint pow(ll e) {

        ll a = 1, p = x;

        while(e > 0) {

            if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}

            else {a = (a*p) % MOD; e--;}

        }

        return modint(a);

    }

    modint inv() const {

        ll a=x, b=MOD, u=1, y=1, v=0, z=0;

        while(a) {

            ll q = b/a;

            swap(z -= q*u, u);

            swap(y -= q*v, v);

            swap(b -= q*a, a);

        }

        return z;

    }

    // Comparators

    bool operator <(modint b) { return x < b.x; }

    bool operator >(modint b) { return x > b.x; }

    bool operator<=(modint b) { return x <= b.x; }

    bool operator>=(modint b) { return x >= b.x; }

    bool operator!=(modint b) { return x != b.x; }

    bool operator==(modint b) { return x == b.x; }

    // Basic Operations

    modint operator+(modint r) const { return modint(*this) += r; }

    modint operator-(modint r) const { return modint(*this) -= r; }

    modint operator*(modint r) const { return modint(*this) *= r; }

    modint operator/(modint r) const { return modint(*this) /= r; }

    modint &operator+=(modint r) {

        if((x += r.x) >= MOD) x -= MOD;

        return *this;

    }

    modint &operator-=(modint r) {

        if((x -= r.x) < 0) x += MOD;

        return *this;

    }

    modint &operator*=(modint r) {

    #if !defined(_WIN32) || defined(_WIN64)

        x = x * r.x % MOD; return *this;

    #endif

        unsigned long long y = x * r.x;

        unsigned xh = (unsigned) (y >> 32), xl = (unsigned) y, d, m;

        asm(

            "divl %4; \n\t"

            : "=a" (d), "=d" (m)

            : "d" (xh), "a" (xl), "r" (MOD)

        );

        x = m;

        return *this;

    }

    modint &operator/=(modint r) { return *this *= r.inv(); }

    // increment, decrement

    modint operator++() { x++; return *this; }

    modint operator++(signed) { modint t = *this; x++; return t; }

    modint operator--() { x--; return *this; }

    modint operator--(signed) { modint t = *this; x--; return t; }

    // 平方剰余のうち一つを返す なければ-1

    friend modint sqrt(modint a) {

        if(a == 0) return 0;

        ll q = MOD-1, s = 0;

        while((q&1)==0) q>>=1, s++;

        modint z=2;

        while(1) {

            if(z.pow((MOD-1)/2) == MOD-1) break;

            z++;

        }

        modint c = z.pow(q), r = a.pow((q+1)/2), t = a.pow(q);

        ll m = s;

        while(t.x>1) {

            modint tp=t;

            ll k=-1;

            FOR(i, 1, m) {

                tp *= tp;

                if(tp == 1) { k=i; break; }

            }

            if(k==-1) return -1;

            modint cp=c;

            REP(i, m-k-1) cp *= cp;

            c = cp*cp, t = c*t, r = cp*r, m = k;

        }

        return r.x;

    }



    template<class T>

    friend modint operator*(T l, modint r) { return modint(l) *= r; }

    template<class T>

    friend modint operator+(T l, modint r) { return modint(l) += r; }

    template<class T>

    friend modint operator-(T l, modint r) { return modint(l) -= r; }

    template<class T>

    friend modint operator/(T l, modint r) { return modint(l) /= r; }

    template<class T>

    friend bool operator==(T l, modint r) { return modint(l) == r; }

    template<class T>

    friend bool operator!=(T l, modint r) { return modint(l) != r; }

    // Input/Output

    friend ostream &operator<<(ostream& os, modint a) { return os << a.x; }

    friend istream &operator>>(istream& is, modint &a) { 

        is >> a.x;

        a.x = ((a.x%MOD)+MOD)%MOD;

        return is;

    }

    friend string to_frac(modint v) {

        static map<ll, PII> mp;

        if(mp.empty()) {

            mp[0] = mp[MOD] = {0, 1};

            FOR(i, 2, 1001) FOR(j, 1, i) if(__gcd(i, j) == 1) {

                mp[(modint(i) / j).x] = {i, j};

            }

        }

        auto itr = mp.lower_bound(v.x);

        if(itr != mp.begin() && v.x - prev(itr)->first < itr->first - v.x) --itr;

        string ret = to_string(itr->second.first + itr->second.second * ((int)v.x - itr->first));

        if(itr->second.second > 1) {

            ret += '/';

            ret += to_string(itr->second.second);

        }

        return ret;

    }

};

using mint = modint<1000000007>;



int main(void) {

    ll n, m, s, t;

    cin >> n >> m >> s >> t;

    s--, t--;

    vector<vector<PII>> g(n);

    vector<ll> a(m), b(m), c(m);

    REP(i, m) {

        cin >> a[i] >> b[i] >> c[i];

        a[i]--, b[i]--;

        g[a[i]].emplace_back(b[i], c[i]);

        g[b[i]].emplace_back(a[i], c[i]);

    }



    // sからt

    vector<ll> dist1(n, INF);

    vector<mint> cnt1(n);

    cnt1[s] = 1;

    dist1[s] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> que;

    que.push({0, s});

    while(que.size()) {

        PII p = que.top(); que.pop();

        if(dist1[p.second] < p.first) continue;

        for(auto to: g[p.second]) {

            if(dist1[to.first] > dist1[p.second] + to.second) {

                dist1[to.first] = dist1[p.second] + to.second;

                cnt1[to.first] = cnt1[p.second];

                que.push({dist1[to.first], to.first});

            } else if(dist1[to.first] == dist1[p.second] + to.second) {

                cnt1[to.first] += cnt1[p.second];

            }

        }

    }



    // tからs

    vector<ll> dist2(n, INF);

    vector<mint> cnt2(n);

    cnt2[t] = 1;

    dist2[t] = 0;

    que.push({0, t});

    while(que.size()) {

        PII p = que.top(); que.pop();

        if(dist2[p.second] < p.first) continue;

        for(auto to: g[p.second]) {

            if(dist2[to.first] > dist2[p.second] + to.second) {

                dist2[to.first] = dist2[p.second] + to.second;

                cnt2[to.first] = cnt2[p.second];

                que.push({dist2[to.first], to.first});

            } else if(dist2[to.first] == dist2[p.second] + to.second) {

                cnt2[to.first] += cnt2[p.second];

            }

        }

    }



    dump(dist1);

    dump(cnt1);

    dump(dist2);

    dump(cnt2);



    const ll D = dist1[t];

    mint ret = cnt1[t] * cnt2[s];

    REP(i, n) if(dist1[i] == dist2[i]) ret -= cnt1[i]*cnt1[i]*cnt2[i]*cnt2[i];

    REP(i, m) {

        ll u = a[i], v = b[i];

        if(dist1[u]*2 < D && dist1[v]*2 > D && dist1[u]+c[i] == dist1[v] && dist1[u]+dist2[v]+c[i]==D) {

            dump(u, v, cnt1[u], cnt2[v]);

            ret -= cnt1[u]*cnt1[u]*cnt2[v]*cnt2[v];

        }

        swap(u, v);

        if(dist1[u]*2 < D && dist1[v]*2 > D && dist1[u]+c[i] == dist1[v] && dist1[u]+dist2[v]+c[i]==D) {

            dump(u, v, cnt1[u], cnt2[v]);

            ret -= cnt1[u]*cnt1[u]*cnt2[v]*cnt2[v];

        }

    }

    cout << ret << endl;



    return 0;

}