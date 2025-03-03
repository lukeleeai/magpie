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



int P[100001];

int C[100001];



int Find(int A) {

	if (P[A] == A) return A;

	else {

		P[A] = Find(P[A]);

		return P[A];

	}

}



ll Union(int A, int B) {

	int a = Find(A);

	int b = Find(B);

	if (a != b) {

		P[b] = a;

		C[a] += C[b];

	}

	return C[a];

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, M;

	cin >> N >> M;



	pair<int, int> E[100001];

	rep1(i, M) {

		int a, b;

		cin >> a >> b;

		E[i] = mp(a, b);

	}



	ll sum = 1ll * N * (N - 1) / 2;

	ll kotae[100001];

	kotae[M] = sum;



	rep1(i, N) {

		C[i] = 1;

		P[i] = i;

	}



	for (int i = M; i > 1; i--) {

		int A = E[i].first;

		int B = E[i].second;

		int ca = C[Find(A)];

		int cb = C[Find(B)];

		int cf = Union(A, B);

		if (cf != ca) {

			sum += 1ll * ca * (ca - 1) / 2;

			sum += 1ll * cb * (cb - 1) / 2;

			sum -= 1ll * cf * (cf - 1) / 2;

		}

		kotae[i - 1] = sum;

	}



	rep1(i, M) co(kotae[i]);

	

	Would you please return 0;

}