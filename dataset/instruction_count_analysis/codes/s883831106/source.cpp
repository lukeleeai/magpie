#include "stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")

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

const lint INF = 1e18;

const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN], n, k;

struct Segment_tree {

	#define lson tree[root].ls

	#define rson tree[root].rs

	#define stdl (tree[root].sl)

	#define stdr (tree[root].sr)

	#define mid ((stdl + stdr) >> 1)

	struct Node {

		int sl, sr, ls, rs;

		lint val, rval, cover;

		Node () : ls(-1), rs(-1), cover(-1) {} 

	};

	vector<Node> tree;

	inline int new_Node(int l, int r) {

		static int root = 0;

		tree.pb(Node());

		stdl = l, stdr = r;

		tree[root].val = 0;

		tree[root].rval = l;

		return root++;

	}

	inline void update(int root) {

		if (~tree[root].cover) {

			tree[root].val = tree[root].cover;

			tree[root].rval = stdl + tree[root].cover;

		} else {

			tree[root].val = min(tree[lson].val, tree[rson].val);

			tree[root].rval = min(tree[lson].rval, tree[rson].rval);

		}

	}

	inline void pushdown(int root) {

		int L = lson, R = rson;

		if (lson == -1) L = new_Node(stdl, mid);

		if (rson == -1) R = new_Node(mid + 1, stdr);

		lson = L, rson = R;

		/*

			lson = new_Node(stdl, mid); ? RE

		*/

		if (~tree[root].cover) {

			tree[lson].cover = tree[rson].cover = tree[root].cover;

			update(lson), update(rson), tree[root].cover = -1;

		}

	}

	inline void replace(int root, int l, int r, lint p) {

		if (l <= stdl && stdr <= r) {

			tree[root].cover = p;

			update(root);

			return;

		}

		pushdown(root);

		if (l <= mid) replace(lson, l, r, p);

		if (r >= mid + 1) replace(rson, l, r, p);

		update(root);

	}

	inline lint query(int root, int l, int r) {

		if (l <= stdl && stdr <= r) {

			return tree[root].rval;

		}

		pushdown(root);

		lint ret = INF;

		if (l <= mid) ret = min(ret, query(lson, l, r));

		if (r >= mid + 1) ret = min(ret, query(rson, l, r));

		return ret;

	}

	#undef lson

	#undef rson

	#undef stdl

	#undef stdr

	#undef mid

	/*lint tree[10086];

	inline void new_Node(int l, int r) {

		rep (i, l, r) {

			tree[i] = i;

		}

	}

	inline void replace(int root, int l, int r, lint p) {

		rep (i, l, r) { tree[i] = i + p; }

	}

	inline lint query(int root, int l, int r) {

		lint ret = INF;

		rep (i, l, r) { ret = min(ret, tree[i]); }

		return ret;

	}

	inline lint query2(int root, int l, int r) {

		lint ret = INF;

		rep (i, l, r) { ret = min(ret, tree[i] - i); }

		return ret;

	}*/

}	Tree;

inline lint getquery(lint T) {

	return min(Tree.query(0, 0, T) + k - T, Tree.query(0, T, k - 1) - T);

}

int main() {

	ios::sync_with_stdio(false);

	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> k;

	Tree.new_Node(0, k - 1);

	lint ans = 0, res, T = 0;

	rep (i, 1, n) {

		cin >> a[i] >> b[i];

		ans += (a[i] <<= 1);

	}

	rep (i, 1, n) {

		if (b[i] == 1) {

			if (a[i] > k) {

				puts("-1"); return 0;

			}

			lint l = (T + 1) % k;

			lint r = (T + a[i] - 1) % k;

			lint val = getquery(T);

			if (l > r) {

				Tree.replace(0, 0, r, INF);

				Tree.replace(0, l, k - 1, INF);

			} else {

				Tree.replace(0, l, r, INF);

			}

			Tree.replace(0, T, T, val);

			T = (T + a[i]) % k;

		} else {

			T = (T + a[i]) % k;

			Tree.replace(0, T, T, getquery(T));

		}

	}

	res = Tree.tree[0].val;

	cout << (res < INF ? res + ans : -1) << endl;

	return 0;

}