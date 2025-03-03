#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

#include <map>

#include <cmath>

#include <queue>

#include <numeric>

#include <climits>

#include <iterator>

#include <iomanip>

#include <stack>

#include <set>

#include <bitset>

#include <functional>

using namespace std;

const constexpr int INF = 1e9;

//typedef std::pair<std::string,double> P;



#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)



typedef long long ll;

typedef vector<int> VI;

const constexpr ll MOD = 1e9+7;

 

struct Less {

    bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {

        return x.first > y.first;

    }

};



ll GCD(ll a, ll b){

    if(b==0) return a;

    return GCD(b, a%b);

}





//グラフの隣接リスト

VI g[200010];

//頂点の入次数を管理

int h[100010];

int H, W;

vector<string> field;

int dist[51][51];

int dxy[5]={-1, 0, 1, 0, -1};

int bfs(){

    for(int i=0; i<H; ++i){

        for(int j=0; j<W; ++j){

            dist[i][j] = -1;

        }

    }

    

    queue<pair<int, int> > q;

    q.push({0, 0});

    dist[0][0]=1;

    while(!q.empty()){

        pair<int, int> p = q.front(); q.pop();

        for(int i=0; i<4; ++i){

            int nx = p.second + dxy[i],

                ny = p.first + dxy[i+1];

            if(ny>=0&&ny<H&&nx>=0&&nx<W&&field[ny][nx]=='.'&&dist[ny][nx]==-1){

                q.push({ny, nx});

                dist[ny][nx] = dist[p.first][p.second]+1;

            }

        }  

    }

    return dist[H-1][W-1];

}

int main(void) {

    cin >> H >> W;

    cin.ignore();

    for(int i=0; i<H; ++i){

        string s; getline(cin, s);

        field.push_back(s);

    }

    int c=0;

    for(int i=0; i<H; ++i){

        for(int j=0; j<W; ++j){

            if(field[i][j]=='#') c++;

        }

    }

    int ans = bfs();

    

    if(ans!=-1){

        cout << W*H-ans-c << endl;

    }else cout << -1 << endl;

    return 0;

}