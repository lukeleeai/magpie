#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<algorithm>

#include<deque>



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



const int cm = 80100;

char cn[cm], * ci = cn, ct;

inline int getint() {

	int A = 0;

	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}

inline int getint2() {

	int pn = 1;

	if ((ct = *ci++) == '-') { pn = -1; ct = *ci++; }

	int A = ct - '0';

	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return pn * A;

}



ll dat[10200];

bool yatta[5000];

int P[5000], C[5000];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(cn, 1, cm, stdin);



	int N = getint(), K = getint();

	rep(i, N) P[i] = getint() - 1;

	rep(i, N) C[i] = getint2();



	ll kotae = -2e18;

	rep(i, N) if (!yatta[i]) {

		int L = 0;

		auto kari = dat;

		kari[0] = 0;

		int j = i;

		while (!yatta[j]) {

			yatta[j] = 1;

			kari[L + 1] = kari[L] + C[j];

			L++;

			j = P[j];

		}

		ll hue = kari[L];

		for (int j = L + 1; j <= L + L; j++) {

			kari[j] = kari[j - L] + hue;

		}

		ll amari = K % L;

		ll wari = K / L;

		if (hue > 0) {

			if (amari > 0) {

				deque<int> dq;

				rep1(i, L + amari - 1) {

					while (dq.size() && kari[dq.back()] <= kari[i]) dq.pop_back();

					dq.push_back(i);

					if (i < amari) continue;

					while (dq.size() && dq.front() <= i - amari) dq.pop_front();

					chmax(kotae, hue * wari + kari[dq.front()] - kari[i - amari]);

				}

			}			

			if (wari > 0) {

				deque<int> dq;

				rep1(i, L + L - amari - 1) {

					while (dq.size() && kari[dq.back()] <= kari[i + amari]) dq.pop_back();

					dq.push_back(i + amari);

					if (i < L - amari) continue;

					while (dq.size() && dq.front() <= i + amari - L) dq.pop_front();

					chmax(kotae, hue * (wari - 1) + kari[dq.front()] - kari[i + amari - L]);

				}

			}

		}

		else {

			deque<int> dq;

			int are = min(K, L);

			rep1(i, L + are - 1) {

				while (dq.size() && kari[dq.back()] <= kari[i]) dq.pop_back();

				dq.push_back(i);

				if (i < are) continue;

				while (dq.size() && dq.front() <= i - are) dq.pop_front();

				chmax(kotae, kari[dq.front()] - kari[i - are]);

			}

		}

	}



	printf("%lld\n", kotae);





	Would you please return 0;

}