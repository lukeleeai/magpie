#include"stdc++.h"

#define rep(i,a,b) for(int i=a;i<b;i++)

#define rrep(i,a,b) for(int i=a;i>=b;i--)

#define fore(i,a) for(auto &i:a)

#define all(x) (x).begin(),(x).end()

//#pragma GCC optimize ("-O3")

using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

//---------------------------------------------------------------------------------------------------

#define MOD_MAX 10101010

struct SuperCombination {

    ll n, k, m, r; vector<int>vec;

    inline ll modInverse(ll a, ll m) {

        ll m0 = m, t, q, x0 = 0, x1 = 1; if (m == 1) return 0;

        while (a > 1) { q = a / m; t = m; m = a % m, a = t; t = x0; x0 = x1 - q * x0; x1 = t; }

        if (x1 < 0) x1 += m0; return x1; }

    inline ll POW(ll a, ll b, ll mod) {

        ll ans = 1; while (b) { if (b & 1) ans = (ans*a) % mod; a = (a*a) % mod; b >>= 1; }

        return ans; }

    inline ll POW(ll a, ll b) {

        ll ans = 1; while (b) { if (b & 1) ans = ans*a; a = a*a; b >>= 1; } return ans; }

    inline ll C(ll n, ll m, ll mod) {

        if (m>n) return 0; ll ans = 1, i, a, b;

        rep(i, 1, m + 1) { a = (n + 1 - i) % mod; b = modInverse(i%mod, mod); 

            ans = ((ans*a) % mod*b) % mod; } return ans;

    }

    inline ll C1(ll n, ll m, ll mod) {

        if (m == 0) return 1; return C(n%mod, m%mod, mod)*C1(n / mod, m / mod, mod) % mod; }

    ll global, global1, arr[1000001], val;

    void fact(ll p, ll t) {

        arr[1] = arr[0] = 1; val = POW(p, t); for (ll i = 2; i <= val; i++) {

            if (i%p) { arr[i] = (arr[i - 1] * i) % val; } else { arr[i] = arr[i - 1]; } } }

    ll cal(ll n, ll p) {

        if (n == 0)return 1; ll temp = POW(arr[val], n / val, val);

        ll ans = (temp*arr[n%val]) % val; ll pp = (ans*cal(n / p, p)) % val;

        return pp; }

    inline ll C2(ll n, ll m, ll p, ll t) {

        ll x = POW(p, t); ll a, b, c, ap = 0, bp = 0, cp = 0, temp;

        for (temp = n; temp; temp /= p) ap += temp / p; for (temp = m; temp; temp /= p) bp += temp / p;

        for (temp = n - m; temp; temp /= p) cp += temp / p; ap = ap - bp - cp;

        ll ans = POW(p, ap, x); if (ans == 0) return 0;

        fact(p, t); a = cal(n, p); b = cal(m, p); c = cal(n - m, p);

        ans = (ans*a) % x; ans = (ans*modInverse(b, x)) % x; ans = (ans*modInverse(c, x)) % x;

        return ans; }

    ll rem[100], num[100];

    inline ll CRT(int cnt) {

        ll temp = 1; for (int i = 0; i <= cnt; i++) temp *= num[i]; ll ans = 0;

        rep(i, 0, cnt + 1) { ll pp = temp / num[i]; ans = (ans + rem[i] * modInverse(pp, num[i])*pp) % temp; }

        return ans%temp; }

    inline ll Lucas(ll n, ll m, ll mod) { ll i, t, cnt = -1;

        for (i = 0; vec[i] * vec[i] <= mod&&i<vec.size(); i++) { if (mod%vec[i] == 0) { t = 0;

        while (mod%vec[i] == 0) { t++; mod /= vec[i]; } num[++cnt] = POW(vec[i], t);

        rem[cnt] = C2(n, m, vec[i], t); }}

        if (mod>1) { num[++cnt] = mod; rem[cnt] = C2(n, m, mod, 1); } ll ans = CRT(cnt); return ans; }

    bool isinit = false; void init() {

        if (isinit) return; vector<bool> prime(MOD_MAX); int ma = sqrt(MOD_MAX) + 1;

        for (int i = 3; i<ma; i += 2) if (!prime[i]) {

            for (int j = i*i; j<1000001; j += 2 * i) prime[j] = 1; } vec.push_back(2);

        for (int i = 3; i<1000001; i += 2) if (!prime[i]) vec.push_back(i); isinit = true;

    }



    ll nCr(ll n, ll r, ll mod) { init();  return Lucas(n, r, mod); }

    ll nHk(ll n, ll k, ll mod) {

        init(); if (n == 0 && k == 0) return 1; if (n <= 0 || k < 0) return 0;

        return nCr(n + k - 1, k, mod);

    }

};

/*---------------------------------------------------------------------------------------------------

　　　　　　　　　　　 ∧＿∧

　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!

　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0

　　　　／　　　＼　 　  |　|

　　　 /　　 /￣￣￣￣/　　|

　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿

　 　　　＼/＿＿＿＿/　（u　⊃

---------------------------------------------------------------------------------------------------*/













int mod = 2;

int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }

template<class... T> int add(int x, T... y) { return add(x, add(y...)); }



int aCbMAX = 100;

vector<vector<int>> com;

void aCbinit(int ma) {

    ma++;

    aCbMAX = ma;

    com.resize(ma, vector<int>(ma));



    rep(i, 0, ma) com[i][0] = com[i][i] = 1;

    rep(i, 1, ma) rep(j, 1, i) com[i][j] = add(com[i - 1][j - 1], com[i - 1][j]);

}

int aCb(int a, int b) {

    if (a == 0) return 1;

    if (b < 0 || a < b) return 0;

    return com[a][b];

}















int N, A[1010101];

SuperCombination sc;

//---------------------------------------------------------------------------------------------------

int solve() {

    aCbinit(100);



    rep(i, 0, N - 1) A[i] = abs(A[i] - A[i + 1]);

    N--;



    int parity = 0;

    //rep(i, 0, N) if (A[i] == 1 && sc.C(N - 1, i, 2) == 1) parity ^= 1;

    rep(i, 0, N) if (A[i] == 1 && (i | (N - 1 - i)) == N - 1) parity ^= 1;

    if (parity) return 1;



    rep(i, 0, N) if (A[i] == 1) return 0;

    rep(i, 0, N) A[i] /= 2;



    parity = 0;

    //rep(i, 0, N) if (A[i] == 1 && sc.C(N, i, 2) == 1) parity ^= 1;

    rep(i, 0, N) if (A[i] == 1 && (i | (N - 1 - i)) == N - 1) parity ^= 1;

    if (parity) return 2;

    return 0;

}

//---------------------------------------------------------------------------------------------------

void _main() {

    cin >> N; string S; cin >> S;

    rep(i, 0, N) A[i] = S[i] - '0';

    cout << solve() << endl;

}










