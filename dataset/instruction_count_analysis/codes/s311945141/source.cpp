#include "stdc++.h"                                           

 

#define int long long

//#pragma GCC optimize("Ofast")

//#pragma GCC optimize("unroll-loops")

//#pragma comment(linker, "/stack:200000000")

//#pragma GCC optimize("Ofast,no-stack-protector") 

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

 

 

#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);

#define forev(i, b, a) for(int i = (b); i >= (a); --i)

#define forn(i, a, b) for(int i = (a); i <= (b); ++i)

#define all(x) x.begin(), x.end()

#define sz(s) (int)s.size()

#define pb push_back

#define ppb pop_back

#define mp make_pair

#define s second

#define f first

 

 

using namespace std;

 

 

typedef pair < long long, long long > pll;    

typedef pair < int, int > pii;

typedef unsigned long long ull;         

typedef vector < pii > vpii;

typedef vector < int > vi;

typedef long double ldb; 

typedef long long ll;  

typedef double db;                         

 

 

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, block = 555;

const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);

const int inf = 1e9, N = 2e5 + 48, mod = 1e9 + 7;

const db eps = 1e-12, pi = 3.14159265359;

const ll INF = 1e18;





int n, m, l, r, x, t[N << 2], add[N << 2], dp[N];

vpii gg[N];

vi g[N];





void push (int v) {

	if (add[v]) {

		add[v << 1] += add[v];

		add[v << 1 | 1] += add[v];

		t[v << 1] += add[v];

		t[v << 1 | 1] += add[v];

		add[v] = 0;

	}

}





void update (int l, int r, int x, int v = 1, int tl = 0, int tr = n) {

	if (l > r || l > tr || tl > r) 

		return;

	

	if (l <= tl && tr <= r) {

		t[v] += x;

		add[v] += x;

		return;

	}



	push(v);

	int tm = (tl + tr) >> 1;

	update(l, r, x, v << 1, tl, tm);

	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = max(t[v << 1], t[v << 1 | 1]);

}



int get (int l, int r, int v = 1, int tl = 0, int tr = n) {

	if (l > r || tl > r || l > tr)

		return -INF;



	if (l <= tl && tr <= r) 

		return t[v]; 

	



	push(v);

	int tm = (tl + tr) >> 1;

	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));

}







main () {

	cin >> n >> m;

	while (m--) {

		cin >> l >> r >> x;

		g[l].pb(x);		

		gg[r + 1].pb({l, x});

	}





	forn (i, 1, n) {

		for (auto x : g[i]) 

			update(0, i - 1, x); 



		for (auto x : gg[i]) 

			update(0, x.f - 1, -x.s); 



		dp[i] = get(0, i - 1);			

		update(i, i, dp[i]);					

	}	

	



	cout << *max_element(dp, dp + 1 + n);	

}          

 