#include <cstdio>



typedef long long ll;



const int MAXN = 2E3 + 10;

const int MOD = 1E9 + 7;



ll modExp(ll e, ll n, ll m = MOD){

	ll ret = 1;

	for (; n; n >>= 1, e = e * e % m)

		if (n & 1)

			ret = ret * e % m;

	return ret;

}



inline void update(int &x, int y){

	if ((x += y) >= MOD)

		x -= MOD;

}



int f[MAXN][MAXN];



int main(){

	int n, k;

	scanf("%d%d", &n, &k);

	f[0][0] = 1;

	for (int i = 1; i < k; ++i){

		int s = f[i - 1][i - 1];

		for (int j = i; j < n; ++j){

			update(f[i][j], s);

			update(f[i][j], f[i - 1][j]);

			update(s, f[i - 1][j]);

		}

	}

	int ans = 0;

	for (int i = 0; i < n; ++i)

		update(ans, f[k - 1][i]);

	printf("%d\n", (int)(ans * modExp(2, n == k ? 0 : n - k - 1) % MOD));

	return 0;

}
