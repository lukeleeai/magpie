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

#define rep(i, a, b) for (register ll i = (a); i <= (b); ++i)

#define per(i, a, b) for (register ll i = (a); i >= (b); --i)

#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define cont(i, x) for (int i = head[x]; i; i = edge[i].nex)

#define clr(a) memset(a, 0, sizeof(a))

#define ass(a, cnt) memset(a, cnt, sizeof(a))

#define cop(a, b) memcpy(a, b, sizeof(a))

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

typedef double db ;

typedef long long ll ;

typedef unsigned long long ull ;

typedef pair <int, int> pii ;

typedef vector <int> vi ;

typedef vector <pii> vii ;

typedef queue <int> qi ;

typedef queue <pii> qii ;

typedef set <int> si ;

typedef map <int, int> mii ;

typedef map <string, int> msi ;

const int maxn = 5e5 + 10 ;

const int inf = 0x3f3f3f3f ;

const int iinf = 1 << 30 ;

const ll linf = 2e18 ;

const ll mod = 1e9 + 7 ;

const double eps = 1e-7 ;

template <class T> void read(T &a)

{

	int f = 1 ; a = 0;

	char ch = getchar() ;

	while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }

	while (isdigit(ch)) { a =  (a << 3) + (a << 1) + ch - '0' ; ch = getchar() ; }

	a *= f;

}



ll n, ans;



ll p[maxn];



ll st[maxn][20], lg[maxn];



void init()

{

	rep(i, 1, n) st[i][0] = p[i];

	ll tot = 0;

	rep(i, 1, n)

	{

		if((1 << (tot + 1)) < i) tot ++;

		lg[i] = tot;

	}

	if(tot >= 20)

	{

		puts("0");

		exit(0);

	}

	rep(i, 1, tot) rep(j, 1, n)

	{

		if(!(j + (1 << (i - 1)) < maxn))

		{

			puts("0");

			exit(0);

		}

		if(!(j + (1 << (i - 1)) > 0))

		{

			puts("0");

			exit(0);

		}

		st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);

	}

	return ;

}



#define query(l, r) max(st[l][lg[r - l + 1]], st[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]])



ll bsearch(ll l, ll r, ll x, ll typ)

{

	ll s = l, e = r;

	ll ret = typ * (n + 1);

	while(l <= r)

	{

		ll mid = (l + r) >> 1;

		if(typ == 1)

		{

			if(query(s, mid) > x) r = mid - 1, ret = mid;

			else l = mid + 1;

		}

		else

		{

			if(query(mid, e) > x) l = mid + 1, ret = mid;

			else r = mid - 1;

		}

	}

	return ret;

}



signed main()

{

	scanf("%lld", &n);

	rep(i, 1, n) scanf("%lld", &p[i]);

	init();

	rep(i, 1, n)

	{

		ll tl = bsearch(1, i - 1, p[i], 0), tr = bsearch(i + 1, n, p[i], 1);

		ll sl = bsearch(1, tl - 1, p[i], 0), sr = bsearch(tr + 1, n, p[i], 1);

		ans += p[i] * (sr - tr) * (i - tl);

		ans += p[i] * (tl - sl) * (tr - i);

	}

	printf("%lld\n", ans);

	return 0;

}
