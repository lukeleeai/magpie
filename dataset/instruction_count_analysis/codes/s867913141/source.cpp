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





	int N, Q;

	cin >> N >> Q;

	string S;

	cin >> S;

	

	bool AC[100000] = {};

	rep(i, N - 1) {

		if (S[i] == 'A' && S[i + 1] == 'C') AC[i] = true;

	}

	int ACN[100000];

	ACN[0] = 0;

	rep(i, N - 1) {

		ACN[i + 1] = ACN[i] + AC[i];

	}



	rep(i, Q) {

		int l, r;

		cin >> l >> r;

		co(ACN[r - 1] - ACN[l - 1]);

	}







	Would you please return 0;

}