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

	pair<int, int> P[200000];

	rep(i, N) {

		int a, b;

		cin >> a >> b;

		P[i] = mp(b, a);

	}

	sort(P, P + N);



	ll time = 0;

	bool OK = true;

	rep(i, N) {

		time += P[i].second;

		if (time > P[i].first) OK = false;

	}



	if (OK) co("Yes");

	else co("No");



	Would you please return 0;

}