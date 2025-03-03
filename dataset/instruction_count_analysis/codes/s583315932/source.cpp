#include <iostream>

#include <string>

#include <algorithm>

#include <vector>

#include <queue>

#include <cstring>

 

#define rep(i, n) for(int i = 0; i < (n); i++)

#define MP make_pair

 

using namespace std;

 

typedef pair<int, int> P;

 

vector<P> open;

int gx, gy;

int W, H, N;

char field[1002][1002];

 

const int dx[] = {0, 1, 0, -1};

const int dy[] = {1, 0, -1, 0};

 

bool visit[1001][1001];

bool check(int n){

    memset(visit, 0, sizeof(visit));

 

    rep(i, n){

        field[open[i].second][open[i].first] = '.';

    }

    for(int i = n; i < open.size(); i++){

        field[open[i].second][open[i].first] = '#';

    }

 

    //rep(i, 10){

    //  rep(j, 10){

    //      cout << field[i][j];

    //  }cout << endl;

    //}cout << endl;

 

    queue<P> q;

    q.push(MP(0, 0));

 

    while(!q.empty()){

        P p = q.front();

        q.pop();

         

        if(visit[p.second][p.first]) continue;

        visit[p.second][p.first] = true;

 

        if(field[p.second][p.first] == 't') return true;

 

        rep(i, 4){

            int nx = p.first+dx[i], ny = p.second+dy[i];

            if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;

            if(field[ny][nx] != '#') q.push(MP(nx, ny));

        }

    }

 

    return false;

}

 

int main(){

    cin >> W >> H;

    rep(i, H) rep(j, W) cin >> field[i][j];

    cin >> N;

    rep(i, N){

        int x, y;

        cin >> x >> y;

        if(field[y][x] == '.'){

            x = y = 1001;

        }

        open.push_back(MP(x, y));

    }

    int lb = -1, ub = N+1;

    while(ub - lb > 1){

        int mid = (lb+ub)/2;

        if(check(mid))ub = mid;

        else lb = mid;

    }

    if(ub == N+1) ub = -1;

    cout << ub << endl;

 

    return 0;

}