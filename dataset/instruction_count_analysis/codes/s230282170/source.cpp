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

#include<utility>

#include <complex>

#define M_PI 3.141592653589793238

using namespace std;

//long long p = 998244353;

long long p = 1000000007;

#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()

#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()

#define int long long

#define ll long long

#define vel vector<ll>

#define vvel vector<vel>

#define rep(i,n) for(int i=0;i<n;i++)

#define sor(v) sort(v.begin(),v.end())

#define mmax(a,b) a=max(a,b)

#define mmin(a,b) a=min(a,b)

#define mkp(a,b) make_pair(a,b)

#define pin pair<ll,ll>

#define qin pair<pin,int>

#define V vector

#define Endl endl

#define veb vector<bool>

#define fcout cout << fixed << setprecision(15)

#define rev(s) reverse(s.begin(),s.end())

#define lower(h,val) (lower_bound(h.begin(),h.end(),val)-h.begin())

#define upper(h,val) (upper_bound(h.begin(),h.end(),val)-h.begin())

#define vveb V<veb>

#define omajinai cin.tie(0);ios::sync_with_stdio(false);

#define endl "\n"

#define pb push_back

vel kai;

vel inv_kai;

int root(int x, vel& pa) {

	if (pa[x] == -1) { return x; }

	int ans = root(pa[x], pa); pa[x] = ans;

	return ans;

}

bool mar(int x, int y, vel& pa) {

	x = root(x, pa);

	y = root(y, pa);

	if (x != y) { pa[x] = y; }

	return (x != y);

}

int gcd(int x, int y) {

	if (x < y) { return gcd(y, x); }

	if (y == 0) { return x; }

	return gcd(y, x % y);

}

int lcm(ll x, ll y) {

	x = abs(x); y = abs(y);

	return x * (y / gcd(x, y));

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

void make_kai(int max_kai,int p) {

	kai = vel(max_kai, 1);

	inv_kai = kai;

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

vel dijk(V<V<pin>>& way, int st, int inf) {

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

void make_tree(vvel& chi, vel& par,int n) {

	V<V<pin>> way(n);

	rep(i, n - 1) {

		int a, b; cin >> a >> b; a--; b--;

		way[a].push_back(mkp(b, 1));

		way[b].push_back(mkp(a, 1));

	}

	vel dist = dijk(way, 0, n + 1);

	par = vel(n,-1);

	chi = vvel(n);

	rep(i, n) {

		for (auto nex : way[i]) {

			int pot = nex.first;

			if (dist[pot] > dist[i]) { chi[i].push_back(pot); }

			else { par[i] = pot; }

		}

	}

}

void pri(vel& v) {

	if (v.size() == 0) { return; }

	cout << v[0];

	rep(i, v.size() - 1) { cout << " " << v[i + 1]; }

	cout << endl;

	return;

}

int modpow(int a, int n, int p) {

	if (n == 0) { return 1; }

	int m = n / 2;

	int x = modpow(a, n / 2, p);

	x *= x; x %= p;

	if (n % 2 == 1) { x *= a; x %= p; }

	return x;

}

int solve(int n, int x, vel& a,vel&b) {

	if (n == 0) {

		return x;

	}

	if (x == 0) { return 0; }

	if (x <= a[n-1] + 1) { return solve(n - 1, x - 1, a, b); }

	return b[n-1] + 1 + solve(n - 1, min(x - a[n - 1] - 2, a[n - 1]), a,b);

}

signed main() {

	int n,m; cin >> n>>m;

	vel a(n);

	rep(i, n) { cin >> a[i]; a[i] /= 2; }

	vel b = a;

	while (true) {

		int cnt = 0;

		rep(i, n) {

			if (b[i] % 2 == 0) { cnt++;b[i]/=2; }

		}

		if (cnt == 0) { break; }

		if (cnt < n) { cout << 0 << endl; return 0; }

	}

	int lc = 1;

	rep(i, n) {

		lc = lcm(lc,a[i]);

		if (lc > m) { cout << 0 << endl; return 0; }

	}

	int ans = m / lc;

	cout << (ans + 1) / 2 << endl;

	return 0;

}