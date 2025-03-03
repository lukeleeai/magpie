#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <utility>



using namespace std;



typedef pair<int, int> pii;



#define fst first

#define scd second

#define rep(i,x) for(int i=0;i<(x);++i)



template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}



const int inf = 1e9;



int k[150];

vector<pii> stone[150];

int N, M;



int memo[150][150][10];



int rec(int n, int m, int i)

{

	if (n >= N - 1) return 0;



	if (~memo[n][m][i]) return memo[n][m][i];



	int res = inf;



	rep(j, k[n + 1]) {

		int dist = (stone[n][i].scd + stone[n + 1][j].scd) * abs(stone[n][i].fst - stone[n + 1][j].fst);

		chmin(res, dist + rec(n + 1, m, j));

	}



	if (m < M) {

		if (n + 2 >= N) return 0;

		rep(j, k[n + 2]) {

			int dist = (stone[n][i].scd + stone[n + 2][j].scd) * abs(stone[n][i].fst - stone[n + 2][j].fst);

			chmin(res, dist + rec(n + 2, m + 1, j));

		}

	}



	return memo[n][m][i] = res;

}



signed main()

{

	while (scanf("%d %d", &N, &M), N || M) {

		rep(i, N) {

			scanf("%d", &k[i]);



			stone[i].resize(k[i]);



			rep(j, k[i]) {

				int x, d; scanf("%d %d", &x, &d);

				stone[i][j].fst = x, stone[i][j].scd = d;

			}

		}



		int ans = inf;



		rep(i, k[0]) {

			memset(memo, -1, sizeof(memo));

			chmin(ans, rec(0, 0, i));

		}



		if (M > 0) {

			rep(i, k[1]) {

				memset(memo, -1, sizeof(memo));

				chmin(ans, rec(1, 1, i));

			}

		}



		printf("%d\n", ans);

	}

}