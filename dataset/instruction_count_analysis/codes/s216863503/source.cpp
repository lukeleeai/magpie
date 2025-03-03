// ABC101C - Minimization



#include "stdc++.h"

using namespace std;



int main() {

	int N, K;

	cin >> N >> K;

	vector<int> A(N);

	for (int i = 0; i < N; i++) {

		cin >> A.at(i);

	}



	int ans;

	ans = ((N - K) + (K - 2))/ (K - 1) + 1;



	cout << ans << endl;



	return 0;

}
