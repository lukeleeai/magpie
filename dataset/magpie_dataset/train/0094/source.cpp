#include "stdc++.h"

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)

#define REPR(i,n) for (int i=(int)(n)-1;i>=0;--i)

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define ALL(c) (c).begin(), (c).end()

#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)

#define tpl(...) make_tuple(__VA_ARGS__)

const int INF = 0x3f3f3f3f;

const double EPS = 1e-8;

const double PI = acos(-1);

const int dy[] = {-1,0,1,0};

const int dx[] = {0,1,0,-1};

typedef long long ll;

typedef pair<int,int> pii;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename Ch,typename Tr,typename C,typename=decltype(begin(C()))>basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>&os,

const C& c){os<<'[';for(auto i=begin(c);i!=end(c);++i)os<<(i==begin(c)?"":" ")<<*i;return os<<']';}

template<class S,class T>ostream&operator<<(ostream &o,const pair<S,T>&t){return o<<'('<<t.first<<','<<t.second<<')';}

template<int N,class Tp>void output(ostream&,const Tp&){}

template<int N,class Tp,class,class ...Ts>void output(ostream &o,const Tp&t){if(N)o<<',';o<<get<N>(t);output<N+1,Tp,Ts...>(o,t);}

template<class ...Ts>ostream&operator<<(ostream&o,const tuple<Ts...>&t){o<<'(';output<0,tuple<Ts...>,Ts...>(o,t);return o<<')';}

template<class T>void output(T t,char z=10){if(t<0)t=-t,putchar(45);int c[20];

int k=0;while(t)c[k++]=t%10,t/=10;for(k||(c[k++]=0);k;)putchar(c[--k]^48);putchar(z);}

template<class T>void outputs(T t){output(t);}

template<class S,class ...T>void outputs(S a,T...t){output(a,32);outputs(t...);}

template<class T>void output(T *a,int n){REP(i,n)cout<<a[i]<<(i!=n-1?',':'\n');}

template<class T>void output(T *a,int n,int m){REP(i,n)output(a[i],m);}

template<class T>bool input(T &t){int n=1,c;for(t=0;!isdigit(c=getchar())&&~c&&c-45;);

if(!~c)return 0;for(c-45&&(n=0,t=c^48);isdigit(c=getchar());)t=10*t+c-48;t=n?-t:t;return 1;}

template<class S,class ...T>bool input(S&a,T&...t){input(a);return input(t...);}

template<class T>bool inputs(T *a, int n) { REP(i,n) if(!input(a[i])) return 0; return 1;}



int dp[101][101][101];



struct P {

  int a,e,r;

  void in() {

    cin >> a >> e >> r;

  }

  bool operator<(const P &rhs) const {

    return r < rhs.r;

  }

} p[100];



int main() {

  int d,n;

  while(cin>>d>>n,d||n) {

    REP(i,n) {

      p[i].in();

    }

    sort(p,p+n);

    memset(dp,0x3f,sizeof(dp));

    dp[0][0][0] = 0;

    REP(i,n) {

      for (int j=0; j <= 100; ++j) {

        REP(k,d+1) {

          chmin(dp[i+1][j][k], dp[i][j][k]);

          if (j>=p[i].r) {

            chmin(dp[i+1][min(100,j+p[i].e)][min(d,k+p[i].a)], dp[i+1][j][k] + 1);

            // REP(l,100) {

            //   chmin(dp[i+1][min(100,j+p[i].e*l)][min(d,k+p[i].a*l)], dp[i][j][k] + l);

            // }

          }

        }

      }

    }

    int ans = INF;

    REP(i,101) chmin(ans, dp[n][i][d]);

    if (ans == INF) puts("NA");

    else cout << ans << endl;

  }

}