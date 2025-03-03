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



char dn[1400000], * di = dn;

int keta1 = 1, keta2;

char C1[10] = { '1', '0', '0', '0', '0', '0' };

char C2[10] = { '0', '0', '0', '0', '0', '0' };



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, M;

	scanf("%d %d", &N, &M);



	if (N % 2) {

		int n = N - 1;

		keta2 = 0;

		while (n) {

			*(C2 + keta2) = '0' + n % 10;

			n /= 10;

			keta2++;

		}



		rep1(i, M) {

			for (int i = keta1 - 1; i >= 0; i--)* di++ = (*(C1 + i));

			*di++ = ' ';

			for (int i = keta2 - 1; i >= 0; i--)* di++ = (*(C2 + i));

			*di++ = '\n';



			C1[0]++;

			int tmp = 0;

			while (C1[tmp] > '9') {

				C1[tmp++] -= 10;

				C1[tmp]++;

				if (keta1 <= tmp) keta1 = tmp + 1;

			}

			C2[0]--;

			tmp = 0;

			while (C2[tmp] < '0') {

				C2[tmp++] += 10;

				C2[tmp]--;

				if (C2[keta2 - 1] == '0') keta2--;

			}

		}

	}

	else {

		int n = N;

		keta2 = 0;

		while (n) {

			*(C2 + keta2) = '0' + n % 10;

			n /= 10;

			keta2++;

		}

		rep1(i, (M + 1) / 2) {

			for (int i = keta1 - 1; i >= 0; i--)* di++ = (*(C1 + i));

			*di++ = ' ';

			for (int i = keta2 - 1; i >= 0; i--)* di++ = (*(C2 + i));

			*di++ = '\n';



			C1[0]++;

			int tmp = 0;

			while (C1[tmp] > '9') {

				C1[tmp++] -= 10;

				C1[tmp]++;

				if (keta1 <= tmp) keta1 = tmp + 1;

			}

			C2[0]--;

			tmp = 0;

			while (C2[tmp] < '0') {

				C2[tmp++] += 10;

				C2[tmp]--;

				if (C2[keta2 - 1] == '0') keta2--;

			}

		}

		C2[0]--;

		int tmp = 0;

		while (C2[tmp] < '0') {

			C2[tmp++] += 10;

			C2[tmp]--;

			if (C2[keta2 - 1] == '0') keta2--;

		}

		for (int i = (M + 1) / 2 + 1; i <= M; i++) {

			for (int i = keta1 - 1; i >= 0; i--)* di++ = (*(C1 + i));

			*di++ = ' ';

			for (int i = keta2 - 1; i >= 0; i--)* di++ = (*(C2 + i));

			*di++ = '\n';



			C1[0]++;

			int tmp = 0;

			while (C1[tmp] > '9') {

				C1[tmp++] -= 10;

				C1[tmp]++;

				if (keta1 <= tmp) keta1 = tmp + 1;

			}

			C2[0]--;

			tmp = 0;

			while (C2[tmp] < '0') {

				C2[tmp++] += 10;

				C2[tmp]--;

				if (C2[keta2 - 1] == '0') keta2--;

			}

		}

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}