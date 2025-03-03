#include <iostream>

#include <sstream>

#include <cstdio>

#include <vector>

#include <algorithm>

#include <complex>

#include <cstring>

#include <cstdlib>

#include <string>

#include <cmath>

#include <cassert>

#include <queue>

#include <set>

#include <map>

#include <valarray>

#include <bitset>

#include <stack>

using namespace std;



#define REP(i,n) for(int i=0;i<(int)n;++i)

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define ALL(c) (c).begin(), (c).end()

typedef long long ll;

const int INF = 1<<29;

const double PI = acos(-1);

const double EPS = 1e-8;



int n, m;

int hint[10000][10];

bool appear[10000][10];

int hit[10000], blow[10000];

int tmp[10];

int ans[10];

int ansnum;



typedef pair<bool, int> pbi;



void dfs(int now, int used) {

   REP(i, m) {

    if (hit[i] > n-now || blow[i] > n-now) return;

  }

  // REP(i, now)

  //   cout << tmp[i];

  // cout << endl;

  if (now == n) {

    ansnum++;

    memcpy(ans, tmp, sizeof(tmp));

    return;

  }

 

  REP(i, 10) {

    if (used >> i & 1) continue;

    vector<pbi> record;

    REP(j, m) {

      if (hint[j][now] == i) {

        if (hit[j] > 0) {

          hit[j]--;

          record.push_back(pbi(0, j));

        } else {

          goto br;

        }

      } else if (appear[j][i]) {

        if (blow[j] > 0) {

          blow[j]--;

          record.push_back(pbi(1, j));

        }

        else {

          goto br;

        }

      }

    }

    tmp[now] = i;

    dfs(now+1, used|1<<i);

  br:;

    FOR(it, record) {

      if (it->first) {

        blow[it->second]++;

      } else {

        hit[it->second]++;

      }

    }

  }

}



int main() {

  while(cin >>n>>m, n||m) {

    memset(appear, 0, sizeof(appear));

    REP(i, m) {

      REP(j,n) {

        char c;

        cin >> c;

        hint[i][j] = c-'0';

        appear[i][c-'0'] = 1;

      }

      cin >> hit[i];

      cin >> blow[i];

    }

    ansnum = 0;

    dfs(0, 0);

    if (ansnum == 1) {

      REP(i, n)

        cout << ans[i];

      cout << endl;

    }

    else cout << "NO" << endl;

  }

}