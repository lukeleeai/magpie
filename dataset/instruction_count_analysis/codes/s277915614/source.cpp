#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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



//絶対無理そう



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int A = getint(), B = getint(), M = getint();



	int a[100001], b[100001];

	int ma = 100000, mb = 100000;

	rep1(i, A) {

		a[i] = getint();

		chmin(ma, a[i]);

	}

	rep1(i, B) {

		b[i] = getint();

		chmin(mb, b[i]);

	}



	int kotae = ma + mb;



	rep(i, M) {

		int x = getint(), y = getint(), c = getint();

		chmin(kotae, a[x] + b[y] - c);

	}



	printf("%d", kotae);



	Would you please return 0;

}