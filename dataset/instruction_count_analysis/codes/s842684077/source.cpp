#include "stdc++.h"

using namespace std;



typedef long long   signed int LL;

typedef long long unsigned int LU;



#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)

#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)

#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)

#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)

#define  inc(i, n) incID(i, 0, n)

#define inc1(i, n) incII(i, 1, n)

#define  dec(i, n) decID(i, 0, n)

#define dec1(i, n) decII(i, 1, n)



#define inII(v, l, r) ((l) <= (v) && (v) <= (r))

#define inID(v, l, r) ((l) <= (v) && (v) <  (r))



#define PB push_back

#define EB emplace_back

#define MP make_pair

#define FI first

#define SE second

#define PQ priority_queue



#define  ALL(v)  v.begin(),  v.end()

#define RALL(v) v.rbegin(), v.rend()

#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)

#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)



template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }

template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }

template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }

template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }

template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }

template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }



// ---- ----



const int V = 300002;



struct E { int t; LL c; int r; };

vector<E> g[V];

bool used[V];

const LL INF = 1e12;



void add(int f, int t, LL c) {

	int gt = g[t].size();

	int gf = g[f].size();

	g[f].PB({ t, c, gt });

	g[t].PB({ f, 0, gf });

}



LL dfs(int v, int t, LL f) {

	if(v == t) { return f; }

	

	used[v] = true;

	inc(i, g[v].size()) {

		E & e = g[v][i];

		if(! used[e.t] && e.c > 0) {

			LL d = dfs(e.t, t, min(f, e.c));

			if(d > 0) {

				e.c -= d;

				g[e.t][e.r].c += d;

				return d;

			}

		}

	}

	

	return 0;

}



LL flow(int S, int T) {

	LL ans = 0;

	while(true) {

		inc(i, V) { used[i] = false; }

		LL f = dfs(S, T, INF);

		ans += f;

		if(f == 0) { break; }

	}

	return ans;

}



// ----



LL n, a[101];



int main() {

	cin >> n;

	inc1(i, n) { cin >> a[i]; }

	

	int S = 0;

	int T = 1;

	inc1(i, n) {

		add(S, i * 3 - 1, INF);

		add(i * 3 - 1, i * 3 + 0, max(a[i], 0LL) - a[i]);

		add(i * 3 + 0, i * 3 + 1, max(a[i], 0LL) -  0LL);

		add(i * 3 + 1, T, INF);

	}

	inc1(i, n) {

		for(int j = i * 2; j <= n; j += i) { add(i * 3, j * 3, INF); }

	}

	

	LL ans = -flow(S, T);

	

	inc1(i, n) { ans += max(a[i], 0LL); }

	

	cout << ans << endl;

	

	return 0;

}
