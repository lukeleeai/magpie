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

	int A[300001], B[300001], C[300001];

	rep(i, 3 * N) {

		cin >> A[i];

		B[i] = A[i];

		C[i] = A[i];

	}

	reverse(C, C + 3 * N);



	ll S1[100001] = {}, S2[100001] = {};



	map<int, int> MB, MC;

	rep(i, N) {

		MB[B[i]]++;

		MC[C[i]]++;

	}



	rep(i, N) S1[0] += B[i];



	rep1(i, N) {

		if (MB.begin()->first < B[N + i - 1]) {

			S1[i] = S1[i - 1] + B[N + i - 1] - MB.begin()->first;

			MB[MB.begin()->first]--;

			if (MB[MB.begin()->first] == 0) MB.erase(MB.begin()->first);

			MB[B[N + i - 1]]++;

		}

		else {

			S1[i] = S1[i - 1];

		}

	}



	rep(i, N) S2[0] += C[i];



	rep1(i, N) {

		if ((--MC.end())->first > C[N + i - 1]) {

			S2[i] = S2[i - 1] + C[N + i - 1] - (--MC.end())->first;

			MC[(--MC.end())->first]--;

			if (MC[(--MC.end())->first] == 0) MC.erase((--MC.end())->first);

			MC[C[N + i - 1]]++;

		}

		else {

			S2[i] = S2[i - 1];

		}

	}



	ll S[100001];

	rep(i, N + 1) {

		S[i] = S1[i] - S2[N - i];

	}



	co(*max_element(S, S + N + 1));



	Would you please return 0;

}