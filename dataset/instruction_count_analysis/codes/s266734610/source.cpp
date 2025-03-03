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

#define Would

#define you

#define please



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



const int K = 19;

const int KM = 1 << (K - 1);

pair<int, int> dat[1 << K];



pair<int, int> check(int L, int R, int A, int l, int r) {

	if (L <= l && r <= R) return dat[A];

	if (r <= L || R <= l) return mp(1e9, 1e9);

	return min(check(L, R, A * 2, l, (l + r) / 2), check(L, R, A * 2 + 1, (l + r) / 2, r));

}



pair<int, int> query(int L, int R) {

	return check(L, R, 1, 0, KM);

}



ll kotae;

void keisan(int L, int R) {

	auto p = query(L, R);

	ll k2 = (ll)(R - L + 1) * (R - L) - (ll)(R - p.second - 1) * (R - p.second) - (ll)(p.second - L + 1) * (p.second - L);

	kotae += p.first * k2 / 2;

	if (L < p.second) keisan(L, p.second);

	if (R > p.second + 1) keisan(p.second + 1, R);

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	rep(i, N) {

		int a = getint();

		dat[i + KM] = mp(a, i);

	}



	for (int i = KM - 1; i >= 1; i--) {

		dat[i] = min(dat[i * 2], dat[i * 2 + 1]);

	}



	keisan(0, N);



	printf("%lld", kotae);



	Would you please return 0;

}