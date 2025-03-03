/* 

/*-----------------------------------------------*/

#include <cstdio>

#include <cstring>

#include <string>

#include <vector>

#include <cmath>

#include <algorithm>

#include <queue>

#include <map>

using namespace std;

typedef vector<int> vi;

typedef pair<int, int> ii;

typedef vector<ii> vii;

typedef long long int ll;

typedef vector<ll> vll;

/*-----------------------------------------------*/

// #define DBGMODE

#ifdef DBGMODE

	#define debug(...) fprintf(stderr, __VA_ARGS__)

#else

	#define debug(...)

#endif

/*-----------------------------------------------*/

ll add_mod (ll a, ll b, ll p) { ll res = a + b; if (res > p) res -= p; return res; }

ll sub_mod (ll a, ll b, ll p) { ll res = a - b; if (res < 0) res += p; return res; }

const ll MOD = 1e9 + 7;

int N;

ll dp[110][5][5][5];



ll solve () {

	memset(dp, 0, sizeof dp);

	for (int x = 0; x < 4; x++)

		for (int y = 0; y < 4; y++)

			for (int z = 0; z < 4; z++) {

				ll &val = dp[3][x][y][z];

				if 		(x == 0 && y == 2 && z == 1) val = 0;

				else if (x == 0 && y == 1 && z == 2) val = 0;

				else if (x == 2 && y == 0 && z == 1) val = 0;

				else val = 1;

			}



	for (int i = 4; i <= N; i++)

		for (int x = 0; x < 4; x++) 

			for (int y = 0; y < 4; y++) 

				for (int z = 0; z < 4; z++) {

					for (int j = 0; j < 4; j++) dp[i][y][z][j] = add_mod(dp[i][y][z][j], dp[i - 1][x][y][z], MOD);

					if ((x == 0 && y == 2) ||

						(x == 0 && z == 2) ||

						(y == 0 && z == 2) ||

						(y == 2 && z == 0)) dp[i][y][z][1] = 0;

					if (y == 0 && z == 1) 	dp[i][y][z][2] = 0;

				}

	ll ans = 0;

	for (int x = 0; x < 4; x++)

		for (int y = 0; y < 4; y++)

			for (int z = 0; z < 4; z++)

				ans = add_mod(ans, dp[N][x][y][z], MOD);

	return ans;

}

/*-----------------------------------------------*/

int main() {

	#ifdef DBGMODE

		freopen("input.txt", "r", stdin);

		freopen("output.txt", "w", stdout);

	#endif

	scanf("%d", &N);

	printf("%lld\n", solve());

}