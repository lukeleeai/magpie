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



pair<int, int> E[100001];

int H[100001];

int memo[100001];

int sagasu(int A) {

	if (memo[A]) return memo[A];

	ce(A);

	vector<int> kari;

	for (int i = H[A]; i; i = E[i].second) kari.pb(sagasu(E[i].first));

	sort(kari.begin(), kari.end(), greater<int>());

	int ret = 1;

	rep(i, kari.size()) ret = max(ret, i + kari[i] + 1);

	return memo[A] = ret;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N = getint();



	for (int i = 2; i <= N; i++) {

		int a = getint();

		E[i] = mp(i, H[a]);

		H[a] = i;

	}



	co(sagasu(1) - 1);



	Would you please return 0;

}