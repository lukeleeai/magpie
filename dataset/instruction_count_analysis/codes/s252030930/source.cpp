#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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





	int A, B, M;

	cin >> A >> B >> M;



	int a[100001], b[100001];

	rep1(i, A) cin >> a[i];

	rep1(i, B) cin >> b[i];



	int kotae = *min_element(a + 1, a + A + 1) + *min_element(b + 1, b + B + 1);



	rep(i, M) {

		int x, y, c;

		cin >> x >> y >> c;



		int tmp = a[x] + b[y] - c;

		chmin(kotae, tmp);

	}



	co(kotae);



	Would you please return 0;

}