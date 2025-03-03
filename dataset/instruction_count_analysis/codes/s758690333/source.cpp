#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

#include<queue>

#include<vector>

#include<queue>

#define INF 99999999

using namespace std;

typedef pair<int, int> P;

vector<P> point[7];

int x,y;

int dp[6][1001][6];

char mas[1001][1001];

int cx[6],ans;

int sp,ans1;

int solve(int i , int j, int z);

int main(){

  while(1){

    for(int i = 0; i < 7; i++){

      point[i].clear();

    }

    memset(cx, 0, sizeof(cx));

    ans1 = INF;

    sp = INF;

    cin >> x >> y;

    if(x == 0 && y == 0) break;

    for(int i = 0; i < y; i++) cin >> mas[i];

    for(int i = 0; i < y; i++){ 

      for(int j = 0; j < x; j++){

    if(mas[i][j] == 'S'){

      point[0].push_back(P(j,i));

    }

    if(mas[i][j] == 'G'){

      point[6].push_back(P(j,i));

    }

    if(mas[i][j] >= '1' && mas[i][j] <= '5'){

      point[mas[i][j] - '0'].push_back(P(j,i));

      cx[mas[i][j] - '0']++;

    }

      }

    }

    for(int i = 1; i <= 5; i++){

      rotate(point + 1, point + 2, point + 6);

      rotate(cx + 1, cx + 2, cx + 6);

      memset(dp, -1, sizeof(dp));

      ans = solve(0, 0, 0);

      if(ans < ans1){

    ans1 = ans;

    sp = i;

      }

    }

    if(ans1 == INF) cout << "NA" << endl;

    else cout << sp << " " << ans1 << endl;

  }

}

int solve(int i, int j,int z){

  if(dp[i][j][z] >= 0) return dp[i][j][z];

  if(i == 4){

    return abs(point[6][0].first - point[z][j].first) + abs(point[6][0].second - point[z][j].second);

  }

  int res = INF;

  for(int k = 0; k < cx[z + 1]; k++){

    res = min(abs(point[z + 1][k].first - point[z][j].first) + abs(point[z + 1][k].second - point[z][j].second) + solve(i + 1, k, z + 1),res);

  }

  return dp[i][j][z] = res;

}