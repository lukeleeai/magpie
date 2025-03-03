//#pragma GCC optimize ("O3")

//#pragma GCC target ("avx2")

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





	int N;

	cin >> N;



	int A[200000];

	rep(i, N) cin >> A[i];



	map<int, int> MP;



	rep(i, N) {

		MP[i + A[i]]++;

	}



	ll kotae = 0;

	rep(i, N) {

		int tmp = i - A[i];

		kotae += MP[tmp];

	}



	co(kotae);



	Would you please return 0;

}