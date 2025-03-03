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

int H,W;

char a[1010][1010];

int dist[1010][1010] = {0};

int main(){

    cin >> H >> W;

    for(int i = 0; i < H; i++){

        for(int j = 0; j < W; j++){

            cin >> a[i][j];

            dist[i][j] = 0;

        }

    }

    dist[0][0] = 1;

    for(int i = 0; i < H; i++){

        for(int j = 0; j < W; j++){

            dist[i][j] %= MOD;

            if(a[i+1][j] == '.'){

                dist[i+1][j] += dist[i][j];

            }

            if(a[i][j+1] == '.'){

                dist[i][j+1] += dist[i][j];

            }

        }

    }

    dist[H-1][W-1] %= MOD; 

    cout << dist[H-1][W-1] << endl;

}
