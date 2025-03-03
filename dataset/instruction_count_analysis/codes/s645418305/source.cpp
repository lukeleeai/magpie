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





	int N, T;

	cin >> N >> T;

	int t[200000];

	rep(i, N) cin >> t[i];



	ll kotae = T;

	rep(i, N - 1) {

		kotae += min(T, t[i + 1] - t[i]);

	}

	co(kotae);



	Would you please return 0;

}