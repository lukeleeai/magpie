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





	int N, K;

	cin >> N >> K;



	int a[100001] = {};

	ll s[100002], sa[100002];

	s[0] = 0;

	sa[0] = 0;

	rep1(i, N) {

		cin >> a[i];

		s[i] = s[i - 1] + a[i];

		sa[i] = sa[i - 1] + max(a[i], 0);

	}



	ll kotae = 0;

	for (int i = 1; i <= N - K + 1; i++) {

		ll kari = max(s[i + K - 1] - s[i - 1], 0ll) + sa[i - 1] + sa[N] - sa[i + K - 1];

		kotae = max(kotae, kari);

	}

	co(kotae);



	Would you please return 0;

}