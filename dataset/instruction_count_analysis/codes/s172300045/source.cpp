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



const int MAX_N = 15;

ll X[MAX_N], Y[MAX_N], P[MAX_N];



const ll INF = 1LL << 61;

ll ans[MAX_N];

int N;

ll cx[1 << MAX_N][MAX_N];

ll cy[1 << MAX_N][MAX_N];



const ll BIG = 1e9;

void calcX(int s) {

  if (cx[s][0] != -1) return;



  vector<ll> xs;

  xs.push_back(0); xs.push_back(-BIG); xs.push_back(BIG);

  REP(i, N) if (s >> i & 1) xs.push_back(X[i]);

  sort(ALL(xs)); xs.erase(unique(ALL(xs)), xs.end());

  REP(i, N) {

    auto it = lower_bound(ALL(xs), X[i]);

    ll xx = min(abs(X[i] - *it), abs(X[i] - *(prev(it))));

    cx[s][i] = xx;

  }

}

void calcY(int s) {

  if (cy[s][0] != -1) return;

  vector<ll> xs;

  xs.push_back(0); xs.push_back(-BIG); xs.push_back(BIG);

  REP(i, N) if (s >> i & 1) xs.push_back(Y[i]);

  sort(ALL(xs)); xs.erase(unique(ALL(xs)), xs.end());

  REP(i, N) {

    auto it = lower_bound(ALL(xs), Y[i]);

    ll xx = min(abs(Y[i] - *it), abs(Y[i] - *(prev(it))));

    cy[s][i] = xx;

  }

}



int main2() {



  CLR(cx, -1);

  CLR(cy, -1);



  N = nextLong();

  REP(i, N) {

    X[i] = nextLong();

    Y[i] = nextLong();

    P[i] = nextLong();

  }



  REP(i, N+1) ans[i] = INF;



  {

    ll val = 0;

    REP(i, N) val += P[i] * min(abs(X[i]), abs(Y[i]));

    ans[0] = val;

  }



  const int L = pow(3, N);

  for (int l = 0; l < L; l++) {

    int s = 0;

    int t = 0;



    int k = 0;

    int tmp = l;

    REP(i, N) {

      if (tmp % 3 == 1) { s |= (1 << i); k++; }

      if (tmp % 3 == 2) { t |= (1 << i); k++; }

      tmp /= 3;

    }

    calcX(s);

    calcY(t);



    ll val = 0;

    REP(i, N) {

      ll xx = cx[s][i];

      ll yy = cy[t][i];

      val += P[i] * min(xx, yy);

    }

    chmin(ans[k], val);

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