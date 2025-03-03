#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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



//いやーコンテスト中は絶対無理

int hist[300002], cnt[300001];

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

const int dm = 1 << 21;

char dn[dm], * di = dn;

inline void putint(int X) {

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	rep(i, N) hist[getint()]++;

	rep1(i, N) cnt[hist[i]]++;



	int ruiseki = N;

	int mae = 1;

	int kei = 1;

	int ijou = 0;

	for (int i = N; i >= 1; i--) {

		ijou += cnt[i];

		ruiseki -= cnt[i] * i;

		while ((kei - ijou) * i <= ruiseki) kei++;



		for (int j = mae; j < kei; j++) putint(i);

		mae = kei;

	}

	for (int j = mae; j <= N; j++) {

		*di++ = '0';

		*di++ = '\n';

	}

	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}