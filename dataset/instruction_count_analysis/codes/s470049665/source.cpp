#include <iostream>

#include <vector>

#include <algorithm>

#include <set>

using namespace std;

typedef long long ll;

vector<int> DP[5001];



int main()

{

	int N, K; cin >> N >> K;

	vector<int>a(N);

	vector<bool>b(N);



	for (int i = 0; i < N; i++) {

		cin >> a[i];

	}

	sort(a.begin(), a.end());

	reverse(a.begin(), a.end());



	for (int i = 0; i < N; i++) {

		if (a[i] >= K) {

			b[i] = true;

			continue;

		}

		for (int j = K-1; j >= 0; j--) {

			if (DP[j].size() != 0) {

				if (j + a[i] >= K) {

					while(DP[j].size()){

						if (DP[j][0] == -1) {

							DP[j].erase(DP[j].begin());

							continue;

						}

						b[DP[j][0]] = true;

						DP[j].erase(DP[j].begin());

					}

					b[i] = true;

					DP[j].push_back(-1);

					break;

				}

				else {

					for (int k = 0; k < DP[j].size(); k++) {

						DP[j + a[i]].push_back(DP[j][k]);

					}

					DP[j + a[i]].push_back(i);

					break;

				}

			}

		}

		DP[a[i]].push_back(i);

	}



	int ans = 0;

	for (int i = 0; i < N; i++)if (b[i] == false) {

		ans++;

	}

	cout << ans << endl;



    return 0;

}
