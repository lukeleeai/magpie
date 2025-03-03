#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define Would

#define you

#define please





//たまらず解説をみてお勉強中

int P[100001];



int Find(int A) {

	if (P[A] == A) return A;

	else {

		P[A] = Find(P[A]);

		return P[A];

	}

}



void Union(int A, int B) {

	int a = Find(A);

	int b = Find(B);

	P[b] = a;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;



	pair<int, int> X[100001], Y[100001];

	rep1(i, N) {

		int x, y;

		cin >> x >> y;

		X[i] = make_pair(x, i);

		Y[i] = make_pair(y, i);

	}

	sort(X + 1, X + N + 1);

	sort(Y + 1, Y + N + 1);



	vector<pair<int, pair<int, int>>> eda;



	rep1(i, N - 1) {

		eda.push_back(make_pair(abs(X[i + 1].first - X[i].first), make_pair(X[i].second, X[i + 1].second)));

		eda.push_back(make_pair(abs(Y[i + 1].first - Y[i].first), make_pair(Y[i].second, Y[i + 1].second)));

	}



	sort(eda.begin(), eda.end());



	rep1(i, N) P[i] = i;



	ll kotae = 0;

	for (auto itr : eda) {

		if (Find(itr.second.first) != Find(itr.second.second)) {

			Union(itr.second.first, itr.second.second);

			kotae += itr.first;

		}

	}



	co(kotae);



	Would you please return 0;

}