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



int P[100001];

int K[100001];



int Find(int A) {

	if (P[A] < 0) return A;

	return P[A] = Find(P[A]);

}



bool Unite(int A, int B) {

	int a = Find(A);

	int b = Find(B);

	if (a == b) return false;

	if (P[a] > P[b]) swap(a, b);

	P[a] += P[b];

	P[b] = a;

	K[a] += K[b];

	return true;

}



int Size(int A) {

	return -P[Find(A)];

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	

	int N;

	cin >> N;



	vector<int> XY[100001];

	rep(i, N) {

		int x, y;

		cin >> x >> y;



		XY[x].pb(y);

	}



	rep1(i, 100000) P[i] = -1;



	rep1(i, 100000) {

		if (XY[i].size()) {

			for (int j = 0; j < (int)XY[i].size() - 1; j++) {

				Unite(XY[i][j], XY[i][j + 1]);

			}

			K[Find(XY[i][0])]++;

		}

	}



	ll kotae = 0;

	rep1(i, 100000) {

		if (Find(i) == i) {

			kotae += 1ll * K[i] * Size(i);

		}

	}

	co(kotae - N);



	Would you please return 0;

}