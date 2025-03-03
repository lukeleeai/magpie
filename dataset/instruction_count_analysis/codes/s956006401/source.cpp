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

vector<pair<int, int> > vals[101010];



vector<pair<int, i64> > row[101010], col[101010];

bool rvis[101010], cvis[101010];

i64 rval[101010], cval[101010];

i64 rmin, cmin;



void visit_row(int p, i64 d)

{

//	printf("ro %d\n", p);

	if (rvis[p]) {

		if (rval[p] != d) {

			puts("No");

			exit(0);

		}

		return;

	}

	rvis[p] = true;

	rval[p] = d;

	rmin = min(rmin, d);

	for (auto e : row[p]) {

		visit_row(e.first, d + e.second);

	}

}

void visit_col(int p, i64 d)

{

//	printf("co %d\n", p);

	if (cvis[p]) {

		if (cval[p] != d) {

			puts("No");

			exit(0);

		}

		return;

	}

	cvis[p] = true;

	cval[p] = d;

	cmin = min(cmin, d);

	for (auto e : col[p]) {

		visit_col(e.first, d + e.second);

	}

}



int main()

{

	scanf("%d%d", &R, &C);

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {

		scanf("%d%d%d", Ri + i, Ci + i, Ai + i);

		--Ri[i]; --Ci[i];

	}



	for (int i = 0; i < C; ++i) vals[i].clear();

	for (int i = 0; i < N; ++i) {

		vals[Ci[i]].push_back({ Ri[i], Ai[i] });

	}

	for (int i = 0; i < C; ++i) if (vals[i].size() >= 2) {

		for (int j = 1; j < vals[i].size(); ++j) {

			row[vals[i][0].first].push_back({ vals[i][j].first, vals[i][j].second - vals[i][0].second });

			row[vals[i][j].first].push_back({ vals[i][0].first, -vals[i][j].second + vals[i][0].second });

		}

	}

	for (int i = 0; i < R; ++i) vals[i].clear();

	for (int i = 0; i < N; ++i) {

		vals[Ri[i]].push_back({ Ci[i], Ai[i] });

	}

	for (int i = 0; i < R; ++i) if (vals[i].size() >= 2) {

		for (int j = 1; j < vals[i].size(); ++j) {

			col[vals[i][0].first].push_back({ vals[i][j].first, vals[i][j].second - vals[i][0].second });

			col[vals[i][j].first].push_back({ vals[i][0].first, -vals[i][j].second + vals[i][0].second });

		}

	}

	for (int i = 0; i < N; ++i) if (!rvis[Ri[i]]) {

		if (cvis[Ci[i]]) {

			int t = 5;

			t /= t - 5;

			return 0;

		}

		rmin = cmin = 0;

		visit_row(Ri[i], 0);

		visit_col(Ci[i], 0);

	//	printf("%d %lld %lld\n", i, rmin, cmin);

		if (Ai[i] + rmin + cmin < 0) {

			puts("No");

			return 0;

		}

	}



	puts("Yes");

	return 0;

}
