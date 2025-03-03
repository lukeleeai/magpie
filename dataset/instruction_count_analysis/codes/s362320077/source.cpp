#include "stdc++.h"

using namespace std;



typedef long long ll;

#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)

#define ALL(v) (v).begin(),(v).end()

#define CLR(t,v) memset(t,(v),sizeof(t))

template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}

template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}

template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}

template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}



ll nextLong() { ll x; scanf("%lld", &x); return x;}



const ll INF = 1LL << 61;

const int MAX_N = 15;

int N;

ll X[MAX_N], Y[MAX_N], P[MAX_N];



ll ans[MAX_N];

ll dp1[MAX_N+1][MAX_N+1];

ll dp2[MAX_N+1][MAX_N+1];



ll rec(const vector<pair<ll, ll>>& at, ll dp[MAX_N+1][MAX_N+1], int R, int K) {

  if (dp[R][K] != -1) return dp[R][K];

  ll res = INF;

  if (R <= K) { chmin(res, 0LL); }

  else if (K == 0) {

    ll val = 0;

    for (int i = 0; i < R; i++) {

      val += at[i].second * abs(at[i].first);

    }

    chmin(res, val);

  } else if (K >= 1) {

    for (int L = 0; L < R; L++) {

      for (int z = L; z < R; z++) {

        ll val = 0;

        for (int i = L; i < R; i++) {

          val += at[i].second * abs(at[i].first - at[z].first);

        }

        chmin(res, val + rec(at, dp, L, K-1));

      }

    }

    for (int L = 0; L < R; L++) {

      ll val = 0;

      for (int i = L; i < R; i++) {

        val += at[i].second * abs(at[i].first);

      }

      chmin(res, val + rec(at, dp, L, K));

    }

  }

  return dp[R][K] = res;

}



int main2() {



  N = nextLong();

  REP(i, N) {

    X[i] = nextLong();

    Y[i] = nextLong();

    P[i] = nextLong();

  }



  REP(i, N+1) ans[i] = INF;



  REP(s, 1<<N) {

    vector<pair<ll, ll>> x, y;

    REP(i, N)

      if (s >> i & 1) x.push_back({X[i], P[i]});

      else y.push_back({Y[i], P[i]});



    sort(ALL(x));

    sort(ALL(y));

    CLR(dp1, -1);

    CLR(dp2, -1);



    for (int a = 0; a <= N; a++) {

      for (int b = 0; b + a <= N; b++) {

        ll cost1 = rec(x, dp1, x.size(), a);

        ll cost2 = rec(y, dp2, y.size(), b);

        chmin(ans[a+b], cost1 + cost2);

      }

    }



  }

  REP(i, N+1)

    cout << ans[i] << endl;

  return 0;

}



int main() {



#ifdef LOCAL

  for (;!cin.eof();cin>>ws)

#endif

    main2();

  return 0;

}