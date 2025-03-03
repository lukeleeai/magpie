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



int P[200002], saishou[200002], saidai[200002];



int Find(int A) {

	if (P[A] < 0) return A;

	return P[A] = Find(P[A]);

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int A[200001];

	rep1(i, N) A[getint()] = i;

	

	rep(i, N + 2) P[i] = -1;



	ll kotae = 0;

	for (int i = N; i > 0; i--) {

		int a = A[i];

		int b = Find(a - 1);

		int c = Find(a + 1);

		int l = saishou[b];

		if (!l) l = a;

		int r = saidai[c];

		if (!r) r = a;

		kotae += (ll)(a - l + 1) * (r - a + 1) * i;

		if (saishou[b] && saidai[c]) {

			saidai[b] = saidai[c];

			P[c] = b;

		}

		else if (saishou[b]) {

			saidai[b] = a;

			P[a] = b;

		}

		else if (saidai[c]) {

			saishou[c] = a;

			P[a] = c;

		}

		else {

			saishou[a] = a;

			saidai[a] = a;

		}

	}



	printf("%lld", kotae);



	Would you please return 0;

}