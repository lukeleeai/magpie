#include "stdc++.h"

using namespace std;



const int INF = 1 << 30;



bool solve() {

	int N, M;

	cin >> N >> M;

	if (N == 0) return false;



	vector<int> S(M);

	vector<vector<int>> C(M);

	for(int i = 0; i < M; ++i) {

		cin >> S[i];

		int K;

		cin >> K;

		C[i].resize(K);

		for(auto& c : C[i]) {

			cin >> c;

		}

	}



	vector<int> mi(N + 1, 0), ma(N + 1, 0);

	for(int i = 0; i < M; ++i) {

		for(auto c : C[i]) {

			ma[c] += S[i];

		}

		if (C[i].size() == 1) {

			mi[C[i][0]] += S[i];

		}

	}



	vector<int> mafore(N + 2);

	mafore[0] = 0;

	for(int i = 1; i <= N; ++i) {

		mafore[i] = max(mafore[i - 1], ma[i]);

	}



	vector<int> maback(N + 2);

	mafore[N + 1] = 0;

	for(int i = N; i >= 1; --i) {

		maback[i] = max(maback[i + 1], ma[i]);

	}



	int ans = 0;

	for(int i = 1; i <= N; ++i) {

		int score = max(mafore[i - 1], maback[i + 1]) - mi[i];

		ans = max(ans, score);

	}

	cout << ans + 1 << endl;

	return true;

}



int main(){

	while(solve()){}

	return 0;

}


