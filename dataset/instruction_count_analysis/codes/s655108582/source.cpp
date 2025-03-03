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

#define Would

#define you

#define please



const int dm = 1 << 19;

char dn[dm], * di = dn;

inline void putint(int X) {

	if (X == 0) {

		*di++ = '0';

		*di++ = ' ';

		return;

	}

	int keta = 0;

	char C[20];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = ' ';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	char S[100001];

	int N = fread_unlocked(S, 1, 100001, stdin);

	if (S[N - 1] == '\n') N--;

	int kotae[100000] = {};

	

	int k = 0;

	rep(i, N) {

		if (S[i] == 'R') {

			k++;

		}

		else {

			kotae[i - 1] += (k + 1) / 2;

			kotae[i] += k / 2;

			k = 0;

		}

	}

	k = 0;

	for (int i = N - 1; i >= 0; i--) {

		if (S[i] == 'L') {

			k++;

		}

		else {

			kotae[i + 1] += (k + 1) / 2;

			kotae[i] += k / 2;

			k = 0;

		}

	}



	rep(i, N) putint(kotae[i]);

	fwrite_unlocked(dn, di - dn - 1, 1, stdout);



	Would you please return 0;

}