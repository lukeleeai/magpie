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

	map<int, int> MAP[100001];

	rep1(i, M) {

		int P, Y;

		cin >> P >> Y;

		MAP[P][Y] = i;

	}



	int kotae1[100001], kotae2[100001];

	rep1(i, N) {

		int kari = 1;

		for (auto itr : MAP[i]) {

			kotae1[itr.second] = i;

			kotae2[itr.second] = kari;

			kari++;

		}

	}



	rep1(i, M) {

		cout << setfill('0') << setw(6) << kotae1[i] << setw(6) << kotae2[i] << "\n";

	}



	Would you please return 0;

}