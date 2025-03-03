#pragma GCC optimize ("Ofast")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

#include<cstring>



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



char cn[300100], * ci = cn, ct;

int N, A, B, C;



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	fread(cn, 1, 300100, stdin);

	while ((ct = *ci++) >= '0') N = N * 10 + ct - '0';

	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	while ((ct = *ci++) >= '0') B = B * 10 + ct - '0';

	while ((ct = *ci++) >= '0') C = C * 10 + ct - '0';



	int kei = A + B + C;

	



	int OK = 1;

	char *di = cn;



	char* S = ci;



	for (int i = 0; i < 3 * N; i += 3) {

		if (S[i] == 'B') {

			if (C == 0 && B == 0) OK = 0;

			if (C == 1 && B == 1) {

				if (i == 3 * N - 3 || S[i + 4] == 'C') {

					*di++ = 'C';

					*di++ = '\n';

					C++;

					B--;

				}

				else {

					*di++ = 'B';

					*di++ = '\n';

					B++;

					C--;

				}

			}

			else if (C <= B) {

				*di++ = 'C';

				*di++ = '\n';

				C++;

				B--;

			}

			else {

				*di++ = 'B';

				*di++ = '\n';

				B++;

				C--;

			}

		}

		else if (S[i + 1] == 'B') {

			if (A == 0 && B == 0) OK = 0;

			if (A == 1 && B == 1) {

				if (i == 3 * N - 3 || S[i + 3] == 'A') {

					*di++ = 'A';

					*di++ = '\n';

					A++;

					B--;

				}

				else {

					*di++ = 'B';

					*di++ = '\n';

					B++;

					A--;

				}

			}

			else if (A <= B) {

				*di++ = 'A';

				*di++ = '\n';

				A++;

				B--;

			}

			else {

				*di++ = 'B';

				*di++ = '\n';

				B++;

				A--;

			}

		}

		else {

			if (A == 0 && C == 0) OK = 0;

			if (A == 1 && C == 1) {

				if (i == 3 * N - 3 || S[i + 4] == 'C') {

					*di++ = 'C';

					*di++ = '\n';

					C++;

					A--;

				}

				else {

					*di++ = 'A';

					*di++ = '\n';

					A++;

					C--;

				}

			}

			else if (A <= C) {

				*di++ = 'A';

				*di++ = '\n';

				A++;

				C--;

			}

			else {

				*di++ = 'C';

				*di++ = '\n';

				C++;

				A--;

			}

		}

	}

	if (OK) {

		printf("Yes\n");

		fwrite(cn, 1, di - cn, stdout);

	}

	else printf("No\n");



	Would you please return 0;

}