// By Hacheylight



#include <map>

#include <set>

#include <ctime>

#include <queue>

#include <stack>

#include <cmath>

#include <vector>

#include <bitset>

#include <cstdio>

#include <cctype>

#include <string>

#include <numeric>

#include <cstring>

#include <cassert>

#include <climits>

#include <cstdlib>

#include <iostream>

#include <algorithm>

#include <functional>

using namespace std ;

//#define int long long

#define rep(i, a, b) for (int i = (a); i <= (b); i++)

#define per(i, a, b) for (int i = (a); i >= (b); i--)

#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)

#define clr(a) memset(a, 0, sizeof(a))

#define ass(a, sum) memset(a, sum, sizeof(a))

#define lowbit(x) (x & -x)

#define all(x) x.begin(), x.end()

#define SC(t, x) static_cast <t> (x)

#define ub upper_bound

#define lb lower_bound

#define pqueue priority_queue

#define mp make_pair

#define pb push_back

#define pof pop_front

#define pob pop_back

#define fi first

#define se second

#define y1 y1_

#define Pi acos(-1.0)

#define iv inline void

#define enter cout << endl

#define siz(x) ((int)x.size())

#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)

typedef long double ld ;

typedef long long ll ;

typedef unsigned long long ull ;

typedef pair <int, int> pii ;

typedef pair <ll, int> pli ;

typedef pair<int, pii> tri ;

typedef vector <int> vi ;

typedef vector <pii> vii ;

typedef vector <vi> vvi ;

typedef queue <int> qi ;

typedef queue <pii> qii ;

typedef set <int> si ;

typedef map <int, int> mii ;

typedef map <string, int> msi ;

const int N = 100010 ;

const int INF = 0x3f3f3f3f ;

const int iinf = 1 << 30 ;

const ll linf = 2e18 ;

const int mod = 1000000007 ;

const double eps = 1e-7 ;

void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }

template <class T> void print(T a) { cout << a << endl ; exit(0) ; }

template <class T> void chmin(T &a, T b) { if (a > b) a = b ; }

template <class T> void chmax(T &a, T b) { if (a < b) a = b ; }

void add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod ; }

void sub(int &a, int b) { a = (a - b + mod) % mod ; }

void mul(int &a, int b) { a = (ll) a * b % mod ; }

int addv(int a, int b) { return (a += b) >= mod ? a -= mod : a ; }

int subv(int a, int b) { return (a -= b) < 0 ? a += mod : a ; }

int mulv(int a, int b) { return (ll) a * b % mod ; }

int read() {

    int f = 1, x = 0 ;

    char ch = getchar() ;

    while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }

    while (isdigit(ch)) { x = x * 10 + ch -'0' ; ch = getchar() ; }

    return x * f ;

}

int pw(int a, int b) {

    int s = 1 ;

    for (; b; b >>= 1, a = (ll) a * a % mod)

    if (b & 1) s = (ll) s * a % mod ;

    return s ;

}



int fac[N], inv[N] ;

int dfn[N], low[N], stk[N] ;

int n, m, k, tim, top, ans ;

vi e[N] ;

set <int> s ;



int C(int n, int k) {

	return mulv(fac[n], mulv(inv[k], inv[n - k])) ;

}



int burnside(int n) {

	int s = 0 ;

	rep(i, 1, n) add(s, pw(k, __gcd(i, n))) ;

	mul(s, pw(n, mod - 2)) ;

//	cout << s << endl ;

	return s ;

}



/*

一个双联通分量，

如果边数<点数，可放任何颜色

边数=点数，有一个环，通过Burnside引理求

边数>点数，那么有多个环，用组合数求 

*/ 



void tarjan(int u) {

	dfn[u] = low[u] = ++tim ;

	stk[++top] = u ;

	rep(i, 0, siz(e[u]) - 1) {

		int to = e[u][i] ;

		if (!dfn[to]) {

			tarjan(to) ;

			chmin(low[u], low[to]) ;

			if (low[to] >= dfn[u]) {

				s.clear() ; int t, nn, mm = 0 ; 

				do {

					t = stk[top--] ;

					s.insert(t) ;

				} while (t != to) ;	

				s.insert(u) ;

				nn = siz(s) ;

				loop(it, s) 

				rep(i, 0, siz(e[*it]) - 1) 

				if (s.count(e[*it][i])) mm++ ;

				mm /= 2 ;

				if (mm < nn) mul(ans, k) ;

				if (nn == mm) mul(ans, burnside(mm)) ;

				if (nn < mm) mul(ans, C(mm + k - 1, k - 1)) ;

	//			cout << "ans = " << ans << endl ;

 			}

		} else {

			chmin(low[u], dfn[to]) ;

		}

	}

}



signed main() {

	scanf("%d%d%d", &n, &m, &k) ;

	rep(i, 1, m) {

		int x, y ; scanf("%d%d", &x, &y) ;

		e[x].pb(y) ; e[y].pb(x) ;

	}

	fac[0] = 1 ;

	rep(i, 1, m + k) fac[i] = mulv(fac[i - 1], i) ;

	inv[m + k] = pw(fac[m + k], mod - 2) ;

	per(i, m + k, 1) inv[i - 1] = mulv(inv[i], i) ;

	ans = 1 ;

	rep(i, 1, n) if (!dfn[i]) tarjan(i) ;

	printf("%d\n", ans) ;

	return 0 ;

}
