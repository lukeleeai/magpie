#include "stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")

template <typename T>

inline void read(T &x) {

	x = 0;

	bool sign = false;

	char ch = getchar();

	while (ch < '0' || '9' < ch) {

		sign |= ch == '-';

		ch = getchar();

	}

	while ('0' <= ch && ch <='9') {

		x = (x << 3) + (x << 1) + (ch ^ 48);

		ch = getchar();

	}

	x = sign ? -x : x;

}

template <typename T>

inline void print(T x) {

	static char outp[128];

	int tot = 0;

	if (!x) {

		putchar('0');

		return;

	} else if (x < 0) {

		x = -x;

		putchar('-');

	}

	while (x) { outp[tot++] = x % 10, x /= 10; }

	while (tot) { putchar(outp[--tot] + 48); }

}

typedef long long lint;

typedef unsigned int uint;

typedef pair<int, int> pii;

typedef pair<lint, lint> pll;

typedef unsigned long long ulint;

#define endl '\n'

#define fst first

#define sed second

#define pb push_back

#define mp make_pair

#define rint register int

#define newline putchar('\n')

#define leave_space putchar(' ')

#define all(x) (x).begin(), (x).end()

#define reveal(x) cerr << #x << " = " << (x) << endl

#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)

#define per(it, f, e) for (rint it = (f); it >= (e); --it)

const int INF = 2e9;

const int MAXN = 2e5 + 10;

const int MAXV = (1 << 20) + 10;

int n, ary[MAXN], whe[MAXN];

struct Segment_tree {

	#define lson (root << 1)

	#define rson (root << 1 | 1)

	#define mid ((tree[root].stdl + tree[root].stdr) >> 1)

	int flag;

	struct Node {

		int val;

		int stdl, stdr;

	}	tree[MAXV];

	inline void buildtree(int root, int l, int r) {

		tree[root].stdl = l;

		tree[root].stdr = r;

		if (l == r) {

			tree[root].val = (l & 1) == flag ? ary[l] : INF;

			return;

		}

		buildtree(lson, l, mid);

		buildtree(rson, mid + 1, r);

		tree[root].val = min(tree[lson].val, tree[rson].val);

	}

	inline void build(int N, int F) {

		flag = F;

		buildtree(1, 1, N);

	}

	inline int query(int root, int l, int r) {

		if (l <= tree[root].stdl && tree[root].stdr <= r) {

			return tree[root].val;

		}

		int ret = INF;

		if (l <= mid) ret = min(ret, query(lson, l, r));

		if (r > mid) ret = min(ret, query(rson, l, r));

		return ret;

	}

}	Tree[2];

#define X fst.fst

#define Y fst.sed

#define LL sed.fst

#define RR sed.sed

#define SEG(a, b, c, d) mp(mp(a, b), mp(c, d))

typedef pair<pii, pii> seg;

priority_queue<seg, vector<seg>, greater<seg> > que;

inline seg data(int l, int r) {

	int OO = (l & 1) ^ 1;

	int L = whe[Tree[OO].query(1, l, r)];

	int R = whe[Tree[OO ^ 1].query(1, L, r)];

	return SEG(ary[L], ary[R], l, r);

}

int main() {

	read(n);

	rep (i, 1, n) {

		read(ary[i]);

		whe[ary[i]] = i;

	}

	Tree[0].build(n, 1);

	Tree[1].build(n, 0);

	int L = whe[Tree[0].query(1, 1, n)];

	int R = whe[Tree[1].query(1, L, n)];

	que.push(SEG(ary[L], ary[R], 1, n));

	while (!que.empty()) {

		seg ft = que.top();

		que.pop();

		print(ft.X);

		leave_space;

		print(ft.Y);

		leave_space;

		L = whe[ft.X];

		R = whe[ft.Y];

		if (R - L > 1) que.push(data(L + 1, R - 1));

		if (L != ft.LL) que.push(data(ft.LL, L - 1));

		if (R != ft.RR) que.push(data(R + 1, ft.RR));

	}	newline;

	return 0;

}