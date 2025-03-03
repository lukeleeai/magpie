#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

#include <cmath>

using namespace std;



#define loop(i,N) for(ll (i)=0; (i)<(N);++(i))

#define OMAZINAI cin.tie(0); ios::sync_with_stdio(false);

#define INF (1LL<<61)

typedef long long int ll;



int flag[300];

int main() {

	OMAZINAI;

	std::vector<int> tmp = { 3, 5, 7, 11, 13, 17 };

	int cnt = 0, N, t;

	cin >> N;

	auto add = [&](int n) {

		if(n <= N)

			if (!flag[n]) {

				++cnt;

				flag[n] = 1;

			}

	};

	for (int i : tmp)

			add(std::pow(i, 7));

	for (int i : tmp)

		for (int n : tmp)

			if (i - n)

				add(i*pow(n, 3));

	for (int i : tmp)

		for (int n : tmp)

			for (int t : tmp)

				if (i - n && n - t && t - i)

					add(i*n*t);

	cout << cnt << endl;

	return 0;

}