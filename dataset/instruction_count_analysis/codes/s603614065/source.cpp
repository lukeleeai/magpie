#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<numeric>

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



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

int abc[300000];

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





	int X = 0, Y = 0, A = 0, B = 0, C = 0;

	while ((ct = getchar_unlocked()) >= '0') X = X * 10 + ct - '0';

	while ((ct = getchar_unlocked()) >= '0') Y = Y * 10 + ct - '0';

	while ((ct = getchar_unlocked()) >= '0') A = A * 10 + ct - '0';

	while ((ct = getchar_unlocked()) >= '0') B = B * 10 + ct - '0';

	while ((ct = getchar_unlocked()) >= '0') C = C * 10 + ct - '0';



	auto a = abc;

	auto b = abc + A;

	auto c = abc + A + B;



	int k = 0;

	int M = A + B + C;

	while (k < M) {

		int yoyuu = (cm - (ci - cn)) / 11;

		chmin(yoyuu, M - k);

		if (yoyuu > 10) {

			rep(i, yoyuu) {

				int aa = 0;

				while ((ct = *ci++) >= '0') aa = aa * 10 + ct - '0';

				abc[k++] = aa;

			}

		}

		else {

			auto tmp = ci;

			while (k < M) {

				abc[k++] = getint();

				if (tmp - ci < 0) break;

				tmp = ci;

			}

		}

	}



	nth_element(a, b - X, b);

	nth_element(b, c - Y, c);

	if (X + Y > B) memcpy(b, b - X, (B - Y) * sizeof(int));

	else memcpy(c - X - Y, b - X, X * sizeof(int));

	nth_element(c - X - Y, c + C - X - Y, c + C);



	ll kotae = accumulate(c + C - X - Y, c + C, 0ll);

	//for (auto kari = c + C - X - Y; kari < c + C; kari++) kotae += *kari;

	printf("%lld", kotae);



	Would you please return 0;

}