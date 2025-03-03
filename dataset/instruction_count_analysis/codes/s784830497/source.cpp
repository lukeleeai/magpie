#include <cstdio>

#include <cmath>

#include <algorithm>



typedef double r64;

const r64 PI = acos(-1);

const r64 C1 = 5 * (PI - 4);

const r64 C2 = 10 * (PI - 2);

const int Inf = 0x3f3f3f3f;

const int MN = 200005;



int sx, sy, tx, ty, N, K, px[MN], py[MN], p[MN];

r64 Ans;



int f[MN];



int main() {

	scanf("%d%d%d%d%d", &sx, &sy, &tx, &ty, &N);

	Ans = 100ll * (abs(tx - sx) + abs(ty - sy));

	if (sx > tx) std::swap(sx, tx), std::swap(sy, ty);

	int rev = sy > ty;

	if (rev) std::swap(sy, ty);

	for (int i = 1, x, y; i <= N; ++i) {

		scanf("%d%d", &x, &y);

		if (x < sx || tx < x || y < sy || ty < y) continue;

		if (rev) y = -y;

		px[++K] = x, py[K] = y, p[K] = K;

	}

	std::sort(p + 1, p + K + 1, [](int i, int j) { return px[i] < px[j]; });

	int num = 0;

	f[0] = -Inf;

	for (int i = 1; i <= K; ++i) f[i] = Inf;

	for (int i = 1; i <= K; ++i) {

		int v = py[p[i]];

		int j = std::lower_bound(f, f + K + 1, v) - f;

		if (num < j) num = j;

		f[j] = v;

	}

	if (num == std::min(tx - sx, ty - sy) + 1) Ans += (num - 1) * C1 + C2;

	else Ans += num * C1;

	printf("%.15lf\n", Ans);

	return 0;

}