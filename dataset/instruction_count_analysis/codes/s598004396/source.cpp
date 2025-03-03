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

	pair<int, int> X[501];

	int kotae[250001] = {};

	rep1(i, N) {

		cin >> X[i].first;

		X[i].second = i;

		kotae[X[i].first] = i;

	}



	sort(X + 1, X + N + 1);



	queue<pair<int, int>> que;

	rep1(i, N) {

		rep(j, X[i].second - 1) que.push(mp(X[i].second, X[i].first));

	}



	int OK = 1;

	rep1(i, N* N) {

		if (kotae[i] == 0) {

			if (que.size() == 0) {

				OK = 0;

				break;

			}

			auto q = que.front();

			que.pop();

			if (q.second < i) {

				OK = 0;

				break;

			}

			kotae[i] = q.first;

		}

		else {

			rep(j, N - kotae[i]) que.push(mp(kotae[i], 300000));

		}

	}



	if (OK) {

		co("Yes");

		rep1(i, N * N) co(kotae[i]);

	}

	else co("No");



	Would you please return 0;

}