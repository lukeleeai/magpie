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



//木はdfsのほうが書くのはやいかなぁ

vector<int> eda[100001];

int kyoriF[100001];

int kyoriS[100001];



void sagasuF(int A, int B) {

	if (!kyoriF[A]) {

		kyoriF[A] = B;

		for (auto itr : eda[A]) sagasuF(itr, B + 1);

	}

}

void sagasuS(int A, int B) {

	if (!kyoriS[A]) {

		kyoriS[A] = B;

		for (auto itr : eda[A]) sagasuS(itr, B + 1);

	}

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	int N;

	cin >> N;

	rep(i, N - 1) {

		int a, b;

		cin >> a >> b;

		eda[a].push_back(b);

		eda[b].push_back(a);

	}



	sagasuF(1, 1);

	sagasuS(N, 1);



	int fen = 0;

	rep1(i, N) if (kyoriF[i] <= kyoriS[i]) fen++;



	if (fen > N - fen) co("Fennec");

	else co("Snuke");



	Would you please return 0;

}