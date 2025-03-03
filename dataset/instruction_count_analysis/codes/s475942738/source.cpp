#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

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

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	int A[100100];

	rep(i, N + 1) cin >> A[i];





	ll nokori = 1;

	ll B[100100];



	rep(i, N + 1) {

		B[i] = nokori;



		nokori = (nokori - A[i]) * 2;



		if (nokori > 1e15) nokori = 1e15;

	}

	

	int OK = 1;

	ll kotae = 0;

	ll kari = 0;

	for (int i = N; i >= 0; i--) {

		if (B[i] < A[i]) OK = 0;

		

		kari += A[i];

		kotae += min(kari, B[i]);

	}



	if (OK) co(kotae);

	else co(-1);



	Would you please return 0;

}