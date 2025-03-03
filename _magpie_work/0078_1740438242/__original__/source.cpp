#include <stdio.h>

#include <cctype>

#include <limits.h>

#include <math.h>

#include <complex>

#include <bitset>

#include <vector>

#include <map>

#include <set>

#include <stack>

#include <queue>

#include <cstring>

#include <string>

#include <sstream>

#include <algorithm>

#include <iomanip>

#include <iostream>



#define VARIABLE(x) cerr << #x << "=" << x << endl

#define BINARY(x) static_cast<bitset<16> >(x);

#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))



const int INF = 1000000000;

const double EPS = 1e-8;

const double PI = 3.14159;

int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};

using namespace std;

//typedef pair<int, int> P;

struct P {

	int x, y;

	P(int x, int y):x(x), y(y){}

	P(){}

};



/** Problem0244 : Hot Spring Trip **/

int cost[300][300];



int main()

{

	int N, M;

	

	while (cin>>N>>M, N||M) {

		rep(i, 300) rep(j, 300)

			cost[i][j] = i==j?0:INF;

	

		rep(i, M) {

			int a, b, c; cin>>a>>b>>c;

			a--, b--;

			cost[a][b] = cost[b][a] = c;

		}

		

		vector<P> can_free;

		rep(i, N) {

			rep(j, N) {

				if (cost[i][j]!=INF && i!=j) {

					rep(k, N) {

						if (cost[j][k]!=INF && i!=k && j!=k)

							can_free.push_back(P(i, k));

					}

				}

			}

		}

		

		rep(k, N) {

			rep(i, N) {

				rep(j, N) {

					cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);

				}

			}

		}

		

		int ans=cost[0][N-1];

		rep(i, can_free.size()) {

			ans = min(cost[0][can_free[i].x]+cost[can_free[i].y][N-1], ans);

		}

		

		cout << ans << endl;

	}

}