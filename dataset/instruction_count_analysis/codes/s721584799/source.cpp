

#include "stdc++.h"



#define ln                 '\n'

#define all(dat)           dat.begin(), dat.end()

#define loop(i, to)        for (int i = 0; i < to; ++i)

#define cont(i, to)        for (int i = 1; i <= to; ++i)

#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)

#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)



typedef long long          num;



using namespace std;



const int nsz = 2e5;

const num inf = 0x3f3f3f3f3f3f3f3f;

int n;

num d, a[nsz + 5], w1[nsz + 5], w2[nsz + 5];



struct segmnet_tree {

	#define ls  (u << 1)

	#define rs  (u << 1 | 1)

	

	pair<num, int> tr[4 * nsz + 5];

	

	void inline init(num a[], int u = 1, int l = 1, int r = n) {

		if (l == r)  { tr[u] = make_pair(a[l], l); return; }

		int md = (l + r) >> 1;

		init(a, ls, l, md);

		init(a, rs, md + 1, r);

		tr[u] = min(tr[ls], tr[rs]);

	}

	

	void set(int id, num w, int u = 1, int l = 1, int r = n) {

		if (l == r) { tr[u].first = w; return; }

		int md = (l + r) >> 1;

		id <= md ? set(id, w, ls, l, md) : set(id, w, rs, md + 1, r);

		tr[u] = min(tr[ls], tr[rs]);

	}

	

	pair<num, int> qry(int el, int er, int u = 1, int l = 1, int r = n) {

		if (l >= el && r <= er)  return tr[u];

		int md = (l + r) >> 1;

		pair<num, int> res = make_pair(inf, 0);

		if (el <= md)  res = min(res, qry(el, er, ls, l, md));

		if (er > md)  res = min(res, qry(el, er, rs, md + 1, r));

		return res;

	}

};

segmnet_tree tr1, tr2;



struct union_find {

	int sz, pr[nsz + 5];

	vector<int> s[nsz + 5];

	

	int inline operator [] (int id) { return pr[id]; }

	

	void inline init(int sz = n) {

		this->sz = sz;

		cont (u, sz) {

			pr[u] = u;

			s[u].push_back(u);

		}

	}

	

	int qry(int u) { return pr[u]; }

	

	bool inline link(int u, int v) {

		int pu = qry(u), pv = qry(v);

		if (pu == pv)  return 0;

		if (s[pu].size() < s[pv].size())  swap(pu, pv);

		loop (i, s[pv].size()) {

			int v = s[pv][i];

			s[pu].push_back(v);

			pr[v] = pu;

		}

		return 1;

	}

};

union_find uf;



num inline w(int u, int v) {

	if (u < v)  swap(u, v);

	return w1[u] + w2[v];

}



num inline boruvka() {

	uf.init();

	tr1.init(w1);

	tr2.init(w2);

	num res = 0;

	for (int cnt = n; cnt > 1;) {

		vector< pair<int, int> > e;

		cont (u, n) {

			if (uf[u] != u)  continue;

			int su = 0, sv = 0;

			num cur = inf;

			loop (i, uf.s[u].size()) {

				int v = uf.s[u][i];

				tr1.set(v, inf), tr2.set(v, inf);

			}

			loop (i, uf.s[u].size()) {

				int v1 = uf.s[u][i], v2 = tr2.qry(1, v1).second, v3 = tr1.qry(v1, n).second;

				if (v2 && w(v1, v2) < cur)  cur = w(v1, v2), su = v1, sv = v2;

				if (v3 && w(v1, v3) < cur)  cur = w(v1, v3), su = v1, sv = v3;

			}

			loop (i, uf.s[u].size()) {

				int v = uf.s[u][i];

				tr1.set(v, w1[v]), tr2.set(v, w2[v]);

			}

			e.push_back(make_pair(su, sv));

		}

		loop (i, e.size()) {

			int u = e[i].first, v = e[i].second;

			if (!uf.link(u, v))  continue;

			res += w(u, v);

			--cnt;

		}

	}

	return res;

}



int main() {

	scanf("%d%lld", &n, &d);

	cont (i, n) {

		scanf("%lld", &a[i]);

		w1[i] = a[i] + i * d;

		w2[i] = a[i] - i * d;

	}

	printf("%lld\n", boruvka());

}