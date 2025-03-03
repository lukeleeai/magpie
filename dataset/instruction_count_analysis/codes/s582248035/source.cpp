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



	int A[200001];

	int mae[200002] = {};

	int ato[200002] = {};

	rep1(i, N) {

		cin >> A[i];

		mae[i] = max(mae[i - 1], A[i]);

	}

	for (int i = N; i >= 1; i--) {

		ato[i] = max(ato[i + 1], A[i]);

	}



	rep1(i, N) {

		co(max(mae[i - 1], ato[i + 1]));

	}



	Would you please return 0;

}