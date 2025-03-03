#include"stdc++.h"



#define debug(x) cerr << #x << ": " << x << '\n'

#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'

using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef vector<ll> vll;

const ll INF = LLONG_MAX/2;

const ll MOD = 1e9+7;

const double EPS=1e-12;



double lmin=INF,lmax=-INF,rmin=INF,rmax=-INF,umin=INF,umax=-INF,dmin=INF,dmax=-INF,xcmin=INF,xcmax=-INF,ycmin=INF,ycmax=-INF;



double xlength(double t){

  return max({rmax+t,lmax-t,xcmax})-min({rmin+t,lmin-t,xcmin});

}

double ylength(double t){

  return max({umax+t,dmax-t,ycmax})-min({umin+t,dmin-t,ycmin});

}

double box(double t){

  return xlength(t)*ylength(t);

}

double golden_search(double a, double b, double f(double)) {

  const double r = 2 / (3 + sqrt(5));

  double c = a + r * (b - a), d = b - r * (b - a);

  double fc = f(c), fd = f(d);

  while (d - c > EPS) {

    if (fc > fd) { // '<': maximum, '>': minimum

      a = c; c = d; d = b - r * (b - a);

      fc = fd; fd = f(d);

    } else {

      b = d; d = c; c = a + r * (b - a);

      fd = fc; fc = f(c);

    }

  }

  return c;

}



signed main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  ll N;cin>>N;

  for(ll i=0;i<N;i++){

    double x,y;char d;cin>>x>>y>>d;

    if(d=='R'){

      rmin=min(rmin,x);

      rmax=max(rmax,x);

      ycmin=min(ycmin,y);

      ycmax=max(ycmax,y);

    }else if(d=='L'){

      lmin=min(lmin,x);

      lmax=max(lmax,x);

      ycmin=min(ycmin,y);

      ycmax=max(ycmax,y);

    }else if(d=='U'){

      umin=min(umin,y);

      umax=max(umax,y);

      xcmin=min(xcmin,x);

      xcmax=max(xcmax,x);

    }else{

      dmin=min(dmin,y);

      dmax=max(dmax,y);

      xcmin=min(xcmin,x);

      xcmax=max(xcmax,x);

    }

  }

  double ans = box(0);

  for(ll i=1;i<=1000;i++){

    ans = min(ans,box(golden_search(0,1e9/i,box)));

  }

  printf("%.10lf\n",ans);

  return 0;

}
