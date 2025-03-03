#include <cstdio>

#include <algorithm>

#include <vector>

#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)



inline int read()

{

	int data = 0, w = 1; char ch = getchar();

	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();

	if (ch == '-') w = -1, ch = getchar();

	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();

	return data * w;

}



const int maxn(100010), Mod(1e9 + 7);

int n, m, A[maxn], B[maxn], S[maxn], c[maxn], f[maxn], tot;

struct node { int x, y; } P[maxn];

inline bool operator == (const node &lhs, const node &rhs)

	{ return lhs.x == rhs.x && lhs.y == rhs.y; }

void Add(int x, int v) { for (; x <= tot; x += x & -x) c[x] = (c[x] + v) % Mod; }

int Sum(int x) { int ans = 0; for (; x; x -= x & -x) ans = (ans + c[x]) % Mod; return ans; }



int main()

{

	n = read(), m = read();

	for (int i = 1; i <= n; i++) A[i] = read();

	for (int i = 1; i <= m; i++) B[i] = read();

	P[tot = 1] = (node) {0, 0};

	for (int i = 1, j; i <= n; i++)

	{

		j = std::upper_bound(B + 1, B + m + 1, A[i]) - B;

		if (j > 1 && j <= m) P[++tot] = (node) {A[i] - B[j - 1], B[j] - A[i]};

	}

	P[n = ++tot] = (node) {(int)1e9, (int)1e9}, tot = 0;

	for (int i = 1; i <= n; i++) S[i] = P[i].y;

	std::sort(S + 1, S + n + 1), tot = std::unique(S + 1, S + n + 1) - S - 1;

	for (int i = 1; i <= n; i++)

		P[i].y = std::lower_bound(S + 1, S + tot + 1, P[i].y) - S;

	std::sort(P + 1, P + n + 1, [] (const node &lhs, const node &rhs)

			{ return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y; });

	n = std::unique(P + 1, P + n + 1) - P - 1;

	Add(P[1].y, 1);

	for (int i = 2, j; i <= n; i = j)

	{

		for (j = i; j <= n && P[j].x == P[i].x; j++);

		for (int k = i; k < j; k++) f[k] = Sum(P[k].y - 1);

		for (int k = i; k < j; k++) Add(P[k].y, f[k]);

	}

	printf("%d\n", f[n]);

	return 0;

}
