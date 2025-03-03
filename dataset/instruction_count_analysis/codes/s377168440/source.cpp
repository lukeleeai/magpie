#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



typedef int _loop_int;

#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)

#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)

#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)



#define DEBUG(x) cout<<#x<<": "<<x<<endl

#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl

#define ALL(a) (a).begin(),(a).end()



#define CHMIN(a,b) a=min((a),(b))

#define CHMAX(a,b) a=max((a),(b))



// mod

const ll MOD = 1000000007ll;

#define FIX(a) ((a)%MOD+MOD)%MOD



// floating

typedef double Real;

const Real EPS = 1e-11;

#define EQ0(x) (abs(x)<EPS)

#define EQ(a,b) (abs(a-b)<EPS)

typedef complex<Real> P;



const int INF = 1<<30;



int b;



int n;

int a[252521];

const int N = 1<<18;

pii seg[2*N];

pii qmin(int l, int r, int a, int b, int k){

  if(r<=a || b<=l)return pii(INF,INF);

  if(l<=a && b<=r)return seg[k];

  int m = (a+b)/2;

  return min(qmin(l,r,a,m,2*k+1),qmin(l,r,m,b,2*k+2));

}



ll dfs(int l, int r, int x){

  if(r==l)return 0;

  if(r-l==1)return 1;

  ll ret = 0;

  int cnt = 0;

  pii P = qmin(l,r,0,N,0);

  int v = P.first;

  int p = P.second;

  if(l<p)ret = min(ret+max(1ll,dfs(l,p,v)),1ll<<60);

  p++;

  while(p<r){

    P = qmin(p,r,0,N,0);

    if(P.first != v)break;

    int q = P.second;

    ret = min(ret+max(1ll,dfs(p,q,v)),1ll<<60);

    p = q+1;

  }

  ret = min(ret+max(1ll,dfs(p,r,v)),1ll<<60);

  int sa = v-x;



  ll a = b;

  ll c = sa;

  ll bsa = 1;

  while(c){

    if(c&1)bsa=min(bsa*a,1ll<<30);

    a=min(a*a,1ll<<30);

    c>>=1;

  }

  return (ret+bsa-1)/bsa;

}



int main(){

  scanf("%d",&n);

  REP(i,n)scanf("%d",a+i);

  // 1 check

  bool ok1 = true;

  REP(i,n-1)if(a[i]>=a[i+1]){

    ok1 = false; break;

  }

  if(ok1){

    puts("1");

    return 0;

  }

  // seg

  REP(i,n)seg[i+N-1] = pii(a[i],i);

  FOR(i,n,N)seg[i+N-1] = pii(INF,INF);

  FORR(i,0,N-1)seg[i] = min(seg[2*i+1],seg[2*i+2]);



  int low = 1, high = n+10;

  while(low+1<high){

    b = (low+high)/2;

    ll ret = dfs(0,n,0);

    if(ret<=1){

      high = b;

    }else{

      low = b;

    }

  }

  printf("%d\n",high);

  return 0;

}
