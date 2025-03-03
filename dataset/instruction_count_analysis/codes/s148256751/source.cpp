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



const int cm = 1 << 17;

char cn[cm], *ci = cn + cm, ct;

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

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N = getint(), M = getint();



	int A[100000];

	rep(i, N) *(A + i) = getint();

	sort(A, A + N);



	pair<int, int> BC[100000];

	rep(i, M) {

		(*(BC + i)).second = getint();

		(*(BC + i)).first = getint();

	}

	sort(BC, BC + M);



	int kazu = 0;

	int B[100000] = {};

	for (int i = M - 1; i >= 0; i--) {

		rep(j, BC[i].second) {

			if (kazu >= N) break;

			*(B + kazu) = BC[i].first;

			kazu++;

		}

	}



	ll kotae = 0;

	rep(i, N) kotae += max(A[i], B[i]);



	co(kotae);



	Would you please return 0;

}