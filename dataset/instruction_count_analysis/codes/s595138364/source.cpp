#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define rep(i, n) for(ll i = 0;i < n;i++)

int x4[4] = {1, -1, 0, 0}, y4[4] = {0, 0, 1, -1};





int main() {

  cin.tie(0); ios::sync_with_stdio(false);



  int h, w;

  cin >> h >> w;

  vector<string> s(h);

  rep(i, h) cin >> s[i];



  vector<pii> graph[400][400];



  rep(i, h) rep(j, w) rep(k, 4) {

    int ni = i+x4[k];

    int nj = j+y4[k];

    if (0 <= ni && ni < h && 0 <= nj && nj < w && s[i][j] != s[ni][nj]) {

      graph[i][j].push_back(pii(ni, nj));

    }

  }



  vector<vector<bool>> reached(400, vector<bool>(400));

  ll ans = 0;



  rep(i, h) rep(j, w) {

    if (reached[i][j]) continue;



    ll black = 0;

    ll white = 0;



    queue<pii> que;

    que.push(pii(i, j));

    reached[i][j] = true;



    while (que.size()) {

      pii p = que.front(); que.pop();



      if (s[p.first][p.second] == '#') {

        black++;

      } else {

        white++;

      }



      for (auto&& k : graph[p.first][p.second]) {

        if (reached[k.first][k.second] == false) {



          reached[k.first][k.second] = true;

          que.push(pii(k.first, k.second));

        }

      }

    }



    ans += white*black;

  }



  cout << ans << endl;

}
