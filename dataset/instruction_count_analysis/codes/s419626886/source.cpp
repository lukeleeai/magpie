#include <iostream>

#include <cmath>

#include <algorithm>

#include <cstdio>

#include <string>

#include <map>

#include <set>

#include <locale.h>

#include <vector>

#include <iomanip>

#include <cassert>

#include <list>

#include <unordered_map>

#include <cstring>



#define all(x) x.begin(), x.end()

#define sz(x) (int)(x.size())

#define pb push_back



#define onlycin ios_base::sync_with_stdio(false); cin.tie(0)

#define mp make_pair

#define endl "\n"

#define rep(i,x,y) for(int i = x; i <= y; ++i)

#define repr(i,x,y) for(long long i = x; i >= y; --i)

#define y1 wearsdfasdf

#define fi first

#define se second



typedef long long ll;



const int N = (100000) + 322;

const int INF = (ll)(1e9) + 7;



using namespace std;



int n, cost[N], flag;



vector <int> v[N];



vector <int> lst;



int getC(int sum, int mx) {

  if (sum / 2 < mx) return sum - mx;

  return sum / 2;

}



bool check(int sum, int av) {

  return (sum / 2 <= av && av <= sum);

}



void dfs(int x, int p = -1) {

  int sum = 0, mx = 0;

  for(auto it : v[x]) {

    if (p == it) continue;

    dfs(it, x);

    sum += cost[it];

    mx = max(mx, cost[it]);

  }

  if (sz(v[x]) > 1) {

   // cout << x << ' ' << sum << ' ' << mx << ' ' << cost[x] << ' ' << getC(sum, mx) << endl;

    if (!check(sum, cost[x])) {flag = 1;}

    int C = sum - cost[x];

    if (C > getC(sum, mx)) flag = 1;

    cost[x] = cost[x] - C;

  }

}



int main () {

  ios_base::sync_with_stdio(false);

  cin >> n;

  rep(i, 1, n) cin >> cost[i];

  rep(i, 1, n - 1) {

    int x, y; cin >> x >> y;

    v[x].pb(y);

    v[y].pb(x);

  }

  int root = 1;

  rep(i, 1, n) {

    if (sz(v[i]) > 1) root = i;

  }

  if (n == 2) {

    if (cost[1] != cost[2]) {

      cout << "NO";

      return 0;

    }

    cout << "YES";

    return 0;

  }

  

  dfs(root);

  if (cost[root] != 0) {

    cout << "NO";

    return 0;

  }

  if (flag == 1) {

    cout << "NO";

    return 0;

  }

  cout << "YES";

  return 0;

}
