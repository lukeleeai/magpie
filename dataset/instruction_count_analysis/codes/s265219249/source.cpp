#include<iostream>

#include<vector>

#include<algorithm>

#include<cctype>

#include<utility>

#include<string>

#include<cmath>

#include <numeric>

#include<queue>

#include<climits>





#define REP(i, n) for(int i = 0;i < n;i++)

#define REPR(i, n) for(int i = n;i >= 0;i--)

#define FOR(i, m, n) for(int i = m;i < n;i++)

#define FORR(i, m, n) for(int i = m;i >= n;i--)

#define SORT(v, n) sort(v, v+n);

#define VSORT(v) sort(v.begin(), v.end());

#define llong long long

#define pb(a) push_back(a)

//#define INF LLONG_MAX / 2;

using namespace std;

typedef pair<int, int> P;

typedef pair<llong, llong> LP;

typedef pair<int, P> PP;

typedef pair<llong, LP> LPP;

typedef long long int ll;

typedef pair<ll,int> LL_IP;



const ll INF = LLONG_MAX;



#define ARRAY_MAX 100005

#define N_MAX 45

#define AB_MAX 15

#define INF 1e9



int dp[N_MAX][N_MAX * AB_MAX][N_MAX * AB_MAX];



int main(){



    int n,ma,mb;

    cin >> n >> ma >> mb;

    vector<int> a(n),b(n),c(n);

    REP(i,n){

        cin >> a[i] >> b[i] >> c[i];

    }



    for(int i = 0;i <= n;i++){

        for(int j = 0;j <= N_MAX*AB_MAX;j++){

            for(int k = 0;k <= N_MAX*AB_MAX;k++){

                dp[i][j][k] = INF;

            }

        }

    }





    dp[0][0][0] = 0;

    

    for(int i = 1;i <= n;i++){

        for(int j = 0;j <= N_MAX*AB_MAX;j++){

            for(int k = 0;k <= N_MAX*AB_MAX;k++){

                if(dp[i-1][j][k] == INF){

                    continue;

                }

                dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]);

                dp[i][j+a[i-1]][k+b[i-1]] = min(dp[i][j+a[i-1]][k+b[i-1]],dp[i-1][j][k]+c[i-1]);

            }

        }

    }

    int ans = INF;



    for(int i = 1;i <= N_MAX*AB_MAX;i++){

        for(int j = 1;j <= N_MAX*AB_MAX;j++){

            if(i*mb == j*ma){

                ans = min(ans,dp[n][i][j]);

            }

        }

    }



    if(ans == INF){

        ans = -1;

    }

    cout << ans << endl;









    return 0;

}