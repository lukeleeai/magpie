#include"stdc++.h"

using namespace std;

typedef long long ll;

#define MM 1000000000

#define MOD MM+7

#define MAX 301000

#define MAP 110

#define initial_value -1

#define Pair pair<int,int>

#define chmax(a,b) (a<b ? a=b:0)

#define chmin(a,b) (a>b ? a=b:0)

ll INF = 1e18;

int dx[4] = {-1,0,1,0};

int dy[4] = {0,-1,0,1};



int main(){

    int h,w; cin >> h >> w;

    char a[h][w];

    for(int i = 0; i < h; i++){

        for(int j = 0; j < w; j++){

            cin >> a[i][j];

        }

    }

    ll dp[1010][1010] = {0};

    dp[0][0] = 1;

    for(int i = 0; i < h; i++){

        for(int j = 0; j < w; j++){

            dp[i][j] %= MOD;

            if(i != h-1){

                if(a[i+1][j] == '.'){

                    dp[i+1][j] += dp[i][j];

                }

            }

            if(j != w-1){

                if(a[i][j+1] == '.'){

                    dp[i][j+1] += dp[i][j];

                }

            }

        }

    }

    cout << dp[h-1][w-1] << endl;

}
