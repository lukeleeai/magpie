#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int R, C, N;

	cin >> R >> C >> N;

	vector<pair<int, int>> P1, P2, P3, P4;

	rep(i, N) {

		int a, b, c, d;

		cin >> a >> b >> c >> d;

		if (((a == 0 || a == R) || (b == 0 || b == C)) && ((c == 0 || c == R) || (d == 0 || d == C))) {

			if (a == 0) P1.pb(mp(b, i));

			else if (b == C) P2.pb(mp(a, i));

			else if (a == R) P3.pb(mp(C - b, i));

			else P4.pb(mp(R - a, i));

			if (c == 0) P1.pb(mp(d, i));

			else if (d == C) P2.pb(mp(c, i));

			else if (c == R) P3.pb(mp(C - d, i));

			else P4.pb(mp(R - c, i));

		}

	}

	sort(P1.begin(), P1.end());

	sort(P2.begin(), P2.end());

	sort(P3.begin(), P3.end());

	sort(P4.begin(), P4.end());



	int k = 1;

	int OK = 1;

	int A[100000] = {};

	for (auto p : P1) {

		if (!A[p.second]) {

			A[p.second] = k;

			k++;

		}

		else {

			k--;

			if (A[p.second] != k) OK = 0;

		}

	}

	for (auto p : P2) {

		if (!A[p.second]) {

			A[p.second] = k;

			k++;

		}

		else {

			k--;

			if (A[p.second] != k) OK = 0;

		}

	}

	for (auto p : P3) {

		if (!A[p.second]) {

			A[p.second] = k;

			k++;

		}

		else {

			k--;

			if (A[p.second] != k) OK = 0;

		}

	}

	for (auto p : P4) {

		if (!A[p.second]) {

			A[p.second] = k;

			k++;

		}

		else {

			k--;

			if (A[p.second] != k) OK = 0;

		}

	}



	if (OK) co("YES");

	else co("NO");



	Would you please return 0;

}