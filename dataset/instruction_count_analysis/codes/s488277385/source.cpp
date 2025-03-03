#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	int N;

	cin >> N;



	vector<pair<int, ll>> eda[100001];

	rep(i, N - 1) {

		int a, b, c;

		cin >> a >> b >> c;

		eda[a].push_back(make_pair(b, c));

		eda[b].push_back(make_pair(a, c));

	}



	ll kyori[100001] = {};



	int Q, K;

	cin >> Q >> K;



	vector<pair<int, ll>> que;

	que.push_back(make_pair(K, 0));



	while (que.size()) {

		vector<pair<int, ll>> que2;

		for (auto itr : que) {

			if (kyori[itr.first] == 0) {

				kyori[itr.first] = itr.second;

				for (auto itr2 : eda[itr.first]) {

					que2.push_back(make_pair(itr2.first, itr.second + itr2.second));

				}

			}

		}

		que = que2;

	}



	rep(i, Q) {

		int X, Y;

		cin >> X >> Y;

		co(kyori[X] + kyori[Y]);

	}



	Would you please return 0;

}