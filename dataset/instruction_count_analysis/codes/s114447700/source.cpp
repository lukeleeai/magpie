/*

* Problem link

* 

*/



#include"stdc++.h"

using namespace std;



struct INIT{INIT(){cin.tie(0);ios_base::sync_with_stdio(false);} }init;

#define rep(i,n) for(auto i=(n)*0;i<n;i++)

typedef long long LL;

const LL INF = (LL)1e9;

typedef vector<LL> V;

typedef vector<V> VV;

inline LL calc(LL d, V& dist, V& cost) {

	LL sum = 0;

	int p = dist.size() - 1;

	rep(i, p) {

		if (dist[i] <= d&&d <= dist[i + 1]) {

			return sum + (d - dist[i])*cost[i];

		}

		sum += (dist[i + 1] - dist[i])*cost[i];

	}

	return INF;

}

int main() {

#ifdef INPUT_FROM_FILE

	ifstream cin("sample.in");

	ofstream cout("sample.out");

#endif

	int N, M, C, S, G;

	while (cin >> N >> M >> C >> S >> G, N + M + C + S + G>0) {

	

		VV cost(N, V(N, INF));

		vector<VV> dist(C, VV(N, V(N, INF)));

		

		rep(i, N) {

			cost[i][i] = 0;

			rep(j, C)dist[j][i][i] = 0;

		}

		rep(i, M) {

			int x, y, c; LL d;

			cin >> x >> y >> d >> c;

			x--; y--; c--;

			dist[c][x][y] = dist[c][y][x] = min(dist[c][y][x], d);

		}

		vector<int> p(C);

		rep(i, C)cin >> p[i];

		VV q(C), r(C);

		rep(i, C) {

			q[i].resize(p[i]);

			r[i].resize(p[i]);

			q[i][0] = 0;

			rep(j, p[i] - 1)cin >> q[i][j + 1];

			rep(j, p[i])cin >> r[i][j];

			q[i].push_back(INF);

				

		}

		rep(c, C)rep(k, N)rep(i, N)rep(j, N)dist[c][i][j] = min(dist[c][i][j], dist[c][i][k] + dist[c][k][j]);

		rep(c, C)rep(i, N)rep(j, N)cost[i][j] = min(cost[i][j], calc(dist[c][i][j], q[c], r[c]));

		rep(k, N)rep(i, N)rep(j, N)cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

		if (cost[S - 1][G - 1] == INF)cout << -1 << endl;

		else cout << cost[S - 1][G - 1] << endl;

	}

	return 0;

}