#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<vector>

#include<functional>

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

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}

pair<int, int> E[100001];

int H[100001];

int n[100001], kari[100001];

int sagasu(int A) {

	if (n[A] == n[A - 1]) return 0;

	int k = n[A - 1];

	for (int i = H[A]; i; i = E[i].second) {

		kari[k++] = sagasu(E[i].first);

	}

	sort(kari + n[A - 1], kari + n[A], greater<int>());

	int ret = 0;

	for (int i = 0; i < n[A] - n[A - 1]; i++) ret = max(ret, kari[n[A - 1] + i] + i);

	return ret + 1;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();



	for (int i = 2; i <= N; i++) {

		int a = getint();

		n[a]++;

		E[i] = mp(i, H[a]);

		H[a] = i;

	}

	rep1(i, N) n[i] = n[i - 1] + n[i];



	printf("%d\n", sagasu(1));



	Would you please return 0;

}