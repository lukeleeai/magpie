#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

#include<vector>

#include<algorithm>

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

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please







int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N;

	scanf("%d ", &N);

	int sL[101] = {}, sR[101] = {};

	vector<pair<int, int>> RR, LL;

	int tot = 0;

	rep(i, N) {

		char c;

		int l = 0, r = 0;

		while((c = getchar_unlocked()) >= '(') {

			if (c == '(') r++;

			else {

				if (r > 0) r--;

				else l++;

			}

		}

		tot += r - l;

		if (l < r) {

			if (l <= 100) sR[l] += r;

			else RR.pb({ l,r });

		}

		else {

			if (r <= 100) sL[r] += l;

			else LL.pb({ r,l });

		}

	}



	if (tot != 0) {

		printf("No");

		return 0;

	}



	sort(RR.begin(), RR.end());

	sort(LL.begin(), LL.end());



	int OK = 1;

	int k = 0;

	rep(i, 101) {

		if (sR[i]) {

			if (k < i) OK = 0;

			k += sR[i];

		}

	}

	rep(i, RR.size()) {

		if (k < RR[i].first) OK = 0;

		k += RR[i].second - RR[i].first;

	}

	k = 0;

	rep(i, 101) {

		if (sL[i]) {

			if (k < i) OK = 0;

			k += sL[i];

		}

	}

	rep(i, LL.size()) {

		if (k < LL[i].first) {

			OK = 0;

		}

		k += LL[i].second - LL[i].first;

	}



	if (OK) printf("Yes");

	else printf("No");



	Would you please return 0;

}