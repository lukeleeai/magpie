#include<iostream>

#include<algorithm>

#include<vector>

#include<string>

#include<set>

#include<queue>

#include<stack>

#include<bitset>

#include<functional>

#include<map>

#include<iomanip>

#include<limits>

#include<unordered_set> 

#include<cmath>

#include <numeric>

#include <array>

#include <complex>

using namespace std;

//long long p = 998244353;

long long p = 1000000007;

#define int long long

#define vel vector<long long>

#define vvel vector<vel>

#define rep(i,n) for(int i=0;i<n;i++)

#define sor(v) sort(v.begin(),v.end())

#define mmax(a,b) a=max(a,b)

#define mmin(a,b) a=min(a,b)

#define mkp make_pair

#define pin pair<int,int>

#define qin pair<pin,int>

#define V vector

#define Endl endl

#define veb vector<bool>

#define fcout cout << fixed << setprecision(15)

#define rev(s) reverse(s.begin(),s.end())

#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()

#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()

int max_kai = 300000;

vel kai(max_kai, 1);

vel inv_kai(max_kai, 1);

int rui(int a, int n, int mod) {

    if (n == 0) { return 1 % mod; }

    int x = rui(a, n / 2, mod);

    x *= x; x %= mod;

    if (n % 2 == 1) { x *= a; x %= mod; }

    return x;

}

int root(int x,vel &pa) {

    if (pa[x] == -1) { return x; }

    int ans = root(pa[x],pa); pa[x] = ans;

    return ans;

}

bool mar(int x, int y,vel &pa) {

    x = root(x,pa);

    y = root(y,pa);

    if (x != y) { pa[x] = y; }

    return (x != y);

}

int gcd(int x, int y) {

    if (x < y) { return gcd(y, x); }

    if (y == 0) { return x; }

    return gcd(y, x % y);

}

int lcm(int x, int y) {

    x = abs(x); y = abs(y);

    return x * y / gcd(x, y);

}

long long modinv(long long a, long long m) {

    long long b = m, u = 1, v = 0;

    while (b) {

        long long t = a / b;

        a -= t * b; swap(a, b);

        u -= t * v; swap(u, v);

    }

    u %= m;

    if (u < 0) u += m;

    return u;

}

void make_kai() {

    rep(i, max_kai - 1) {

        kai[i + 1] = kai[i] * (i + 1); kai[i + 1] %= p;

        inv_kai[i + 1] = modinv(kai[i + 1], p);

    }

}

int com(int n, int r) {

    if ((n < 0) || (r < 0) || (r > n)) { return 0; }

    int ans = (kai[n] * inv_kai[r]) % p;

    return (ans * inv_kai[n - r]) % p;

}

vel uni(vel x) {

    if (x.size() == 0) { return x; }

    sor(x);

    int n = x.size();

    vel ans(1, x[0]);

    for (int j = 1; j < n; j++) {

        if (x[j - 1] != x[j]) { ans.push_back(x[j]); }

    }

    x = ans;

    return x;

}

void pr(vel& v) {

    int n = v.size();

    if (n != 0) {

        cout << v[0];

        rep(i, n - 1) {

            cout << " " << v[i + 1];

        }

        cout << endl;

    }

}

vel dijk(V<V<pin>>& way, int st,int inf) {

    int n = way.size();

    vel dist(n, inf); dist[st] = 0;

    priority_queue<pin, vector<pin>, greater<pin>> pq;

    pq.push(mkp(0, st));

    veb is_checked(n, false);

    while (!pq.empty()) {

        pin x = pq.top(); pq.pop();

        int pot = x.second;

        if (!is_checked[pot]) {

            is_checked[pot] = true;

            for (auto y : way[pot]) {

                int nex_dist = x.first + y.second;

                int nex_pot = y.first;

                if (dist[nex_pot] > nex_dist) {

                    dist[nex_pot] = nex_dist;

                    pq.push(mkp(nex_dist, y.first));

                }

            }

        }

    }

    return dist;

}

template< typename Monoid >

struct SegmentTree {

    using F = function< Monoid(Monoid, Monoid) >;



    int sz;

    vector< Monoid > seg;



    const F f;

    const Monoid M1;



    SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1) {

        sz = 1;

        while (sz < n) sz <<= 1;

        seg.assign(2 * sz, M1);

    }



    void set(int k, const Monoid& x) {

        seg[k + sz] = x;

    }



    void build() {

        for (int k = sz - 1; k > 0; k--) {

            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);

        }

    }



    void update(int k, const Monoid& x) {

        k += sz;

        seg[k] = x;

        while (k >>= 1) {

            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);

        }

    }



    Monoid query(int a, int b) {

        Monoid L = M1, R = M1;

        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {

            if (a & 1) L = f(L, seg[a++]);

            if (b & 1) R = f(seg[--b], R);

        }

        return f(L, R);

    }



    Monoid operator[](const int& k) const {

        return seg[k + sz];

    }



    template< typename C >

    int find_subtree(int a, const C& check, Monoid& M, bool type) {

        while (a < sz) {

            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);

            if (check(nxt)) a = 2 * a + type;

            else M = nxt, a = 2 * a + 1 - type;

        }

        return a - sz;

    }





    template< typename C >

    int find_first(int a, const C& check) {

        Monoid L = M1;

        if (a <= 0) {

            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);

            return -1;

        }

        int b = sz;

        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {

            if (a & 1) {

                Monoid nxt = f(L, seg[a]);

                if (check(nxt)) return find_subtree(a, check, L, false);

                L = nxt;

                ++a;

            }

        }

        return -1;

    }



    template< typename C >

    int find_last(int b, const C& check) {

        Monoid R = M1;

        if (b >= sz) {

            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);

            return -1;

        }

        int a = sz;

        for (b += sz; a < b; a >>= 1, b >>= 1) {

            if (b & 1) {

                Monoid nxt = f(seg[--b], R);

                if (check(nxt)) return find_subtree(b, check, R, true);

                R = nxt;

            }

        }

        return -1;

    }

};

vel mul(vel& a, vel& b) {

    int n = a.size();

    int m = b.size();

    vel ans(n + m - 1, 0);

    rep(i, n) {

        rep(j, m) {

            ans[i + j] += a[i] * b[j];

            ans[i + j] %= p;

        }

    }

    return ans;

}

int rui_p(int& a, int n) {

    if (n == 0) { return 1; }

    int qans = rui_p(a, n / 2);

    qans = qans * qans;

    qans %= p;

    if (n % 2 == 1) {

        qans = qans * a; qans %= p;

    }

    return qans;

}

vvel disj_min(vel& v) {

    int n = v.size();

    vvel ret(22, vel(n));

    ret[0] = v;

    rep(i, 21) {

        rep(j, n) {

            int nex = j + (1 << i);

            if (nex < n) {

                ret[i + 1][j] = min(ret[i][j], ret[i][nex]);

            }

            else {

                ret[i + 1][j] = ret[i][j];

            }

        }

    }

    return ret;

}

vvel disj_max(vel& v) {

    int n = v.size();

    vvel ret(20, vel(n));

    ret[0] = v;

    rep(i, 19) {

        rep(j, n) {

            int nex = j + (1 << i);

            if (nex < n) {

                ret[i + 1][j] = max(ret[i][j], ret[i][nex]);

            }

            else {

                ret[i + 1][j] = ret[i][j];

            }

        }

    }

    return ret;

}

int find_min(vvel& dv,int l,int r) {

    int i = 19;

    while (l + (1 << i) > r) {

        i--;

    }

    return min(dv[i][l], dv[i][r - (1 << i)]);

}

int find_max(vvel& dv, int l, int r) {

    int i = 19;

    while (l + (1 << i) > r) {

        i--;

    }

    return max(dv[i][l], dv[i][r - (1 << i)]);

}

bool is_prime(int n) {

    if (n == 0 || n == 1) { return false; }

    for (int i = 2; i * i <= n; i++) {

        if (n % i == 0) { return false; }

    }

    return true;

}



signed main() {

    int n, m; cin >> n >> m;

    int lc1 = 1;

    vel a(n);

    rep(i, n) {

        int ai; cin >> ai; ai /= 2;

        lc1 = lcm(lc1, ai);

        if (lc1 > m) { cout << 0 << endl; return 0; }

        a[i] = ai;

    }

    rep(i, n) {

        if ((lc1 / a[i]) % 2 == 0) { cout << 0 << endl; return 0; }

    }

    int ans = m / lc1;

    ans = (ans + 1) / 2;

    cout << ans << endl;

    return 0;

}