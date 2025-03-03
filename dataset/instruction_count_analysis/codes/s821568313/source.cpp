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





	int N;

	cin >> N;



	int A[100000], a[50000], b[50000];

	pair<int, int> B[100000];

	rep(i, N) {

		cin >> A[i];

		B[i] = mp(A[i], i);

	}

	sort(B, B + N);

	rep(i, N) {

		A[B[i].second] = i;

	}



	int kotae = 0;

	rep(i, N) {

		if ((i + A[i]) % 2) kotae++;

	}

	co(kotae / 2);



	Would you please return 0;

}