#include <iostream>

#include <iomanip>

#include <string>

#include <vector>

#include <algorithm>



using namespace std;



int main(){

	ios_base::sync_with_stdio(false);

	cout << setiosflags(ios::fixed) << setprecision(10);

	while(true){

		int n, m, k;

		cin >> n >> m >> k;

		if(n == 0 && m == 0 && k == 0){ break; }

		double answer = 0;

		if(n == 1){

			const double r = 1.0 / m;

			for(int i = 1; i <= m; ++i){

				answer += max(1, i - k) * r;

			}

		}else{

			const double r = 1.0 / m;

			const int len = n * m + 1;

			vector<double> dp(len);

			dp[0] = 1.0;

			for(int i = 0; i < n; ++i){

				vector<double> next(len);

				for(int j = 0; j + m < len; ++j){

					for(int k = 1; k <= m; ++k){

						next[j + k] += r * dp[j];

					}

				}

				dp.swap(next);

			}

			for(int i = n; i < len; ++i){

				answer += dp[i] * max(1, i - k); 

			}

		}

		cout << answer << endl;

	}

	return 0;

}