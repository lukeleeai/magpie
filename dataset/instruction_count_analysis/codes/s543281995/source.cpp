#include <iostream>

#include <iomanip>

#include <cstdio>

#include <string>

#include <cstring>

#include <deque>

#include <list>

#include <queue>

#include <stack>

#include <vector>

#include <utility>

#include <algorithm>

#include <map>

#include <set>

#include <complex>

#include <cmath>

#include <limits>

#include <cfloat>

#include <climits>

#include <ctime>

#include <cassert>

using namespace std;



#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)

#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)

#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)

#define all(v) begin(v), end(v)

#define pb(a) push_back(a)

#define fr first

#define sc second

#define INF 2000000000

#define int long long int



#define X real()

#define Y imag()

#define EPS (1e-10)

#define EQ(a,b) (abs((a) - (b)) < EPS)

#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )

#define LE(n, m) ((n) < (m) + EPS)

#define LEQ(n, m) ((n) <= (m) + EPS)

#define GE(n, m) ((n) + EPS > (m))

#define GEQ(n, m) ((n) + EPS >= (m))



typedef vector<int> VI;

typedef vector<VI> MAT;

typedef pair<int, int> pii;

typedef long long ll;



typedef complex<double> P;

typedef pair<P, P> L;

typedef pair<P, double> C;



int dy[]={0, 0, 1, -1};

int dx[]={1, -1, 0, 0};

int const MOD = 1000000007;



namespace std {

    bool operator<(const P& a, const P& b) {

        return a.X != b.X ? a.X < b.X : a.Y < b.Y;

    }

}



bool take[310][310];



signed main() {

    int n;

    while(cin >> n, n) {

        int w[310];

        rep(i,0,n) cin >> w[i];

        memset(take, false, sizeof(take));



        rep(i,0,n) {

            rep(j,0,n-i) {

                int len = i+1;

                int s = j, t = j+i;

                rep(k,s,t) {

                    if(take[s][k] && take[k+1][t]) take[s][t] = true;

                }

                if(len == 2) {

                    if(abs(w[s] - w[t]) < 2) {

                        take[s][t] = true;

                    }

                }

                if(take[s][t]) {

                    int x = s-1, y = t+1;

                    while(1) {

                        if(x < 0 || x >= n || y < 0 || y >= n) break;

                        if(abs(w[x] - w[y]) >= 2) break;

                        take[x][y] = true;

                        x--; y++;

                    }

                }

            }

        }



        int dp[310][310] = {};

        rep(i,0,n) rep(j,i+1,n) {

            if(take[i][j]) dp[i][j] = j-i+1;

        }



        rep(i,0,n) rep(j,i,n) rep(k,i,j) {

            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);

        }

        cout << dp[0][n-1] << endl;

    }

    return 0;

}