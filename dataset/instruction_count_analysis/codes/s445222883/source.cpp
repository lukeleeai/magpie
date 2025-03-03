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



	int p[20000];

	rep(i, N) cin >> p[i];



	int a[20001], b[20001];

	rep1(i, N) {

		a[i] = i * 30000;

		b[i] = (N - i + 1) * 30000;

	}

	rep(i, N) {

		a[p[i]] += i;

	}



	rep1(i, N) cout << a[i] << (i == N ? '\n' : ' ');

	rep1(i, N) cout << b[i] << (i == N ? '\n' : ' ');



	Would you please return 0;

}