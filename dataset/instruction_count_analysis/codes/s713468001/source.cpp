#include <cstdio>



typedef long long LL;

const int Mod = 998244353;



inline int qPow(int b, int e) {

	int a = 1;

	for (; e; e >>= 1, b = (LL)b * b % Mod)

		if (e & 1) a = (LL)a * b % Mod;

	return a;

}



const int MN = 500005;



int Fac[MN], iFac[MN];



inline void Init(int N) {

	Fac[0] = 1;

	for (int i = 1; i <= N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;

	iFac[N] = qPow(Fac[N], Mod - 2);

	for (int i = N; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;

}

inline int Binom(int N, int M) {

	if (M < 0 || M > N) return 0;

	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;

}



int N, K, Ans;



int main() {

	scanf("%d%d", &N, &K);

	if (K < N) return puts("0"), 0;

	Init(K);

	for (int R = 0; R <= K; ++R) {

		int B = K - R;

		if (R < B) continue;

		if (R == B) --B;

		Ans = ((LL)Ans + Binom(R + B, R) - Binom(R + B, 2 * R - N + 1) + Mod) % Mod;

	}

	printf("%d\n", Ans);

	return 0;

}



// Luogu : PinkRabbit