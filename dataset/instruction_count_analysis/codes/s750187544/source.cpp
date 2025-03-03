#include <algorithm>

#include <cstdio>

#include <cstring>



typedef long long LL;



const int MAXN = 200000;

const int MOD = 1000000007;

const int INF = 1000000001;



int N, X, Y, C[MAXN + 5], W[MAXN + 5];



int Min[MAXN + 5], Cnt[MAXN + 5];



int Fac[MAXN + 5], Inv[MAXN + 5];



int Pow(int x, int y) {

	int ret = 1;

	while (y) {

		if (y & 1)

			ret = (LL)ret * x % MOD;

		y >>= 1;

		x = (LL)x * x % MOD;

	}

	return ret;

}



int main() {

	scanf("%d%d%d", &N, &X, &Y);

	Fac[0] = 1;

	for (int i = 1; i <= N; i++)

		Fac[i] = (LL)Fac[i - 1] * i % MOD;

	Inv[N] = Pow(Fac[N], MOD - 2);

	for (int i = N - 1; i >= 0; i--)

		Inv[i] = (LL)Inv[i + 1] * (i + 1) % MOD;

	for (int i = 0; i <= N; i++)

		Min[i] = INF;

	for (int i = 1; i <= N; i++) {

		scanf("%d%d", &C[i], &W[i]);

		Cnt[C[i]]++;

		Min[C[i]] = std::min(Min[C[i]], W[i]);

	}

	int fir = std::min_element(Min + 1, Min + N + 1) - Min, sec = 0;

	for (int i = 1; i <= N; i++)

		if (i != fir && Min[i] < Min[sec])

			sec = i;

	for (int i = 1; i <= N; i++) { // 对于每个球

		if (W[i] != Min[C[i]] && W[i] + Min[C[i]] <= X) // 内部就可以交换

			continue;

		if (C[i] != fir && W[i] + Min[fir] <= Y) // 可交换出去

			continue;

		if (C[i] == fir && W[i] + Min[sec] <= Y) // 可交换出去

			continue;

		Cnt[C[i]]--; // 该球无法移动

	}

	int tot = 0, Ans = 1;

	for (int i = 1; i <= N; i++) // 合并每个颜色的连通块

		if (Min[i] + Min[fir] <= Y)

			Ans = (LL)Ans * Inv[Cnt[i]] % MOD, tot += Cnt[i];

	printf("%d", (LL)Ans * Fac[tot] % MOD);

}