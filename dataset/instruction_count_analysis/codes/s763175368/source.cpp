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



int P[200002];

int eranda[200002];



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

	eranda[a] |= eranda[b];

	P[b] = a;

	return true;

}



int Size(int A) {

	return -P[Find(A)];

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, H, W;

	cin >> N >> H >> W;



	pair<int, pair<int, int>> E[100000];

	rep(i, N) {

		int r, c, a;

		cin >> r >> c >> a;

		E[i] = mp(a, mp(r - 1, H + c - 1));

	}

	sort(E, E + N);

	reverse(E, E + N);



	rep(i, H + W) P[i] = -1;

	ll kotae = 0;

	rep(i, N) {

		int r = E[i].second.first;

		int c = E[i].second.second;

		if (Find(r) != Find(c)) {

			if (!(eranda[Find(r)] && eranda[Find(c)])) {

				Unite(r, c);

				kotae += E[i].first;

			}

		}

		else {

			if (eranda[Find(r)] == 0) {

				kotae += E[i].first;

				eranda[Find(r)] = 1;

			}

		}

	}



	co(kotae);





	Would you please return 0;

}