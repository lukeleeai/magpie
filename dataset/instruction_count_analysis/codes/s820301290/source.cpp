//#pragma GCC optimize ("O3")

//#pragma GCC target ("avx")

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

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	string S;

	cin >> S;



	int A[2020] = {};

	A[0] = 1;



	ll kotae = 0;

	int tmp = 0;

	int are = 1;

	rep(i, S.size()) {

		int j = S.size() - i - 1;

		tmp += (S[j] - '0') * are;

		tmp %= 2019;

		are *= 10;

		are %= 2019;

		kotae += A[tmp]++;

	}

	co(kotae);



	Would you please return 0;

}