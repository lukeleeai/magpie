#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please





int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N;

	scanf("%d", &N);

	char S[100000], T[4][100000];

	scanf("%s", S);



	int A[4];

	rep(i, 4) A[i] = i;



	rep(i, N) {

		T[A[0]][i] = 'S';

		T[A[1]][i] = 'W';

		T[A[2]][i] = 'S';

		T[A[3]][i] = 'W';

		if (S[i] == 'o') {

			swap(A[1], A[2]);

			swap(A[2], A[3]);

		}

		else {

			swap(A[1], A[2]);

			swap(A[0], A[1]);

		}

	}

	rep(i, 4) if (A[i] == i) {

		fwrite(T[i], 1, N, stdout);

		return 0;

	}



	printf("-1");



	Would you please return 0;

}