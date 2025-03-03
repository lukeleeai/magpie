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

	for (int i = keta - 1; i >= 0; i--) *di++ = (*(C + i));

	*di++ = '\n';

}

bool b[200001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	char c;

	int N = 0;

	while ((c = getchar_unlocked()) >= '0') N = N * 10 + c - '0';



	bool a[200001];

	rep1(i, N) {

		a[i] = getchar_unlocked() - '0';

		getchar_unlocked();

	}



	int kazu = 0;

	for (int i = N; i > 0; i--) {

		bool k = a[i];

		for (int j = i + i; j <= N; j += i) {

			k ^= b[j];

		}

		if (k) {

			kazu++;

			b[i] = true;

		}

	}

	if (kazu == 0) {

		*di++ = '0';

		*di++ = '\n';

	}

	else putint(kazu);

	rep1(i, N) {

		if (b[i]) putint(i);

	}

	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}