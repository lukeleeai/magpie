#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <stack>

#include <queue>

#include <set>

#include <cmath>

#include <map>

using namespace std;

#define MOD 1000000007

#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)

typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;



int R, C, N;

int Ri[101010], Ci[101010], Ai[101010];



int uf[201010];

i64 ofs[201010];

i64 mn[201010];



pair<int, i64> root(int p)

{

	if (uf[p] < 0) return{ p, 0LL };

	auto tmp = root(uf[p]);

	tmp.second += ofs[p];

	uf[p] = tmp.first;

	ofs[p] = tmp.second;

	return tmp;

}



bool join(int p, int q, i64 d)

{

	// v[p] = v[q] + d

	auto r1 = root(p), r2 = root(q);

	if (r1.first == r2.first) {

		if (r1.second != r2.second - d) return true;

		return false;

	}

	d += r1.second - r2.second;

	p = r1.first;

	q = r2.first;

	if (0 && uf[p] < uf[q]) {

		swap(p, q);

		d *= -1;

	}

	uf[p] += uf[q];

	uf[q] = p;

	ofs[q] = d;

	return false;

}



vector<pair<int, int> > vals[101010];



int main()

{

	scanf("%d%d", &R, &C);

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {

		scanf("%d%d%d", Ri + i, Ci + i, Ai + i);

		--Ri[i]; --Ci[i];

	}



	bool ans = true;

	for (int t = 0; t < 2; ++t) {

		int ppp = (t == 1 ? 100000 : 0);

		for (int i = 0; i < R; ++i) {

			uf[i + ppp] = -1;

			ofs[i + ppp] = 0;

		}

		for (int i = 0; i < C; ++i) vals[i].clear();

		for (int i = 0; i < N; ++i) {

			vals[Ci[i]].push_back({ Ri[i], Ai[i] });

		}

		for (int i = 0; i < C; ++i) if (vals[i].size() >= 2) {

			for (int j = 1; j < vals[i].size(); ++j) {

				if (join(vals[i][0].first + ppp, vals[i][j].first + ppp, -vals[i][j].second + vals[i][0].second)) {

	//				printf("%d %d %d\n", t, vals[i][0].first, vals[i][1].first);

					ans = false;

				}

			}

		}

		swap(R, C);

		for (int i = 0; i < N; ++i) swap(Ri[i], Ci[i]);

	}

	const int waf = 100000;

	for (int i = 0; i < 200000; ++i) {

		mn[i] = -(1LL << 60LL);

	}

	for (int i = 0; i < R; ++i) {

		auto t = root(i);

		mn[t.first] = max(mn[t.first], t.second);

	}

	for (int i = 0; i < C; ++i) {

		auto t = root(i + waf);

		mn[t.first] = max(mn[t.first], t.second);

	}

	for (int i = 0; i < N; ++i) {

		i64 mnr = mn[root(Ri[i]).first];

		i64 mnc = mn[root(Ci[i] + waf).first];

		i64 v = Ai[i] + root(Ri[i]).second + root(Ci[i] + waf).second;

//		printf("%d: %lld %lld %lld\n", i, mnr, mnc, v);

		if (v - mnr - mnc < 0) ans = false;

	}



	puts(ans ? "Yes" : "No");

	return 0;

}
