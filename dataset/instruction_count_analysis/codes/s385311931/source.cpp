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



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = 0;

	while ((ct = getcha()) >= '0') N = N * 10 + ct - '0';



	int kotae = 0;

	rep(i, N) {

		int A = 0;

		if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = ct - '0';

		else while ((ct = *ci++) >= '0') A = ct - '0';

		kotae ^= A;

	}



	if (kotae & 1) printf("NO\n");

	else printf("YES\n");





	Would you please return 0;

}