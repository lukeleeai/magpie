#include "stdc++.h"

#define range(i, a, b) for(int i = (a); i < (b); i++)

#define rep(i, a) range(i, 0, a)

using namespace std;

int d, n;

vector <int> a, e, r;

vector <vector <int>> memo;

const int INF = 1000000000;



void rec(int c = 0, int exp = 0, int end = d) {

	if (memo[exp][end] <= c) return;

	memo[exp][end] = c;



	rep (i, n) {

		if (exp < r[i]) continue;

		rec(c + 1, min(exp + e[i], 100), max(end - a[i], 0));

	}

}



int main() {

	while (cin >> d >> n, d) {

		a = e = r = vector <int> (n);

		rep (i, n) cin >> a[i] >> e[i] >> r[i];

		memo = vector <vector <int>> (105, vector <int> (105, INF));

		rec();

		int ans = INF;

		rep (i, 101) ans = min(ans, memo[i][0]);

		cout << (ans == INF ? "NA" : to_string(ans)) << endl;

	}

	return 0;

}
