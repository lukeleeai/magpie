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

	

	ll N, A, B;

	cin >> N >> A >> B;



	ll X[100001];

	rep(i, N) cin >> X[i];



	ll kotae = 0;

	rep(i, N - 1) {

		kotae += min((X[i + 1] - X[i]) * A, B);

	}

	co(kotae);



	Would you please return 0;

}