#include"stdc++.h"

using namespace std;

typedef long long ll;

#define F first

#define S second

#define pii pair<int, int>

#define eb emplace_back

#define all(v) v.begin(), v.end()

#define rep(i, n) for (int i = 0; i < (n); ++i)

#define rep3(i, l, n) for (int i = l; i < (n); ++i)

#define sz(v) (int)v.size()

const int inf = 1e9 + 7;

const ll INF = 1e18;

const int mod = 1000000007;

#define abs(x) (x >= 0 ? x : -(x))

#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())

#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())

template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }

template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }

ll modpow(ll a, int b, int _mod) { return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1; }

template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }

template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }

template<typename T >inline istream& operator >> (istream& is, vector<T>& v) { rep(j, sz(v)) is >> v[j]; return is; }

template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }







void solve();



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    cout << fixed << setprecision(10);



    int T;

    // cin >> T;

    T = 1;



    while (T--) {

        solve();

    }

}





const int N = 200005;

vector<vector<int> > G(N);

vector<int> seen(N);

int pos = -1; // cycle 中に含まれる頂点 pos

stack<int> hist; // 訪問履歴



void dfs(int v, int p) {

    seen[v] = 1;

    hist.push(v);

    for (auto nv : G[v]) {

        // if (nv == p) continue;

        if (seen[nv] == 2) continue;



        if (seen[nv] == 1) { // cycle を検出

            pos = nv;

            return;

        }

        dfs(nv, v);

        if (pos != -1) return;

    }

    hist.pop();

    seen[v] = 2;

}



void solve() {

    int n;

    cin >> n;



    string k;

    cin >> k;



    rep(i, n) {

        int b;

        cin >> b;

        b--;

        G[i].eb(b);

    }

    if (n == 2) {

      ll x = stoll(k);

      int now = 0;

      rep(i, x) {

        now = G[now][0];

      }

      cout << now + 1 << endl;

      return;

    }



    dfs(0, -1);



    // cycle 復元

    vector<int> cycle;

    while (!hist.empty()) {

        int t = hist.top();

        cycle.eb(t);

        hist.pop();

        if (t == pos) break;

    }

    reverse(all(cycle));

    // for (auto e : cycle) cout << e << " "; cout << endl;



    int cnt = 0, now = 0;

    while (1) {

        if (now == cycle[0]) {

            break;

        }

        now = G[now][0];

        cnt++;

        if (sz(k) < 7 && cnt == stoi(k)) {

            cout << now + 1 << endl;

            return;

        }

    }

    int k3 = 0;

    rep(i, sz(k)) {

        k3 *= 10;

        k3 += k[i] - '0';

        k3 %= sz(cycle);

    }

    k3 -= cnt; // 先に足すと, 10 倍するのが効いてしまう

    while (k3 < 0) k3 += sz(cycle);

    k3 %= sz(cycle);



    now = cycle[0];

    while (k3--) {

        now = G[now][0];

    }

    cout << now + 1 << endl;

}
