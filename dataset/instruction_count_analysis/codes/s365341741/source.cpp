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





	int N, K;

	cin >> N >> K;

	int h[100000];

	rep(i, N) {

		cin >> h[i];

	}

	sort(h, h + N);



	int saishou = 1e9;

	rep(i, N - K + 1) {

		saishou = min(saishou, h[i + K - 1] - h[i]);

	}

	co(saishou);



	Would you please return 0;

}