//嘘っぽいのに通ってたやつでいこう



#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

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



char cn[100000], *ci = cn, c;

const char* owa = cn + 100000;

inline char getcha() {

	if (ci == owa) {

		fread(cn, 1, 100000, stdin);

		ci = cn;

	}

	return *ci++;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(cn, 1, 100000, stdin);

	int N = 0;

	while ((c = getcha()) >= '0') N = N * 10 + c - '0';

	int sL[1001] = {}, sR[1001] = {};

	pair<int, int> RR[500], LL[500];

	int rr = 0, ll = 0;

	int tot = 0;

	rep(i, N) {

		int l = 0, r = 0;

		while ((c = getcha()) >= '(') {

			if (c == '(') r++;

			else {

				if (r > 0) r--;

				else l++;

			}

		}

		tot += r - l;

		if (l < r) {

			if (l <= 1000) sR[l] += r;

			else RR[rr++] = { l,r };

		}

		else {

			if (r <= 1000) sL[r] += l;

			else LL[ll++] = { r,l };

		}

	}



	if (tot != 0) {

		printf("No");

		return 0;

	}



	sort(RR, RR + rr);

	sort(LL, LL + ll);



	int OK = 1;

	int k = 0;

	rep(i, 1001) {

		if (sR[i]) {

			if (k < i) OK = 0;

			k += sR[i];

		}

	}

	rep(i, rr) {

		if (k < RR[i].first) OK = 0;

		k += RR[i].second - RR[i].first;

	}

	k = 0;

	rep(i, 1001) {

		if (sL[i]) {

			if (k < i) OK = 0;

			k += sL[i];

		}

	}

	rep(i, ll) {

		if (k < LL[i].first) {

			OK = 0;

		}

		k += LL[i].second - LL[i].first;

	}



	if (OK) printf("Yes");

	else printf("No");



	Would you please return 0;

}