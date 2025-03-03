#include"stdc++.h"

//#include<cstdio>



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





	string S;

	cin >> S;



	int kotae[100000] = {};

	int N = S.size();

	

	int k = 0;

	rep(i, N) {

		if (S[i] == 'R') {

			k++;

		}

		else {

			kotae[i - 1] += (k + 1) / 2;

			kotae[i] += k / 2;

			k = 0;

		}

	}

	k = 0;

	for (int i = N - 1; i >= 0; i--) {

		if (S[i] == 'L') {

			k++;

		}

		else {

			kotae[i + 1] += (k + 1) / 2;

			kotae[i] += k / 2;

			k = 0;

		}

	}



	rep(i, N) cosp(kotae[i]);



	Would you please return 0;

}