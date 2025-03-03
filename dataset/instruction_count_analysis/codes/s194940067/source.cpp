#include "iostream"

#include "climits"

#include "list"

#include "queue"

#include "stack"

#include "set"

#include "functional"

#include "algorithm"

#include "math.h"

#include "utility"

#include "string"

#include "map"

#include "unordered_map"

#include "iomanip"

#include "random"



using namespace std;

const long long int MOD = 1000000007;

list<long long int> Prime(int M) {

	list<long long int>P;

	P.push_back(2);

	P.push_back(3);

	for (int i = 5; i <= M; i += 6) {

		bool flag = true;

		for (auto j : P) {

			if (i%j == 0) {

				flag = false;

				break;

			}

		}

		if (flag)P.push_back(i);

		flag = true;

		for (auto j : P) {

			if ((i + 2) % j == 0) {

				flag = false;

				break;

			}

		}

		if (flag)P.push_back(i + 2);

	}

	return P;

}

long long int power(long long int x, long long int n, long long int M) {

	long long int tmp = 1;



	if (n > 0) {

		tmp = power(x, n / 2, M);

		if (n % 2 == 0) tmp = (tmp*tmp) % M;

		else tmp = (((tmp*tmp) % M)*x) % M;

	}

	return tmp;

}



long long int N, M, K, Q, W, H;

long long int ans;

long long int pas[100001];





int main() {

	ios::sync_with_stdio(false);

	cin >> H >> W >> N >> M;

	long long int num[1000][1000] = {};

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

			num[i][j] = 1;

		}

	}

	for (int i = 0; i < H; i += N) {

		for (int j = 0; j <= W; j+=M) {

			num[i][j] += 250000;

		}

	}

	for (int i = N - 1; i < H; i += N) {

		for (int j = M - 1; j < W; j += M) {

			num[i][j] = -(N*M + 250000);

		}

	}

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++)ans += num[i][j];

	}

	if (ans < 0) {

		cout << "No\n";

		return 0;

	}

	cout << "Yes\n";

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

			if (j)cout << " ";

			cout << num[i][j];

		}

		cout << endl;

	}

	return 0;

}