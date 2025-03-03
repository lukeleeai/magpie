#include "stdc++.h"

 

#define MAXN (1 << 18)

#define ll long long

 

int n, q, A, B;

int x[MAXN];

ll seg1[MAXN << 1], seg2[MAXN << 1];

 

ll query(ll *seg, int u, int l, int r, int ql, int qr){

	if(ql <= l && r <= qr) return seg[u];

	int m = l + r >> 1, ls = u << 1, rs = ls | 1;

	ll ret = LLONG_MAX;

	if(!(m < ql)) ret = std::min(ret, query(seg, ls, l, m, ql, qr));

	if(!(qr < m + 1)) ret = std::min(ret, query(seg, rs, m + 1, r, ql, qr));

	return ret;

}

 

void insert(ll *seg, int u, int l, int r, int pos, ll val){

	if(l == r){

		seg[u] = val;

		return;

	}

	int m = l + r >> 1, ls = u << 1, rs = ls | 1;

	if(pos <= m) insert(seg, ls, l, m, pos, val);

	else insert(seg, rs, m + 1, r, pos, val);

	seg[u] = std::min(seg[ls], seg[rs]);

}

 

int main(){

	scanf("%d%d%d%d", &n, &q, &A, &B);

	memset(seg1, 0x7f, sizeof seg1);

	memset(seg2, 0x7f, sizeof seg2);

	x[0] = B;

	insert(seg1, 1, 1, n, A, A);

	insert(seg2, 1, 1, n, A, -A);

	ll delta = 0;

	for(int i = 1; i <= q; ++ i){

		scanf("%d", x + i);

		

		ll tmp1 = query(seg1, 1, 1, n, x[i] + 1, n) - x[i];

		ll tmp2 = query(seg2, 1, 1, n, 1, x[i]) + x[i];

		tmp1 = std::min(tmp1, tmp2);

		

//		ll now = query(seg1, 1, 1, n, x[i - 1], x[i - 1]) - x[i - 1] + delta;

//		if(tmp1 < now){

			insert(seg1, 1, 1, n, x[i - 1], tmp1 + x[i - 1] - std::abs(x[i] - x[i - 1]));

			insert(seg2, 1, 1, n, x[i - 1], tmp1 - x[i - 1] - std::abs(x[i] - x[i - 1]));

//		}

		

		delta += std::abs(x[i] - x[i - 1]);

	}

	ll ans = LLONG_MAX;

	for(int i = 1; i <= n; ++ i){

		ans = std::min(ans, query(seg1, 1, 1, n, i, i) - i + delta);

	}

	printf("%lld\n", ans);

	return 0;

}