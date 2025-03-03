#include "stdc++.h"

#define ll long long

#define mod 1000000007

#define pii pair<int, int>

#define fr(n) for (int i = 0; i < n; i++)

#define fr1(n) for (int i = 1; i <= n; i++)

using namespace std;



void A() {

    int n, a[100005] = {}, b[100005] = {};

    cin >> n;

    fr1(n) cin >> a[i];

    b[1] = 0; b[2] = abs(a[1] - a[2]);

    for (int i = 3; i <= n; i++) b[i] = min(b[i - 2] + abs(a[i - 2] - a[i]), b[i - 1] + abs(a[i - 1] - a[i]));

    cout << b[n];

}



void B() {

    int n, k, a[100005] = {}, b[100005] = {};

    cin >> n >> k;

    fr1(n) cin >> a[i], b[i] = mod;

    fr1(k) b[i] = abs(a[1] - a[i]);

    for (int i = k + 1; i <= n; i++) for (int j = 1; j <= k; j++) b[i] = min(b[i - j] + abs(a[i - j] - a[i]), b[i]);

    cout << b[n];

}



void C() {

    int n, a[100005][3] = {}, b[100005][3] = {};

    cin >> n;

    fr1(n) cin >> a[i][0] >> a[i][1] >> a[i][2];

    fr1(n) b[i][0] = max(b[i - 1][1], b[i - 1][2]) + a[i][0], b[i][1] = max(b[i - 1][2], b[i - 1][0]) + a[i][1], b[i][2] = max(b[i - 1][0], b[i - 1][1]) + a[i][2];

    cout << max({b[n][0], b[n][1], b[n][2]});

}



void D() {

    int n, w, a[102] = {}, b[102] = {};

    ll z = 0, d[100005] = {};

    cin >> n >> w;

    fr(n) cin >> a[i] >> b[i];

    fr(n) for (int j = w; j >= a[i]; j--) d[j] = max(d[j], d[j - a[i]] + b[i]);

    fr1(w) z = max(z, d[i]);

    cout << z;

}



void E() {

    int n, a[102] = {}, b[102] = {};

    ll w, d[100005] = {};

    cin >> n >> w;

    fr1(100000) d[i] = mod * 328ll;

    fr(n) cin >> a[i] >> b[i];

    fr(n) for (int j = 100000; j >= b[i]; j--) d[j] = min(d[j], d[j - b[i]] + a[i]);

    for (int i = 100000; i >= 0; i--) if (d[i] <= w) {

        cout << i;

        break;

    }

}



void F() {

    string s, t, u;

    cin >> s >> t;

    int d[3003][3003] = {}, n = (int)s.length(), m = (int)t.length();

    fr1(n) for (int j = 1; j <= m; j++) {

        if (s[i - 1] == t[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;

        else d[i][j] = max(d[i - 1][j], d[i][j - 1]);

    }

    while (n && m) {

        if (d[n - 1][m - 1] + 1 == d[n][m]) n--, m--, u += s[n];

        else if (n && d[n - 1][m] == d[n][m]) n--;

        else m--;

    }

    reverse(u.begin(), u.end());

    cout << u;

}



void G() {

    int n, m, u, v, z = 0, c[100005] = {}, d[100005] = {};

    vector<int> g[100005] = {};

    cin >> n >> m;

    fr(m) cin >> u >> v, g[u].push_back(v), c[v]++;

    queue<int> q;

    fr1(n) if (!c[i]) q.push(i);

    while (!q.empty()) {

        int x = q.front();

        q.pop();

        for (int i : g[x]) {

            d[i] = max(d[i], d[x] + 1);

            c[i]--;

            if (!c[i]) q.push(i);

        }

    }

    fr1(n) z = max(z, d[i]);

    cout << z;

}



void H() {

    int n, m, d[1003][1003] = {1};

    string s[1003] = {};

    cin >> n >> m;

    fr(n) cin >> s[i];

    fr(n) for (int j = 0; j < m; j++) if (s[i][j] == '.') {

        if (i) d[i][j] += d[i - 1][j];

        if (j) d[i][j] += d[i][j - 1];

        if (d[i][j] >= mod) d[i][j] -= mod;

    }

    cout << d[n - 1][m - 1];

}



void I() {

    int n;

    double z = 0, a[3003] = {}, d[3003] = {1};

    cin >> n;

    fr1(n) cin >> a[i];

    fr1(n) for (int j = n; j >= 0; j--) {

        double e = d[j];

        if (j) d[j] = d[j - 1] * a[i];

        else d[j] = 0;

        d[j] += e * (1 - a[i]);

    }

    fr(n + 1) if (i + i > n) z += d[i];

    cout << setprecision(13) << z;

}



void J() {

    int n, c0, c[4] = {};

    double d[303][303][303] = {};

    cin >> n;

    fr(n + 1) for (int j = 0; j <= i; j++) for (int k = 0; k <= j; k++) {

        if (i - j) d[i][j][k] += d[i - 1][j][k] * (i - j) / i;

        if (j - k) d[i][j][k] += d[i][j - 1][k] * (j - k) / i;

        if (k) d[i][j][k] += d[i][j][k - 1] * k / i;

        if (i) d[i][j][k] += 1.0 * n / i;

        //cout << i << ' ' << j << ' ' << k << ' ' << d[i][j][k] << '\n';

    }

    fr(n) cin >> c0, c[c0]++;

    cout << setprecision(13) << d[c[1] + c[2] + c[3]][c[2] + c[3]][c[3]];

}



void K() {

    int n, k, a[102] = {}, b[100005] = {};

    cin >> n >> k;

    fr(n) cin >> a[i];

    fr1(k) for (int j = 0; j < n; j++) if (i >= a[j]) b[i] |= !b[i - a[j]];

    cout << (b[k] ? "First" : "Second");

}



void L() {

    int n;

    ll a[3003] = {}, d[2][3003][3003] = {};

    cin >> n;

    fr(n) cin >> a[i];

    fr(n) for (int j = 0; j + i < n; j++) {

        d[0][j][j + i] = max(d[1][j + 1][j + i] + a[j], d[1][j][j + i - 1] + a[j + i]);

        d[1][j][j + i] = min(d[0][j + 1][j + i], d[0][j][j + i - 1]);

    }

    cout << d[0][0][n - 1] - d[1][0][n - 1];

}



void M() {

    int n, k, a[102] = {};

    ll d[100005] = {1};

    cin >> n >> k;

    fr(n) cin >> a[i];

    for (int j = 0; j < n; j++) {

        ll e[100005] = {};

        fr(k + 1) e[i] = d[i];

        fr1(k) e[i] += e[i - 1];

        fr(k + 1) d[i] = e[i] - (i > a[j] ? e[i - a[j] - 1] : 0);

        fr(k + 1) d[i] %= mod;

    }

    cout << d[k];

}



void N() {

    int n;

    ll a[403] = {}, b[403] = {}, d[403][403] = {};

    cin >> n;

    fr1(n) cin >> a[i], b[i] = b[i - 1] + a[i];

    fr(403) for (int j = 0; j < 403; j++) d[i][j] = mod * 890328ll;

    fr1(n) d[i][i] = 0;

    for (int i = 1; i < n; i++) for (int j = 1; j + i <= n; j++) {

        for (int k = j; k < j + i; k++) d[j][j + i] = min(d[j][j + i], d[j][k] + d[k + 1][j + i]);

        d[j][j + i] += b[j + i] - b[j - 1];

    }

    cout << d[1][n] << '\n';

}



void O() {

    int n, d[2100328] = {1}, c[2100328] = {};

    vector<int> g[2100328] = {};

    bool b[22][22] = {};

    cin >> n;

    fr(1 << n) for (int j = 0; j < n; j++) if (i & (1 << j)) g[i].push_back(j), c[i]++;

    fr(n) for (int j = 0; j < n; j++) cin >> b[i][j];

    fr(n) {

        for (int j = (int)(1 << n) - 1; j >= 0; j--) if (c[j] == i + 1) {

            for (int k : g[j]) if (b[i][k]) {

                d[j] += d[j - (1 << k)];

                if (d[j] >= mod) d[j] -= mod;

            }

        }

    }

    cout << d[(1 << n) - 1];

}



vector<int> g[100005];

ll d[100005], e[100005];



void dfs(int x, int p) {

    d[x] = e[x] = 1;

    for (int i : g[x]) if (i != p) {

        dfs(i, x);

        d[x] = d[x] * e[i] % mod;

        e[x] = e[x] * (d[i] + e[i]) % mod;

    }

}



void P() {

    int n, u, v;

    cin >> n;

    fr(n - 1) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    dfs(1, 1);

    cout << (d[1] + e[1]) % mod;

}



void Q() {

    int n, h[200005] = {};

    ll t[200005] = {}, a[200005] = {}, y = 0;

    cin >> n;

    fr1(n) cin >> h[i];

    fr1(n) cin >> a[i];

    fr1(n) {

        ll z = 0;

        for (int j = h[i]; j; j -= j & -j) z = max(z, t[j]);

        for (int j = h[i]; j <= n; j += j & -j) t[j] = max(t[j], z + a[i]);

    }

    fr1(n) y = max(y, t[i]);

    cout << y;

}



vector<vector<ll>> mul(int n, vector<vector<ll>> c, vector<vector<ll>> d) {

    vector<vector<ll>> e(n);

    fr(n) e[i].resize(n);

    fr(n) for (int j = 0; j < n; j++) {

        for (int k = 0; k < n; k++) e[i][j] = (e[i][j] + c[i][k] * d[k][j]) % mod;

    }

    return e;

}



void R() {

    int n;

    vector<vector<ll>> a, b;

    ll m, z = 0;

    cin >> n >> m;

    a.resize(n); b.resize(n);

    fr(n) a[i].resize(n), b[i].resize(n);

    fr(n) for (int j = 0; j < n; j++) cin >> a[i][j];

    fr(n) b[i][i] = 1;

    while (m) {

        if (m & 1) b = mul(n, b, a);

        a = mul(n, a, a);

        m >>= 1;

    }

    fr(n) for (int j = 0; j < n; j++) z += b[i][j];

    cout << z % mod;

}



void S() {

    string k;

    int m;

    ll d[10004][102][2] = {};

    d[0][0][1] = 1;

    cin >> k >> m;

    fr1(k.length()) {

        for (int j = 0; j < m; j++) {

            for (int l = 0; l < 10; l++) d[i][(j + l) % m][0] += d[i - 1][j][0];

            for (int l = 0; l < k[i - 1] - '0'; l++) d[i][(j + l) % m][0] += d[i - 1][j][1];

            d[i][(j + k[i - 1] - '0') % m][1] = d[i - 1][j][1];

        }

        for (int j = 0; j < m; j++) d[i][j][0] %= mod;

    }

    cout << (d[k.length()][0][0] + d[k.length()][0][1] + mod - 1) % mod;

}



void U() {

    int n;

    ll a[17][17] = {}, d[65541] = {}, s[65541] = {}, z = 0;

    cin >> n;

    fr(n) for (int j = 0; j < n; j++) cin >> a[i][j];

    fr(1 << n) for (int j = 0; j < n; j++) for (int k = 0; k < j; k++) if (i & (1 << j) && i & (1 << k)) s[i] += a[j][k];

    fr(1 << n) {

        vector<int> b;

        for (int j = 0; j < n; j++) if (i & (1 << j)) b.push_back(1 << j);

        int m = (int)b.size();

        for (int j = 0; j < (1 << m); j++) {

            int c = 0;

            for (int k = 0; k < m; k++) if (j & (1 << k)) c += b[k];

            d[i] = max(d[i], d[i - c] + s[c]);

        }

    }

    fr(1 << n) z = max(z, d[i]);

    cout << z;

}



//vector<int> g[100005];

int p[100005];

ll d2[100005] = {1}, z[100005], m;



void dfs2(int x, int w) {

    d2[x] = 1;

    for (int i : g[x]) if (i != w) p[i] = x, dfs2(i, x), d2[x] = d2[x] * (d2[i] + 1) % m;

    if (x > 1) g[x].erase(find(g[x].begin(), g[x].end(), w));

}



void dfs3(int x) {

    vector<ll> a = {1}, b = {1};

    for (int i = (int)g[x].size() - 1; i >= 0; i--) a.push_back(a.back() * (d2[g[x][i]] + 1) % m);

    fr(g[x].size()) b.push_back(b.back() * (d2[g[x][i]] + 1) % m);

    reverse(a.begin(), a.end());

    z[x] = d2[x];

    fr(g[x].size()) {

        d2[x] = d2[p[x]] * (b[i] * a[i + 1] % m) % m + 1;

        d2[g[x][i]] = d2[g[x][i]] * d2[x] % m;

    }

    for (int i = 0; i < g[x].size(); i++) d2[x] = d2[p[x]] * (b[i] * a[i + 1] % m) % m + 1, dfs3(g[x][i]);

}



void V() {

    int n, u, v;

    cin >> n >> m;

    fr1(n - 1) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    dfs2(1, 1);

    dfs3(1);

    fr1(n) cout << z[i] << '\n';

}



void X() {

    int n;

    ll z = 0, d[20004] = {};

    pair<pii, int> a[1003] = {};

    cin >> n;

    fr(n) cin >> a[i].first.second >> a[i].first.first >> a[i].second, a[i].first.first += a[i].first.second;

    sort(a, a + n);

    fr(n) for (int j = a[i].first.first; j >= a[i].first.second; j--) d[j] = max(d[j], d[j - a[i].first.second] + a[i].second);

    fr(20003) z = max(z, d[i]);

    cout << z;

}



void Y() {

    ll f[200005] = {1}, g[200005] = {}; g[200000] = 750007460;

    fr1(200000) f[i] = f[i - 1] * i % mod;

    for (int i = 200000; i; i--) g[i - 1] = g[i] * i % mod;

    int h, w, n;

    ll d[3003] = {};

    pii a[3003] = {};

    cin >> h >> w >> n;

    a[n].first = h, a[n].second = w;

    fr(n) cin >> a[i].first >> a[i].second;

    sort(a, a + n);

    fr(n + 1) d[i] = f[a[i].first + a[i].second - 2] * g[a[i].first - 1] % mod * g[a[i].second - 1] % mod;

    fr(n + 1) {

        for (int j = 0; j < i; j++) if (a[i].first >= a[j].first && a[i].second >= a[j].second) {

            d[i] -= d[j] * f[a[i].first - a[j].first + a[i].second - a[j].second] % mod * g[a[i].first - a[j].first] % mod * g[a[i].second - a[j].second] % mod;

            if (d[i] < 0) d[i] += mod;

        }

    }

    cout << d[n];

}



int main() {

    ios::sync_with_stdio(false);

    N();

}
