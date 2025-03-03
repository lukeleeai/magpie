#include <iostream>

#include <string>

#include <queue>

#include <vector>

#include <set>

#include <map>

#include <algorithm>

#include <utility>

#include <iomanip>



#define ll long long int

#define pb push_back

#define mk make_pair

#define pq priority_queue



using namespace std;

typedef pair<int, int> P;

typedef pair<ll, int> Pl;

const int inf = 1e9;

const ll linf = 1LL << 50;

int n, m, s;

const int mod = 1e5;

ll dp[2][2001][3001];



int main(int argc, char const* argv[])

{

	while(true){

			scanf("%d %d %d", &n, &m, &s);

			if(n == 0)break;

			int target = s - n * n * (n * n + 1) / 2;

			int sup = m - n * n;

			for(int i = 0; i < 2; i++){

					for(int j = 0; j <= sup; j++){

							for(int k = 0; k <= target; k++){

									if(j == 0 && k == 0)dp[i][j][k] = 1;

									else dp[i][j][k] = 0;

							}

					}

			}

			dp[0][0][0] = 1;

			for(int i = 0; i < n * n; i++){

					for(int j = 1; j <= sup; j++){

							for(int k = 1; k <= target; k++){

									dp[(i+1) & 1][j][k] = dp[i & 1][j][k];

									if(k - (n * n - i) >= 0)dp[(i+1) & 1][j][k] += dp[(i+1) & 1][j-1][k-(n * n - i)];

									dp[(i+1) & 1][j][k] %= mod;

							}

					}

			}

			int res = 0;

			for(int i = 0; i <= sup; i++)res = (res + dp[(n*n) & 1][i][target]) % mod;

			cout << res << endl;

	}

	return 0;

}


