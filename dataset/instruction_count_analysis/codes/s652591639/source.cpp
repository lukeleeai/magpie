#include"stdc++.h"

#define rep(i,m) for(long long i=0; i<m; i++)

#define per(i,m) for(long long i=m-1; i>=0; i--)

#define FOR(i,n,m) for(long long i=n; i<m; i++)

#define ROF(i,n,m) for(long long i=m-1; i>=n; i--)

#define SORT(v,n) do{sort(v,v+n);reverse(v,v+n);}while(0)

#define all(x) (x).begin(),(x).end()

#define MP make_pair

#define MT make_tuple

#define EPS (1e-7)

#define INF (1e18)

#define PI (acos(-1))

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

typedef pair<int,int> P;

typedef pair<ll,ll> LP;



 

ll POW(ll x,ll n){

  x%=MOD;

  if(n==0)return 1;

  if(n%2==0)return POW(x*x,n/2)%MOD;

  return x%MOD*POW(x,n-1)%MOD;

}

 

ll POW2(ll x,ll n){

  if(n==0)return 1;

  if(n%2==0)return POW2(x*x,n/2);

  return x*POW2(x,n-1);

}

 

ll POW3(ll x,ll n,ll m){

  x%=m;

  if(n==0)return 1;

  if(n%2==0)return POW3(x*x,n/2,m)%m;

  return x*POW3(x,n-1,m)%m;

}

 

ll gcd(ll u, ll v) {

  ll r;

  while (0 != v) {

    r = u % v; u = v; v = r;

  }

  return u;

}

 

ll lcm(ll u, ll v) {

  return u/gcd(u,v)*v;

}

 

ll KAI(ll m)

{

  if(m<0) return 0;

  if(m==0) return 1;

  return m*KAI(m-1)%MOD;

}

 

ll KAI2(ll m)

{

  if(m<0) return 0;

  if(m==0) return 1;

  return m*KAI2(m-1);

}

 

ll extGCD(ll a, ll b, ll &x, ll &y) {

    if (b == 0) {

        x = 1;

        y = 0;

        return a;

    }

    ll d = extGCD(b, a%b, y, x);

    y -= a / b * x;

    return d;

}

 

inline ll mod(ll a, ll m) {

    return (a % m + m) % m;

}

 

ll modinv(ll a) {

    ll x, y;

    extGCD(a, MOD, x, y);

    return mod(x, MOD);

}

 

ll COM(ll m,ll n)

{

  if(m<n) return 0;

  if(n<0) return 0;

  if(n==0) return 1;

  if(m==n) return 1;

  return KAI(m)%MOD*modinv(KAI(n)%MOD*KAI(m-n)%MOD)%MOD;

}

 

ll COM2(ll m,ll n)

{

  if(m<n) return 0;

  if(n<0) return 0;

  if(n==0) return 1;

  if(m==n) return 1;

  return KAI2(m)/KAI2(n)/KAI2(m-n);

}

 

ll DEC(ll x,ll m,ll n)//xのm進数でのx^nの位の値

{

  return x%POW2(m,n+1)/POW2(m,n);

}

 

ll keta(ll x,ll n)//xのn進数での桁数

{

  if(x==0)return 0;

  return keta(x/n,n)+1;

}

 

ll DIV(ll x,ll n)//x!のnで割り切れる回数

{

  if(x==0)return 0;

  return x/n+DIV(x/n,n);

}

 

ll ORD(ll x,ll n)//xのnで割り切れる回数

{

  if(x==0)return INF;

  if(x%n!=0)return 0;

  return 1+ORD(x/n,n);

}

 

ll SUP(ll x,ll n)//xのnで割れなくなるまで割ったときの余り

{

  if(x==0)return 0;

  if(x%n!=0)return x;

  return SUP(x/n,n);

}

 

ll SGS(ll x,ll y, ll m)//1+x+…+x^(y-1)をmで割った余り

{

  if(y==0)return 0;

  if(y%2==0){

    return (1+POW3(x,y/2,m))*SGS(x,y/2,m)%m;

  }

  return (1+x*SGS(x,y-1,m))%m;

}

 

ll SSGS(ll x,ll y,ll m)//Σ[k=1→y](1+x+…+x^(k-1))をmで割った余り

{

  if(y==0)return 0;

  if(y==1)return 1;

  if(y%2==0){

    return (SSGS(x,y/2,m)*(POW3(x,y/2,m)+1)%m+SGS(x,y/2,m)*y/2%m)%m;

  }

  return (SSGS(x,y-1,m)*x%m+y)%m;

}

 

void shuffle(ll array[], ll size) {

    for(ll i = 0; i < size; i++) {

        ll j = rand()%size;

        ll t = array[i];

        array[i] = array[j];

        array[j] = t;

    }

}



ll SQRT(ll n){

  ll ok,ng,mid;

  ng=n+1;

  if(303700500<ng)ng=303700500;

  ok=0;

  while(abs(ok-ng)>1){

    mid=(ok+ng)/2;

    if(mid*mid<=n){

      ok=mid;

    }

    else{

      ng=mid;

    }

  }

  return ok;

}

 

struct UnionFind

{

  vector<int> par;

  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {

    rep(i,n) par[i] = i;

  }

  int find(int x) {

    if (x == par[x]) return x;

    return par[x] = find(par[x]);

  }

  void unite(int x, int y) {

    x = find(x);

    y = find(y);

    if (x == y) return;

    if (sizes[x] < sizes[y]) swap(x, y);

    par[y] = x;

    sizes[x] += sizes[y];

  }

  bool same(int x, int y) {

    return find(x) == find(y);

  }

  int size(int x) {

    return sizes[find(x)];

  }

};



map< int64_t, int > prime_factor(int64_t n) {

  map< int64_t, int > ret;

  for(int64_t i = 2; i * i <= n; i++) {

    while(n % i == 0) {

      ret[i]++;

      n /= i;

    }

  }

  if(n != 1) ret[n] = 1;

  return ret;

}



bool is_prime(int64_t x) {

  if(x==1)return false;

  for(int64_t i = 2; i * i <= x; i++) {

    if(x % i == 0) return false;

  }

  return true;

}



struct edge{ll to, cost;};

struct graph{

  ll V;

  vector<vector<edge> > G;

  vector<ll> d;



  graph(ll n){

    init(n);

  }



  void init(ll n){

    V = n;

    G.resize(V);

    d.resize(V);

    rep(i,V){

      d[i] = INF;

    }

  }



  void add_edge(ll s, ll t, ll cost){

    edge e;

    e.to = t, e.cost = cost;

    G[s].push_back(e);

  }



  void dijkstra(ll s){

    rep(i,V){

      d[i] = INF;

    }

    d[s] = 0;

    priority_queue<LP,vector<LP>, greater<LP> > que;

    que.push(LP(0,s));

    while(!que.empty()){

      LP p = que.top(); que.pop();

      ll v = p.second;

      if(d[v]<p.first) continue;

      for(auto e : G[v]){

        if(d[e.to]>d[v]+e.cost){

          d[e.to] = d[v]+e.cost;

          que.push(LP(d[e.to],e.to));

        }

      }

    }

  }

};



ll d[300][300];



void warshall_floyd(ll n){  

  rep(i,n)rep(j,n)rep(k,n)d[j][k]=min(d[j][k],d[j][i]+d[i][k]);

}



struct bit{

  ll m;

  vector<ll> b;

  bit(ll i){

    m=i;

    b.resize(m+1);

  }

  ll num(ll i){

    return b[i];

  }

  ll sum(ll i){

    ll s=0;

    while(i>0){ 

      s+=b[i];

      i-=i&-i;

    }

    return s;

  }

  void add(ll i, ll x){

    while(i<=m){

      b[i]+=x;

      i+=i&-i;

    }

  }

};



int main(){

  ll n,x,d,g,l[210000][3]={},ans=0,t,s;

  cin >> n >> x >> d;

  if(d==0){

    if(x==0){

      printf("1");

      return 0;

    }

    printf("%lld",n+1);

    return 0;

  }

  g=gcd(abs(x),abs(d));

  x/=g;

  d/=g;

  if(d<0){

    x*=-1;

    d*=-1;

  }

  rep(i,n){

    l[i+1][0]=l[i][0]+x+i*d;

    l[i+1][1]=l[i][1]+(x+(n-1-i)*d);

  }

  rep(i,min(d,n+1)){

    t=l[i][0];

    s=l[i][1];

    rep(j,(n-i)/d){

      if(t<=l[i+(j+1)*d][0]&&s>=l[i+(j+1)*d][0]&&s<=l[i+(j+1)*d][1])s=l[i+(j+1)*d][1];

      else if(t<=l[i+(j+1)*d][1]&&s>=l[i+(j+1)*d][1]&&t>=l[i+(j+1)*d][0])t=l[i+(j+1)*d][0];

      else if(t<=l[i+(j+1)*d][0]&&s>=l[i+(j+1)*d][1]);

      else if(t>=l[i+(j+1)*d][0]&&s<=l[i+(j+1)*d][1]){

        s=l[i+(j+1)*d][1];

        t=l[i+(j+1)*d][0];

      }

      else{

        ans+=(s-t)/d+1;

        s=l[i+(j+1)*d][1];

        t=l[i+(j+1)*d][0];

      }

    }

    ans+=(s-t)/d+1;

  }

  printf("%lld",ans);

}
