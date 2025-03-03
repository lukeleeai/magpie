#include "stdc++.h"

using namespace std;

const int N = 5010;

bool canleft[N][N], canright[N][N];

int n, K;

int a[N];

bool can[N];

int main(){

	ios::sync_with_stdio(0);

	cin.tie(0), cout.tie(0);

	cin >> n >> K;

	for(int i = 1; i <= n; i++)

		cin >> a[i];

	canleft[0][0] = 1;

	for(int i = 1; i <= n - 1; i++){

		for(int j = 0; j < N; j++){

			canleft[i][j] = canleft[i - 1][j];

			if(j >= a[i])

				canleft[i][j] |= canleft[i - 1][j - a[i]];

		}

	}

	canright[n + 1][0] = 1;

	for(int i = n; i >= 2; i--){

		for(int j = 0; j < N; j++){

			canright[i][j] = canright[i + 1][j];

			if(j >= a[i])

				canright[i][j] |= canright[i + 1][j - a[i]];

		}

	}

	int cnt = 0;

	for(int i = 1; i <= n; i++){

		bool nece = false;

		vector<int> A, B;

		for(int j = 0; j < N; j++)

			if(canleft[i - 1][j]) A.push_back(j);

		for(int j = 0; j < N; j++)

			if(canright[i + 1][j]) B.push_back(j);

		for(int val : A){

			int tmp = K - a[i] - val;

			vector<int>::iterator it = lower_bound(B.begin(), B.end(), tmp);

			if(it != B.end()){

				if((*it) + val < K)

					nece = true;

			}

		}

		if(!nece) cnt++;

	}

	cout << cnt << "\n";

	return 0;

}
