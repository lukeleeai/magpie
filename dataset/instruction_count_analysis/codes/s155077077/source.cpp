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



template<typename C> struct Flow {

	int V;

	C INF;

	struct E { int t, r; C c; };

	vector<vector<E>> g;

	vector<bool> used;

	

	Flow() { }

	Flow(int v, C inf) { init(v, inf); }

	void init(int v, C inf) {

		V = v;

		INF = inf;

		g.resize(V);

		used.resize(V);

	}

	

	void add(int f, int t, C c) {

		assert(inID(f, 0, V));

		assert(inID(t, 0, V));

		int gt = g[t].size();

		int gf = g[f].size();

		g[f].PB({ t, gt, c });

		g[t].PB({ f, gf, 0 });

	}

	

	C dfs(int f, int t, C c) {

		if(f == t) { return c; }

		used[f] = true;

		inc(i, g[f].size()) {

			E & e = g[f][i];

			if(used[e.t] || e.c <= 0) { continue; }

			C v = dfs(e.t, t, min(c, e.c));

			if(v > 0) {

				e.c -= v;

				g[e.t][e.r].c += v;

				return v;

			}

		}

		return 0;

	}

	

	C max_flow(int S, int T) {

		assert(inID(S, 0, V));

		assert(inID(T, 0, V));

		C ans = 0;

		while(true) {

			inc(i, V) { used[i] = false; }

			C f = dfs(S, T, INF);

			ans += f;

			if(f == 0) { break; }

		}

		return ans;

	}

};



// ----



LL n, a[101];



int main() {

	cin >> n;

	inc1(i, n) { cin >> a[i]; }

	

	Flow<LL> f(n * 3 + 2, 1e12);

	

	int S = 0;

	int T = 1;

	inc1(i, n) {

		f.add(        S, i * 3 - 1, f.INF);

		f.add(i * 3 - 1, i * 3 + 0, max(a[i], 0LL) - a[i]);

		f.add(i * 3 + 0, i * 3 + 1, max(a[i], 0LL) -  0LL);

		f.add(i * 3 + 1,         T, f.INF);

	}

	inc1(i, n) {

		for(int j = i * 2; j <= n; j += i) { f.add(i * 3, j * 3, f.INF); }

	}

	

	LL ans = -f.max_flow(S, T);

	

	inc1(i, n) { ans += max(a[i], 0LL); }

	

	cout << ans << endl;

	

	return 0;

}
