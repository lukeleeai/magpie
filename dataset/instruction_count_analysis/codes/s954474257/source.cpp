#include <iostream>

#include <string>

using namespace std;



long long solve(string S) {

	long long cnt = 0, ret = 0;

	for (int i = 0; i < S.size(); i++) {

		cnt++;

		if (i == (int)S.size() - 1 || S[i] != S[i + 1]) {

			ret += cnt / 2;

			cnt = 0;

		}

	}

	return ret;

}



int main() {

	string T; cin >> T;

	long long K; cin >> K;



	bool flag = true;

	for (int i = 0; i < (int)T.size() - 1; i++) {

		if (T[i] != T[i + 1]) flag = false;

	}



	if (flag == true) {

		long long len = 1LL * (long long)(T.size()) * K;

		cout << len / 2LL << endl;

	}

	else {

		string V1 = T;

		string V2 = T + T;

		long long R1 = solve(V1);

		long long R2 = solve(V2);

		cout << R1 + (R2 - R1) * (K - 1LL) << endl;

	}

	return 0;

}