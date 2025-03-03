#include <cstdio>

#include <algorithm>



typedef long long LL;

const int Mod = 1000000007;

const int MN = 75;



inline int qPow(int b, int e) {

	int a = 1;

	for (; e; e >>= 1, b = (LL)b * b % Mod)

		if (e & 1) a = (LL)a * b % Mod;

	return a;

}



int Fac[100005], iFac[100005];

inline void Init(int N) {

	Fac[0] = 1;

	for (int i = 1; i <= N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;

	iFac[N] = qPow(Fac[N], Mod - 2);

	for (int i = N; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;

}



int Len;

char Str[MN];

int posr[MN], nxposb[MN], rcnt;



int N, Ans;



int stk[MN];

inline void Calc(int cnt, int csum) {

	int Sum = 0;

	if (!cnt) Sum = 1;

	else if (cnt <= rcnt) {

		static int vis[MN];

		for (int i = 1; i <= cnt; ++i) vis[i] = posr[i];

		int tot = cnt, mxp = 1;

		for (int i = 1; i <= cnt && stk[i] >= 2; ++i)

			mxp = vis[++tot] = nxposb[std::max(mxp, vis[i])];

		if (mxp <= Len) {

			std::inplace_merge(vis + 1, vis + cnt + 1, vis + tot + 1);

			int nwp = Len + 1, sum = 0, now = cnt, ok = 1;

			while (now && stk[now] == 1) --now;

			for (int i = tot; i >= 1; --i) {

				sum += nwp - vis[i] - 1;

				if (Str[vis[i]] == 'b') {

					sum -= stk[now] - 2;

					if (sum < 0) { ok = 0; break; }

					--now;

				}

				nwp = vis[i];

			}

			if (ok) {

				Sum = Fac[cnt];

				int len = 0, num = 1;

				for (int i = 1; i <= cnt; ++i) {

					++len;

					num += stk[i] * 2;

					if (i == cnt || stk[i] != stk[i + 1]) {

						Sum = (LL)Sum * iFac[len] % Mod;

						len = 0;

					}

				}

				Sum = (LL)Sum * Fac[N - csum + num] % Mod * iFac[num - 1] % Mod * iFac[N - csum + 1] % Mod;

			}

		}

	}

	Ans -= (Ans += Sum) >= Mod ? Mod : 0;

}

void DFS(int st, int mx, int sum) {

	Calc(st - 1, sum);

	if (sum < N) {

		stk[st] = 1;

		DFS(st + 1, 1, sum + 2);

	}

	for (int i = 2; i <= mx; ++i) {

		if (sum + i * 2 <= N + 3) {

			stk[st] = i;

			DFS(st + 1, i, sum + i * 2 - 2);

		}

	}

}



int main() {

	scanf("%d%d%s", &N, &Len, Str + 1);

	Init(100000);

	for (int i = 1; i <= Len; ++i)

		if (Str[i] == 'r')

			posr[++rcnt] = i;

	int nwposb = Len + 1;

	nxposb[Len + 1] = Len + 1;

	for (int i = Len; i >= 1; --i) {

		nxposb[i] = nwposb;

		if (Str[i] == 'b')

			nwposb = i;

	}

	DFS(1, (N + 3) / 2, 0);

	printf("%d\n", Ans);

	return 0;

}