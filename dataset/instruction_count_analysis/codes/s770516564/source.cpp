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



	

	int N, M;

	cin >> N >> M;

	pair<int, int> A[100000];

	rep(i, N) cin >> A[i].first >> A[i].second;

	sort(A, A + N);



	int ima = 0;

	ll kotae = 0;

	rep(i, N) {

		if (ima < M) {

			int kari = min(M - ima, A[i].second);

			ima += kari;

			kotae += (ll)kari * A[i].first;

		}

	}



	co(kotae);



	Would you please return 0;

}