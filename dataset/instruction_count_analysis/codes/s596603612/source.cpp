#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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



int A[500000];

int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	string S, S2;

	S = ">";

	cin >> S2;

	S += S2;

	int N = S.size();

	S += "<";



	rep(i, N) {

		if (S[i] == '<') A[i] = A[i - 1] + 1;

	}



	for (int i = N - 1; i >= 0; i--) {

		if (S[i + 1] == '>') A[i] = max(A[i], A[i + 1] + 1);

	}



	ll kotae = 0;

	rep(i, N) {

		kotae += A[i];

	}

	co(kotae);



	Would you please return 0;

}