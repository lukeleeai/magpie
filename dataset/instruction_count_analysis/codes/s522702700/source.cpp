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



int P[100001];

int Find(int A) {

	if (P[A] < 0) return A;

	return P[A] = Find(P[A]);

}



bool Unite(int A, int B) {

	int a = Find(A);

	int b = Find(B);

	if (a == b) return false;

	if (P[a] > P[b]) swap(a, b);

	P[a] += P[b];

	P[b] = a;

	return true;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N = getint(), M = getint();

	int ip[100001];

	rep1(i, N) ip[getint()] = i;



	rep1(i, N) P[i] = -1;

	rep(i, M) Unite(getint(), getint());



	int kotae = 0;

	rep1(i, N) kotae += Find(i) == Find(ip[i]);



	co(kotae);



	Would you please return 0;

}