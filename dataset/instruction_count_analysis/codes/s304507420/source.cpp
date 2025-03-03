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

#include <bitset>



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



//解説AC

//https://atcoder.jp/contests/abc118/submissions/4292391



int num[]={0,2,5,5,4,5,6,3,7,6};

int a[10];

int n,m;



void cng(string &t, string p){

  if(t=="0") t=p;

  else if(t.size() < p.size())t=p;

  else if(t.size() == p.size()){

    if(t<p) t=p;

  }

}



int

main(void){  

  ios_base::sync_with_stdio(false);

  cin.tie(0);

  cin >> n >> m;

  REP(i,m) cin >> a[i];



  string dp[100100];



  REP(i, n+1) dp[i] = "0";



  dp[0] = "";

  REP(i, n+1){

    if(dp[i] == "0") continue;

    REP(j, m){

      cng(dp[i+num[a[j]]], dp[i]+(char)(a[j]+'0'));

    }

  }

  cout<<dp[n]<<endl;

  

}
