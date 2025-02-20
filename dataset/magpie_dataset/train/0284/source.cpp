#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <cmath>

#include <cstdio>

#include <functional>

#include <numeric>

#include <stack>

#include <queue>

#include <map>

#include <set>

#include <utility>

#include <sstream>

#include <complex>

#include <fstream>

#include <bitset>

#include <time.h>

#include <tuple>



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;

typedef vector<ll> V;

typedef complex<double> Point;



#define PI acos(-1.0)

#define EPS 1e-10

const ll INF = 1e12;

const ll MOD = 1e9 + 7;



#define FOR(i,a,b) for(ll i=(a);i<(b);i++)

#define rep(i,N) for(ll i=0;i<(N);i++)

#define ALL(s) (s).begin(),(s).end()

#define EQ(a,b) (abs((a)-(b))<EPS)

#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

#define fi first

#define se second

#define N_SIZE (1LL << 20)

#define NIL -1

#define MAX_N 100100



ll sq(ll num) { return num*num; }

ll mod_pow(ll x, ll n) {

	if (n == 0)return 1;

	if (n == 1)return x%MOD;

	ll res = sq(mod_pow(x, n / 2));

	res %= MOD;

	if (n % 2 == 1) {

		res *= x;

		res %= MOD;

	}

	return res;

}

ll mod_add(ll a, ll b) { return (a + b) % MOD; }

ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }

ll mod_mul(ll a, ll b) { return a*b % MOD; }



int w, h;

char s[100][100];



struct edge {

	int to;

	ll cost;

};



ll dx[2][10] = { { 1,1,1, 1, 1,2,2, 2,3 },{ -1,-1,-1,-1,-1,-2,-2,-2,-3 } };

ll dy[2][10] = { { 2,1,0,-1,-2,1,0,-1,0 },{  2, 1, 0,-1,-2, 1, 0,-1, 0 } };

ll d[2][100][100];

vector<edge> G[100010];//各頂点からの辺



void dijkstra(P start, bool _t) {

	rep(i, 100)rep(j, 100) {

		d[0][i][j] = INF;

		d[1][i][j] = INF;

	}

	d[_t][start.first][start.second] = 0;



	typedef pair<P, P> PP;



	priority_queue<PP, vector<PP>, greater<PP>> que;

	que.push({ { 0,_t },start });



	while (que.size()) {

		PP p = que.top();

		que.pop();

		int y = p.second.first;

		int x = p.second.second;

		int t = p.first.second;

		for (int i = 0; i < 9; i++) {

			int ny = y + dy[t][i];

			int nx = x + dx[t][i];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w)continue;

			if (s[ny][nx] == 'X')continue;

			if (d[!t][ny][nx] > d[t][y][x] + s[ny][nx] - '0') {

				d[!t][ny][nx] = d[t][y][x] + s[ny][nx] - '0';

				que.push({ { d[!t][ny][nx],!t}, P(ny,nx) });

			}

		}

	}

}



vector<P> S, T;



int main() {

	while (cin >> w >> h&&w + h) {

		S.clear();

		T.clear();

		rep(i, h) {

			rep(j, w) {

				cin >> s[i][j];

				if (s[i][j] == 'S') {

					S.push_back(P(i, j));

					s[i][j] = '0';

				}

				if (s[i][j] == 'T') {

					T.push_back(P(i, j));

					s[i][j] = '0';

				}

			}

		}

		ll ans = INF;

		rep(i, S.size()) {

			dijkstra(S[i], 0);

			rep(j, T.size()) {

				ans = min(ans, d[0][T[j].first][T[j].second]);

				ans = min(ans, d[1][T[j].first][T[j].second]);

			}

			dijkstra(S[i], 1);

			rep(j, T.size()) {

				ans = min(ans, d[0][T[j].first][T[j].second]);

				ans = min(ans, d[1][T[j].first][T[j].second]);

			}

		}

		if (ans == INF)cout << -1 << endl;

		else cout << ans << endl;

	}

}
