#include <iostream>

#include <vector>

#include <string>

#include <cmath>

#include <algorithm>

#include <utility>

#include <queue>

#include <set>

#include <map>



using namespace std;

typedef  long long ll;

typedef pair<int,int> PII;

typedef vector<int> VI;

typedef vector<VI> VVI;

#define  MP make_pair

#define  PB push_back

#define inf  1000000007

#define rep(i,n) for(int i=0;i<(int)(n);++i)



ll l[201][201];

ll s[201][201];

ll dp[1001][201];





int main(){

	int n,m,r;

	while(cin >> n >> m && n!=0){

		for(int i=0;i<200;i++){

			for(int j=0;j<200;j++){

				l[i][j] = inf;

				s[i][j] = inf;

				if(i==j){

					l[i][j] = 0;

					s[i][j] = 0;

				}

			}

		}

		for(int i=0;i<m;i++){

			int x,y;

			ll t;

			char c;

			cin >> x >> y >> t >> c;

			x--;

			y--;

			if(c=='L'){

				l[x][y] = min(l[x][y],t);

				l[y][x] = min(l[x][y],t);

			}else{

				s[x][y] = min(s[x][y],t);

				s[y][x] = min(s[x][y],t);

			}

		}

		for(int k=0;k<n;k++){

			for(int i=0;i<n;i++){

				for(int j=0;j<n;j++){

					l[i][j] = min(l[i][k]+l[k][j],l[i][j]);

					s[i][j] = min(s[i][k]+s[k][j],s[i][j]);

				}

			}

		}

		cin >> r;

		vector<int> z(r);

		for(int i=0;i<r;i++){

			cin >> z[i];

			z[i]--;

		}

		for(int i=0;i<r;i++){

			for(int j=0;j<n;j++){

				dp[i][j] = inf;

			}

		}

		dp[0][z[0]] = 0;

		for(int i=1;i<r;i++){

			for(int j=0;j<n;j++){

				for(int k=0;k<n;k++){

					if(j==k) dp[i][j] = min(dp[i][j],dp[i-1][k] + l[z[i-1]][z[i]]);

					else dp[i][j] = min(dp[i][j],dp[i-1][k]+l[z[i-1]][k]+s[k][j]+l[j][z[i]]);

				}

			}

		}

		ll ans = inf;

		for(int i=0;i<n;i++){

			ans = min(ans,dp[r-1][i]);

		}

		cout << ans << endl;

	}

	return 0;

}
