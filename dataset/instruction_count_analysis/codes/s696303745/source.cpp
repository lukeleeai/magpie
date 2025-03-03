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





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, D;

	cin >> N >> D;

	int d[500000];

	rep(i, N) cin >> d[i];

	int A[500000];

	A[0] = D;

	rep(i, N - 1) A[i + 1] = min(A[i], abs(A[i] - d[i]));

	ll B[500000];

	B[N - 1] = 0;

	rep1(i, N - 1) {

		if (B[N - i] * 2 + 1 >= d[N - i]) B[N - i - 1] = B[N - i] + d[N - i];

		else B[N - i - 1] = B[N - i];

	}

	int Q;

	cin >> Q;

	rep(i, Q) {

		int q;

		cin >> q;

		q--;

		if (A[q] <= B[q]) co("NO");

		else co("YES");

	}

	

	Would you please return 0;

}