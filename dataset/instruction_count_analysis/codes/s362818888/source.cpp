#include <utility>

#include <algorithm>

#include <cstdio>



using namespace std;

using ll = long long;

using pll = pair<ll, ll>;

#define a first

#define b second



static const int MAXN = 200100;



static pll pnts[MAXN];

struct CHT

{

	int ptr = 0, sz = 0;



	bool bad(pll p0, pll p1, pll p2) { return (p1.a - p0.a) * (p2.b - p0.b) - (p2.a - p0.a) * (p1.b - p0.b) > 0; }

	void add(pll p)

	{

		while (sz > 1 && bad(pnts[sz - 2], pnts[sz - 1], p)) --sz;

		pnts[sz++] = p;

	}

	ll val(int i, ll x) { return pnts[i].a * x + pnts[i].b; }

	ll get(ll x)

	{

		ptr = min(ptr, sz - 1);

		while (ptr < sz - 1 && val(ptr, x) > val(ptr + 1, x)) ++ptr;

		return val(ptr, x);

	}

} cht;



int N;

ll h, c, f;



int main()

{

	scanf("%d %lld", &N, &c);

	for (int i = 0; i < N; ++i) {

		scanf("%lld", &h);

		f = (i == 0 ? 0 : cht.get(h) + h * h + c);

		cht.add(pll(-2 * h, h * h + f));

	}

	printf("%lld\n", f);

}