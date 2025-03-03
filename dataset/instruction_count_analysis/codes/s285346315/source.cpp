#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int,int> P;

#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)

const int mod = 1000000007;



int main() {

  int a, b;

  cin >> a >> b;

  int h = 100, w = 100;

  vector<vector<char>> s(101, vector<char>(101));

  rep(i, h / 2) {

    rep(j, w) s[i][j] = '.';

  }

  for(int i = h / 2; i < h; ++i) {

    rep(j, w) s[i][j] = '#';

  }



  --a; --b;

  int cur = 0;

  int height = 0;

  rep(i, b) {

    if(cur >= w) cur = 0, height += 2;

    s[height][cur] = '#';

    cur += 2;

  }

  height = h / 2 + 1;

  cur = 0;

  rep(i, a) {

    if(cur >= w) cur = 0, height += 2;

    s[height][cur] = '.';

    cur += 2;

  }

  cout << h << " " << w << endl;

  rep(i, h) {

    rep(j, w) {

      cout << s[i][j];

    }

    cout << endl;

  }



}