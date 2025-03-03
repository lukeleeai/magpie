//#include "stdc++.h"

#include <iostream>

#include <complex>

#include <sstream>

#include <string>

#include <algorithm>

#include <deque>

#include <list>

#include <map>

#include <numeric>

#include <queue>

#include <vector>

#include <set>

#include <limits>

#include <cstdio>

#include <cctype>

#include <cmath>

#include <cstring>

#include <cstdlib>

#include <ctime>

#include <climits>

#include <iomanip>



#define REP(i, n) for(int i = 0; i < (int)(n); i++)

#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)

#define ROF(i, j, k) for(int i = (int)(j); i >= (int)(k); --i)

#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)

#define SORT(v, n) sort(v, v+n)

#define REVERSE(v) reverse((v).begin(), (v).end())



using namespace std;

using ll = long long;

const ll MOD=1000000007LL;

typedef pair<int, int> P;



ll ADD(ll x, ll y) { return (x+y) % MOD; }

ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }

ll MUL(ll x, ll y) { return x*y % MOD; }

ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }

ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }



template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}

template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}



int n, m;

// i本のマッチで作ることができる最大桁数

int dp[10010], a[10];

const int INF = 1e8;

int matti[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};



int

main(void){  

  ios_base::sync_with_stdio(false);

  cin.tie(0);



  cin >> n >> m;

  REP(i, m) cin >> a[i];

  sort(a, a+m);

  reverse(a, a+m);

  fill(dp, dp+10010,-INF);  

  dp[0] = 0;

  

  REP(i, n){

    if(dp[i] == -INF) continue;

    REP(j, m){      

      dp[i+matti[a[j]]] = max(dp[i]+1, dp[i+matti[a[j]]]);

    }

  }

  cerr << dp[n] << endl;



  int used[10];

  fill(used, used+10, 0);

  int index = n;

  while(index!=0){

    REP(i, m){

      //dp[n - matti[a[i]]] == dp[n]-1 -> そのときのa[i]の文字によって文字列長が増えた

      if(index - matti[a[i]] >= 0 && dp[index - matti[a[i]]] == dp[index]-1){

	index -= matti[a[i]];

	//文字の使った回数

	used[a[i]]++;

	break;

      }

    }

  }

  //あとで上の桁から大きい順に出力

  ROF(i, 9, 0){

    REP(j, used[i]){

      cout << i;

    }

  }



  cout << endl;

  

  return 0;

}
