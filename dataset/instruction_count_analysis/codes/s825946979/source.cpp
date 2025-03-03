#include <cstdio>

#include <algorithm>

#include <vector>

#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)



const int N(1e5 + 10);

struct edge { int x, y; } e[N];

struct node { long long d; int id; } a[N];

inline int operator < (const node &l, const node &r)

	{ return l.d < r.d; }

int n, size[N], cnt;



int main()

{

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)

		scanf("%lld", &a[i].d), a[i].id = i, size[i] = 1;

	std::sort(a + 1, a + n + 1);

	long long dis = 0, d;

	for (int i = n, p; i > 1; i--)

	{

		d = a[i].d - n + (size[i] << 1), p = std::lower_bound(a + 1, a + n + 1, (node) {d, 0}) - a;

		if (a[p].d != d) return puts("-1"), 0;

		e[++cnt] = (edge) {a[i].id, a[p].id}, size[p] += size[i], dis += size[i];

	}

	if (dis != a[1].d) puts("-1");

	else for (int i = 1; i < n; i++) printf("%d %d\n", e[i].x, e[i].y);

	return 0;

}
