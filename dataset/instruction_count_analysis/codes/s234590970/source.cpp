#include"stdc++.h"

using namespace std;

#define FOR(i,a,b)  for(int i=(a),i##formax=(b);i< i##formax;i++)

#define FORR(i,a,b) for(int i=(a),i##formin=(b);i>=i##formin;i--)

#define pb push_back

#define mp make_pair

#define fi first

#define se second

#define pcnt __builtin_popcount

#define sz(x) (int)(x).size()

#define maxs(x,y) x=max((x),(y))

#define mins(x,y) x=min((x),(y))

#define show(x) cout<<#x<<" = "<<(x)<<endl;

#define all(a) ((a).begin()),((a).end())

#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define bit(n) (1LL<<(n))

typedef long long ll;

typedef __int128_t lll;

template<class T>using V=vector<T>;

template<class T>using VV=V<V<T>>;

template<class T,class Y>using P=pair<T,Y>;

template<class T,class Y>ostream& operator<<(ostream&o,P<T,Y>&p){return o<<"("<<p.fi<<","<<p.se<<")";}

template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o<<endl;}

template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}



lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}

ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}

ll modPow(lll a,lll n,ll m){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}

//V<ll>F,R;void setF(int n,int mod){F=R=V<ll>(++n);F[0]=1;FOR(i,1,n)F[i]=F[i-1]*i%mod;R[n-1]=modInv(F[n-1],mod);FORR(i,n-1,1)R[i-1]=R[i]*i%mod;}

//ll comb(int a,int b,int m){return a<b||b<0?0:F[a]*R[b]%m*R[a-b]%m;}



const int IINF = 1e9+6;

const ll LINF = 1e18;

const int MOD = 1e9+7; //998244353;

const int N = 1e5+1;

typedef P<int, int> pii;

int n, m, c[N];

ll e[N];

bool z[N];

queue<int> q;

struct UnionFind{

  vector<int> p;

  int g;

  void init(int n){

    p.assign(n, -1);

    g = n;

  }

  int find(int a){

    return p[a] < 0 ? a : p[a] = find(p[a]);

  }

  bool merge(int a, int b){

    a = find(a);

    b = find(b);

    if(a==b) return 0;

    g--;

    if(p[a]>p[b]) swap(a, b);

    p[a] += p[b];

    p[b] = a;

    return 1;

  }

} uf;



void draw(int a, int b){

  e[a] = e[a] * modInv(b, MOD) % MOD; if(--c[a] == 1) q.push(a);

  e[b] = e[b] * modInv(a, MOD) % MOD; if(--c[b] == 1) q.push(b);

  printf("%d %d\n", a, b);

  z[a] ^= true;

}

main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  scanf("%d %d", &n, &m);

  if(m%2){

    printf("-1\n");

    return 0;

  }

  uf.init(n+1);

  fill(e, e+n+1, 1ll);

  FOR(i, 0, m){

    int a, b;

    scanf("%d %d", &a, &b);

    if(uf.merge(a, b)){

      e[a] = e[a]*b%MOD; c[a]++;

      e[b] = e[b]*a%MOD; c[b]++;

    }else{

      printf("%d %d\n", a, b);

      z[a] ^= true;

    }

  }

  FOR(i, 1, n+1) if(c[i]==1) q.push(i);

  while(!q.empty()){

    int t = q.front(); q.pop();

    if(c[t] != 1) continue;

    z[t] ? draw(t, e[t]) : draw(e[t], t);

  }

}