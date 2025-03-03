#include "stdc++.h"

#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)

#define RREP(i,n) for(int i=int(n)-1;i>=0;--i)

#define rep(i,a,b) for(int i=int(a);i<int(b);++i)

#define rrep(i,a,b) for(int i=int(a)-1;i>=int(b);--i)

#define All(x) (x).begin(),(x).end()

#define rAll(x) (x).rbegin(),(x).rend()

#define ITR(i,x) for(auto i=(x).begin();i!=(x).end();++i)

using std::cin;

using std::cout;

using std::cerr;

using std::endl;

using std::vector;

using std::string;

using Graph = vector<vector<int>>;



typedef long long ll;

typedef std::pair<ll, ll> P;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<ll> vl;

typedef vector<vl> vvl;

constexpr ll mod = 1e9+7;

constexpr double eps = 1e-9;

const double PI = acos(-1);

void solve();



namespace Math{

    template<typename T>

    bool chmax(T &a,T b){

        if(a<b){

            a=b;

            return true;

        }

        return false;

    }

    template<typename T>

    bool chmin(T &a,T b){

        if(b<a){

            a=b;

            return true;

        }

        return false;

    }

    ll bisearch(ll ok,ll ng,std::function<bool(ll)> check){

        while(llabs(ok-ng)>1){

            ll mid=ng-((ng-ok)>>1);

            if(check(mid)) ok=mid;

            else ng=mid;

        }

        return ok;

    }

    ll sqrt(ll n){ll s=1; while(s*s>n||n>=(s+1)*(s+1)){ s=(n/s+s)/2; } return s;}

    ll roundup(ll n,ll div){

        if(n>0) return (n-1)/div+1;

        else return n/div;    

    }

    bool square(ll a){ll n=Math::sqrt(a);return a==n*n;}

    template<typename T>

    T pow(T x, ll n){

        T ans = T(1);

        while(n != 0){

            if(n&1) ans = ans*x;

            x = x*x;

            n = n >> 1;

        }

        return ans;

    }

    int digitsum(ll N,int a){

        if(N==0) return 0;

        int ret=0;

        ret+=digitsum(N/a,a)+N%a;

        return ret;

    }

    ll gcd(ll x,ll y){return y ? gcd(y,x%y) : x;};

    ll lcm(ll x,ll y){return x/Math::gcd(x,y)*y;}

    ll manhattan(const P &a,const P &b){return llabs(a.first-b.first)+llabs(a.second-b.second);}

}



namespace Solution{

    ll knapsack(int kinds,int MAX_W,const vl &weight,const vl &cost){

        vector<vector<ll>> dp(kinds+1,vector<ll>(MAX_W+1,0));

        REP(i,kinds) REP(j,MAX_W+1){

            if(j<weight[i]) dp[i+1][j]=dp[i][j];

            else dp[i+1][j]=std::max(dp[i][j],dp[i][j-weight[i]]+cost[i]);

        }

        return dp[kinds][MAX_W];

    }

    ll cost_based_knapsack(int kinds,int MAX_W,const vl &weight,const vl &cost){

        int MAX_V=0;

        REP(i,kinds) Math::chmax(MAX_V,(int)cost[i]);

        vvl dp(kinds+1,vl(kinds*MAX_V+1,1LL<<58));

        dp[0][0] = 0;

        REP(i,kinds) REP(j,kinds*MAX_V+1){

            if(j<cost[i]) dp[i+1][j]=dp[i][j];

            else dp[i+1][j] = std::min(dp[i][j],dp[i][j-cost[i]]+weight[i]);

        }

        int res=0;

        REP(i,kinds*MAX_V+1) if(dp[kinds][i]<=MAX_W) res=i;

        return res;

    }

    ll unlimited_knapsack(int kinds,int MAX_W,const vl &weight,const vl &cost){

        vector<vector<ll>> dp(kinds+1,vector<ll>(MAX_W+1,0));

        REP(i,kinds) REP(j,MAX_W+1){

            if(j<weight[i]) dp[i+1][j]=dp[i][j];

            else dp[i+1][j]=std::max(dp[i][j],dp[i+1][j-weight[i]]+cost[i]);

        }

        return dp[kinds][MAX_W];

    }

    ll huge_knapsack(int kinds,ll MAX_W,const vl &weight,const vl &cost){

        int n2=kinds/2;

        vector<P> ps(1<<(kinds/2));

        REP(i,1<<n2){

            ll sw=0,sv=0;

            REP(j,n2){

                if(i>>j&1){

                    sw += weight[j];

                    sv += cost[j];

                }

            }

            ps[i] = P(sw,sv);

        }

        std::sort(ps.begin(),ps.begin() + (1<<n2) );

        int m=1;

        rep(i,1,1<<n2){

            if(ps[m-1].second<ps[i].second) ps[m++] = ps[i];

        }



        ll res=0;

        REP(i,1<<(kinds-n2)){

            ll sw=0,sv=0;

            REP(j,kinds-n2){

                if((i>>j)&1){

                    sw += weight[n2+j];

                    sv += cost[n2+j];

                }

            }

            if(sw<=MAX_W){

                ll tv = (lower_bound(ps.begin(),ps.begin()+m,P(MAX_W-sw,LLONG_MAX))-1)->second;

                Math::chmax(res,sv+tv);

            }

        }

        return res;

    }

    ll choose_MonN(int N,int M,const vl &cost){

        vvl dp(N+1,vl(M+1,-1LL<<58));

        REP(i,N+1) dp[i][0]=0;

        REP(i,N) REP(j,M){

            if(j>i) break;

            dp[i+1][j+1]=std::max(dp[i][j+1],dp[i][j]+cost[i]);

        }

        return dp[N][M];

    }

    ll Partition_Func(int n,int k){

        vector<vector<ll>> dp(k+1,vector<ll> (n+1,0));

        dp[0][0]=1;

        rep(i,1,k+1) REP(j,n+1){

            if(j-i>=0) dp[i][j]=(dp[i][j-i]+dp[i-1][j]);

            else dp[i][j]=dp[i-1][j];

        }

        return dp[k][n];

    }

    int LCS(string s,string t){

        int n=s.length(),m=s.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1));

        REP(i,n) REP(j,m){

            if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;

            else dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);

        }

        return dp[n][m];

    }

    int LIS(const vector<ll> a){

        int n=a.size();

        ll INF=1LL<<50;

        vector<ll> dp(n+1,INF);

        REP(i,n) *std::lower_bound(All(dp),a[i])=a[i];

        int k=std::lower_bound(All(dp),INF)-dp.begin();

        return k;

    }

    

    int max_flow(int s,int t,const vector<vector<P>> &g){

        struct edge_{int to,cap, rev;};

        vector<bool> used(g.size(),false);

        vector<vector<edge_>> G(g.size());

        REP(i,g.size()) REP(j,g[i].size()){

            int from = i, to = g[i][j].second;

            int cap = g[i][j].first;

            G[from].push_back((edge_){to,cap,(int)G[to].size()});

            G[to].push_back((edge_){from,0,(int)G[from].size()-1});

        }

        auto dfs = [&](auto&& f,int v,int t,int fl)->int{

            if(v==t) return fl;

            used[v] = true;

            REP(i,G[v].size()){

                edge_ &e = G[v][i];

                if(!used[e.to] && e.cap>0){

                    int d = f(f, e.to,t,std::min(fl,e.cap));

                    if(d>0){

                        e.cap -= d;

                        G[e.to][e.rev].cap += d;

                        return d;

                    }

                }

            }

            return 0;

        };

        int flow=0;

        while(1){

            used.assign(used.size(),false);

            int f = dfs(dfs,s,t,INT_MAX);

            if(f==0) return flow;

            flow += f;

        }

    }

    int bipartite_matching_calculate(const Graph &g){

        int V = g.size();

        vi match(V,-1);

        vector<bool> used(V,false);

        auto dfs = [&](auto&& f,int v)->bool{

            used[v]=true;

            REP(i,g[v].size()){

                int u = g[v][i], w = match[u];

                if(w<0 || !used[w] && f(f,w)){

                    match[v]=u;

                    match[u]=v;

                    return true;

                }

            }

            return false;

        };

        int res=0;

        REP(v,V){

            if(match[v] < 0){

                used.assign(V,false);

                if(dfs(dfs,v)) res++;

            }

        }

        return res;

    }

    int bipartite_matching(int l,int r,std::function<bool(int,int)> F){

        int V = l+r;

        Graph G(V);

        REP(i,l) REP(j,r) if(F(i,j)){

            G[i].push_back(l+j);

            G[l+j].push_back(i);

        }

        return bipartite_matching_calculate(G);

    }

    ll dinic(int s,int t,const vector<vector<P>> &graph){

        struct max_flow {

            struct edge_ { int to;ll cap;int rev; };

            int V;

            vector<vector<edge_>> G;

            vector<int> itr, level;

            max_flow(int V) : V(V) { G.assign(V,vector<edge_>()); }



            void add_edge(int from, int to, ll cap) {

                G[from].push_back((edge_) {to, cap, (int) G[to].size()});

                G[to].push_back((edge_) {from, 0, (int) G[from].size()-1});

            }

            void bfs(int s) {

                level.assign(V,-1);

                std::queue<int> q;

                level[s] = 0; q.push(s);

                while (!q.empty()) {

                    int v = q.front(); q.pop();

                    for(auto &e: G[v]) if(e.cap > 0 and level[e.to] < 0) {

                            level[e.to] = level[v] + 1;

                            q.push(e.to);

                    }

                }

            }



            ll dfs(int v, int t, ll f) {

                if(v == t) return f;

                for(int& i=itr[v]; i < (int) G[v].size(); ++i) {

                    edge_& e = G[v][i];

                    if (e.cap > 0 and level[v] < level[e.to]) {

                        int d = dfs(e.to, t, std::min(f, e.cap));

                        if (d > 0) {

                            e.cap -= d;

                            G[e.to][e.rev].cap += d;

                            return d;

                        }

                    }

                }

                return 0;

            }



            int run(int s, int t) {

                int ret = 0, f;

                while(bfs(s), level[t] >= 0) {

                    itr.assign(V,0);

                    while ((f = dfs(s, t, 1LL<<59)) > 0) ret += f;

                }

                return ret;

            }

        };

        max_flow d(graph.size());

        REP(i,graph.size()) for(auto e:graph[i]){

            d.add_edge(i,e.second,e.first);

        }

        return d.run(s,t);

    }

}



template<class V> 

vector<int> Zalgo(V s){

    vector<int> A(s.size(),0);

    A[0]=s.size();

    int i = 1, j = 0;

    while (i < s.size()) {

        while (i+j < s.size() && s[j] == s[i+j]) ++j;

        A[i] = j;

    if (j == 0) { ++i; continue;}

    int k = 1;

    while (i+k < s.size() && k+A[k] < j) A[i+k] = A[k], ++k;

    i += k; j -= k;

    }

    return A;

}

class mint {

 private:

  ll _num,_mod=mod;

  mint set(ll num){ 

      _num = num ;

      if(_num<0){

          if(_num>=-_mod)_num=_mod+_num;

          else _num=_mod-(-_num)%_mod;

      }

      else if(_num>=_mod) _num%=_mod;

      return *this;

  }

  ll imod()const{

    ll n=_mod-2;

    ll ans = 1,x=_num;

    while(n != 0){

        if(n&1) ans = ans*x%_mod;

        x = x*x%_mod;

        n = n >> 1;

    }

    return ans;

  }

 public:

  explicit mint(){ _num = 0; }

  explicit mint(ll num){

      _num = num;

      if(_num<0){

          if(_num>=-_mod)_num=_mod+_num;

          else _num=_mod-(-_num)%_mod;

      }

      else if(_num>=_mod) _num%=_mod;

  }

  explicit mint(ll num,ll M){

      _mod=M;

      _num=num;

      if(_num<0){

          if(_num>=-_mod)_num=_mod+_num;

          else _num=_mod-(-_num)%_mod;

      }

      else if(_num>=_mod) _num%=_mod;

  }

  mint(const mint &cp){_num=cp._num;_mod=cp._mod;}

  

  mint operator+ (const mint &x)const{ return mint(_num + x._num , _mod); }

  mint operator- (const mint &x)const{ return mint(_num - x._num , _mod);}

  mint operator* (const mint &x)const{ return mint(_num * x._num , _mod); }

  mint operator/ (const mint &x)const{ return mint(_num * x.imod() , _mod);}

  

  mint operator+=(const mint &x){ return set(_num + x._num); }

  mint operator-=(const mint &x){ return set(_num - x._num); }

  mint operator*=(const mint &x){ return set(_num * x._num); }

  mint operator/=(const mint &x){ return set(_num * x.imod());}



  mint operator= (const ll x){ return set(x); }

  mint operator+ (const ll x)const{return *this + mint(x,_mod); }

  mint operator- (const ll x)const{ return *this - mint(x,_mod); }

  mint operator* (const ll x)const{ return *this * mint(x,_mod); }

  mint operator/ (const ll x)const{ return *this/mint(x);}



  mint operator+=(const ll x){ *this = *this + x;return *this; }

  mint operator-=(const ll x){ *this = *this - x;return *this; }

  mint operator*=(const ll x){ *this = *this * x;return *this;}

  mint operator/=(const ll x){ *this = *this / x;return *this;}



  bool operator==(const mint &x)const{return _num==x._num;}

  bool operator!=(const mint &x)const{return _num!=x._num;}



  friend mint operator+(ll x,const mint &m){return mint(m._num + x , m._mod);}

  friend mint operator-(ll x,const mint &m){return mint( x - m._num , m._mod);}

  friend mint operator*(ll x,const mint &m){return mint(m._num * (x % m._mod) , m._mod);}

  friend mint operator/(ll x,const mint &m){return mint(m.imod() * (x % m._mod) , m._mod);}



  explicit operator ll() { return _num; }

  explicit operator int() { return (int)_num; }

  

  friend std::ostream& operator<<(std::ostream &os, const mint &x){ os << x._num; return os; }

  friend std::istream& operator>>(std::istream &is, mint &x){ll val; is>>val; x.set(val); return is;}

};

ll inv_mod(ll a,ll _mod){return (ll)Math::pow(mint(a,_mod),_mod-2);}

class Factorial{

 private:

    vector<ll> fac;

    vector<ll> ifac;

 public:

    

    Factorial(ll N){

        fac.push_back(1);

        REP(i,N) fac.push_back(fac[i]*(i+1)%mod);

        ifac.resize(N+1);

        ifac[N]=inv_mod(fac[N],mod);

        REP(i,N) ifac[N-1-i]=(ifac[N-i]*(N-i))%mod;

    }



    ll fact(ll a){return fac[a];}

    ll ifact(ll a){return ifac[a];}



    ll cmb(ll a,ll b){

        if(a==0&&b==0) return 1;

        if(a<b||a<0||b<0) return 0;

        ll tmp =ifact(a-b)*ifact(b)%mod;

        return tmp*fac[a]%mod;

    }

    ll per(ll a,ll b){

        if(a==0&&b==0) return 1;

        if(a<b||a<0||b<0) return 0;

        return fac[a]*ifac[a-b]%mod;

    }

};

template<typename T> class MAT{

 private:

    int row,col;

    vector<vector<T>> _A;

    double eps = 1e-9;

    MAT set(vector<vector<T>> A){_A = A ; return *this;}

 public:

    MAT(){ }

    MAT(int n,int m=0,T x=T(0)){

        if(n<1 || m<0){cout << "err Matrix::Matrix" <<endl;exit(1);}

        row = n;

        col = m?m:n;//return E if m=0

        REP(i,row){

            vector<T> a(col,x);

            _A.push_back(a);

        }

        if(m==0) REP(i,n) _A[i][i]=1.0;

    }

    MAT(vector<vector<T>> A){row=A.size();col=A[0].size();_A=A;}

    MAT(const MAT &cp){_A=cp._A;row=cp.row;col=cp.col;}

    T* operator[] (int i){return _A[i].data();}

    MAT operator= (vector<vector<T>> x) {return set(x);}

    MAT operator+ (MAT x) const {

        if(row!=x.row || col!=x.col){

            cerr << "err Matrix::operator+" <<endl;

            cerr << "  not equal matrix size" <<endl;

            exit(0);

        }

        MAT r(row, col);

        REP(i,row) REP(j,col) r[i][j]=_A[i][j]+x[i][j];

        return r;

    }

    MAT operator- (MAT x) const {

        if(row!=x.row || col!=x.col){

            cerr << "err Matrix::operator-" <<endl;

            cerr << "  not equal matrix size" <<endl;

            exit(0);

        }

        MAT r(row, col);

        REP(i,row) REP(j,col) r[i][j]=_A[i][j]-x[i][j];

        return r;

    }

    MAT operator* (MAT x) const {

        if(x.col==1&&x.row==1) return x[0][0]*MAT(_A);

        if(row==1&&col==1) return _A[0][0]*x;

        if(col!=x.row){

            cerr << "err Matrix::operator*" <<endl;

            cerr << "  not equal matrix size" <<endl;

            exit(0);

        }

        MAT r(row, x.col);

        REP(i,row) REP(j,x.col) REP(k,col) r[i][j]+=_A[i][k]*x[k][j];

        return r;

    }

    MAT operator/(MAT x)const{*this = *this * x.inverse(); return *this;}

    MAT operator/ (T a)const{

        MAT r(row,col);

        REP(i,row) REP(j,col) r[i][j]=_A[i][j]/a;

        return r;

    }

    MAT operator+= (MAT x) {*this = *this + x;return *this;}

    MAT operator-= (MAT x) {*this = *this - x; return *this;}

    MAT operator*=(T a){*this = a*(*this); return this;}

    MAT operator/=(MAT x){*this = *this/x;return *this;}

    MAT operator/=(T a){*this = *this/a; return *this;}

    friend MAT operator* (T n,MAT x){

        MAT r(x.row,x.col);

        REP(i,x.row) REP(j,x.col) r[i][j]=n*x[i][j];

        return r;

    }

    friend MAT operator* (MAT x,T n){

        MAT r(x.row,x.col);

        REP(i,x.row) REP(j,x.col) r[i][j]=n*x[i][j];

        return r;

    }

    explicit operator vector<vector<T>>(){return _A;}

    friend std::ostream &operator<<(std::ostream &os,const MAT &x){ REP(i,x.row) REP(j,x.col) os<<x._A[i][j]<<" \n"[j==x.col-1]; return os;}

    friend std::istream &operator>>(std::istream &is,MAT &x){REP(i,x.row) REP(j,x.col) is>>x._A[i][j];return is;}

    size_t size_row()const{return row;}

    size_t size_col()const{return col;}

    MAT transpose()const{

        MAT r(col,row);

        REP(i,col) REP(j,row) r[i][j]=_A[j][i];

        return r;

    }

    MAT inverse()const{

        T buf;

        MAT<T> inv_a(row,0);

        vector<vector<T>> a=_A;

        //row reduction

        REP(i,row){

            buf=1/a[i][i];

            REP(j,row){

                a[i][j]*=buf;

                inv_a[i][j]*=buf;

            }

            REP(j,row){

                if(i!=j){

                    buf=a[j][i];

                    REP(k,row){

                        a[j][k]-=a[i][k]*buf;

                        inv_a[j][k]-=inv_a[i][k]*buf;

                    }

                }

            }

        }

        return inv_a;

    }

    MAT Jacobi(MAT b)const{//ヤコビ法によって解を求める

        size_t sz=row;

        MAT D(sz,sz),inD(sz,sz),H(sz,sz),N(sz,sz);

        MAT c(sz,1),x(sz,1),tmp(sz,1);

        //cout<<"initialized"<<endl;

        REP(i,sz){//値の初期化、Aを対角要素とそれ以外に分解する(できてる)

            REP(j,sz){

                H[i][j] = 0;

                if(i==j){

                    D[i][j] = _A[i][j];

                    inD[i][j] = 1/_A[i][j];

                    N[i][j]=0;

                }

                else if(i!=j){

                    D[i][j] = 0;

                    inD[i][j] = 0;

                    N[i][j]=_A[i][j];

                }

            }

            c[i][0] = 0;

            x[i][0] = 1;

        }

        c=inD*b;

        H=inD*N;

        while(1){//反復法ステップ1→2→1...

            tmp=x;

            x=c-H*x;

            T r=T(0);

            for(int i=0;i<row;++i){

                r+=(x[i][0]-tmp[i][0])*(x[i][0]-tmp[i][0]);

            }

            if(r<eps) break;

        }

        return x;

    }

    MAT Gauss(MAT b)const{//ガウス・ザイデル法によって解を求める

        MAT<T> DL(row),U(row),inDL(row),H(row),c(row,1),x(row,1),tmp(row,1);

        for(int i=0;i<row;i++){

            for(int j=0;j<col;j++){

                H[i][j] = 0;

                if(i>=j){

                    DL[i][j] = _A[i][j];

                    U[i][j] = 0;

                }

                else{

                    DL[i][j] = 0;

                    U[i][j] = _A[i][j];

                }

            }

            x[i][0] = 1;

        }

        inDL=DL.inverse();

        c=inDL*b;

        H=inDL*U;

        int n=0;

        while(1){

            tmp=x;

            x=c-H*x;

            T r = T(0);

            for(int i=0;i<row;++i){

                r+=(x[i][0]-tmp[i][0])*(x[i][0]-tmp[i][0]);

            }

            n++;

            if(r<eps) break;

        }

        return x;

    }

    int rank()const{// O( n^3 )

        vector<vector<T>> A=_A;

        const int n = row, m = col;

        int r = 0;

        for(int i = 0; r < n && i < m; ++i) {

            int pivot = r;

            for(int j = r+1; j < n; ++j) if(fabs(A[j][i]) > fabs(A[pivot][i])) pivot = j;

            swap(A[pivot], A[r]);

            if(fabs(A[r][i]) < eps) continue;

            for (int k = m-1; k >= i; --k) A[r][k] /= A[r][i];

            rep(j,r+1,n) rep(k,i,m) A[j][k] -= A[r][k] * A[j][i];

            ++r;

        }

        return r;

    }

};

class UnionFind{

 private:

    vector<int> Parent,es;

    vector<ll> diff_weight;

 public:

    UnionFind(int N){

        es.resize(N,0);

        Parent.resize(N,-1);

        diff_weight.resize(N,0LL);

    }



    int root(int A){

        if(Parent[A]<0) return A;

        else{ 

            int r = root(Parent[A]);

            diff_weight[A] += diff_weight[Parent[A]]; // 累積和をとる

            return Parent[A]=r;

        }

    }

    bool issame(int A,int B){

        return root(A)==root(B);

    }

    ll weight(int x) {

        root(x); // 経路圧縮

        return diff_weight[x];

    }

    ll diff(int x, int y) {

        return weight(y) - weight(x);

    }

    int size(int A){

        return -Parent[root(A)];

    }

    int eize(int A){

        return es[root(A)];

    }

    bool connect(int A,int B){

        A=root(A); B=root(B);

        if(A==B) return false;

        if(size(A)<size(B)) std::swap(A,B);

        Parent[A]+=Parent[B];

        es[A]+=es[B]+1;

        Parent[B]=A;

        return true;

    }

    void unite(int A,int B){

        A=root(A); B=root(B);

        if(A==B){ 

            es[A]++;

            return;

        }

        if(size(A)<size(B)) std::swap(A,B);

        Parent[A]+=Parent[B];

        es[A]+=es[B]+1;

        Parent[B]=A;

        return;

    }

    bool merge(int A, int B, ll w) {

        // x と y それぞれについて、 root との重み差分を補正

        w += weight(A); w -= weight(B); 

        A=root(A); B=root(B);

        if(A==B) return false;

        if(size(A)<size(B)) std::swap(A,B),w=-w;

        Parent[A]+=Parent[B];

        Parent[B]=A;

        // x が y の親になるので、x と y の差分を diff_weight[y] に記録

        diff_weight[B] = w; 

        return true;

    }

};

class SOSU{

 private:

    vector<int> Prime_Number;

    vector<bool> isp;

 public:

    SOSU(int N){

        isp.resize(N+1,true);

        isp[0]=isp[1]=false;

        rep(i,2,N+1) if(isp[i]){

            Prime_Number.push_back(i);

            for(int j=2*i;j<=N;j+=i) isp[j]=false;

        }

    }

    int operator[](int i){return Prime_Number[i];}

    int size(){return Prime_Number.size();}

    int back(){return Prime_Number.back();}

    bool isPrime(int q){return isp[q];}

};

class Divisor{//素因数分解をしてから約数列挙、分解結果はＰ(底,指数)でpfacにまとめている

  private:

    vector<ll> F;

    vector<P> pfactorize;

  public:

    Divisor(ll N){

        for(ll i = 1; i * i <= N; i++) {

            if(N % i == 0) {

                F.push_back(i);

                if(i * i != N) F.push_back(N / i);

            }

        }

        sort(begin(F), end(F));

		SOSU p(Math::sqrt(N)+1);

    	REP(i,p.size()){

    		pfactorize.push_back(P(p[i],0));

    		while(N%p[i]==0){

    			N/=p[i];

    			pfactorize.back().second++;

    		}

            if(pfactorize.back().second==0) pfactorize.pop_back();

    	}

    	if(N>1) pfactorize.push_back(P(N,1));

    }

    int size(){return F.size();}

    vector<P> pfac(){return pfactorize;}

    ll operator[](int k){return F[k];}

};

struct compress{

    std::map<ll,int> zip;

    vector<ll> unzip;

    compress(vector<ll> x){

        unzip=x;

        sort(All(x));

        x.erase(unique(All(x)),x.end());

        REP(i,x.size()){

            zip[x[i]]=i;

        }

    }

    int operator[](int k){return zip[unzip[k]];}

};

struct edge{

    int from;int to;ll cost;

    void push(int a,int b,int c){

        from=a;to=b;cost=c;

    }

    bool operator<(const edge& y)const{

        if(cost!=y.cost) return cost<y.cost;

        else if(to!=y.to) return to<y.to;

        else return from<y.from;}

    bool operator>(const edge& y)const{

        if(cost!=y.cost) return cost>y.cost;

        else if(to!=y.to) return to>y.to;

        else return from>y.from;}

    bool operator==(const edge& y) const{return !(*this<y)&&!(*this>y);}

};

class lca {

  public:

    const int n = 0;

    const int log2_n = 0;

    std::vector<std::vector<int>> parent;

    std::vector<int> depth;



    lca() {}



    lca(const Graph &g, int root)

        : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {

        dfs(g, root, -1, 0);

        for (int k = 0; k + 1 < log2_n; k++) {

            for (int v = 0; v < (int)g.size(); v++) {

                if (parent[k][v] < 0)

                    parent[k + 1][v] = -1;

                else

                    parent[k + 1][v] = parent[k][parent[k][v]];

            }

        }

    }



    void dfs(const Graph &g, int v, int p, int d) {

        parent[0][v] = p;

        depth[v] = d;

        REP(j,g[v].size()) {

            if (g[v][j] != p) dfs(g, g[v][j], v, d + 1);

        }

    }



    int get(int u, int v) {

        if (depth[u] > depth[v]) std::swap(u, v);

        for (int k = 0; k < log2_n; k++) {

            if ((depth[v] - depth[u]) >> k & 1) {

                v = parent[k][v];

            }

        }

        if (u == v) return u;

        for (int k = log2_n - 1; k >= 0; k--) {

            if (parent[k][u] != parent[k][v]) {

                u = parent[k][u];

                v = parent[k][v];

            }

        }

        return parent[0][u];

    }

};

template<typename T> class SegmentTree{

  private:

    typedef std::function<T(T,T)> F;

    int n;

    T d0;

    vector<T> vertex;

    F f;

    F g;

  public:

    SegmentTree(F f,F g,T d):d0(d),f(f),g(g){}

    void init(int _n){

        n=1;

        while(n<_n) n*=2;

        vertex.resize(2*n-1,d0);

    }

    void build(const vector<T> &v){

        int n_=v.size();

        init(n_);

        for(int i=0;i<n_;i++) vertex[n+i-1]=v[i];

        for(int i=n-2;i>=0;i--)

        vertex[i]=f(vertex[2*i+1],vertex[2*i+2]);

    }

    void update(int i,T x){

        int k=i+n-1;

        vertex[k]=g(vertex[k],x);

        while(k>0){

            k=(k-1)/2;

            vertex[k]=f(vertex[2*k+1],vertex[2*k+2]);

        }

        return;

    }

    T query(int l,int r){

        T vl=d0,vr=d0;

        l+=n-1;

        r+=n-1;

        for(;l<=r;l/=2,r=r/2-1){

            if(l%2==0) vl=f(vl,vertex[l]);

            if(r&1) vr=f(vr,vertex[r]);

        }

        return f(vl,vr);

    }

};

template <typename T,typename E>

struct LazySegmentTree{

  using F = std::function<T(T,T)>;

  using G = std::function<T(T,E)>;

  using H = std::function<E(E,E)>;

  int n,height;

  F f;

  G g;

  H h;

  T ti;

  E ei;

  vector<T> dat;

  vector<E> laz;

  LazySegmentTree(F f,G g,H h,T ti,E ei):

    f(f),g(g),h(h),ti(ti),ei(ei){}



  void init(int n_){

    n=1;height=0;

    while(n<n_) n<<=1,height++;

    dat.assign(2*n,ti);

    laz.assign(2*n,ei);

  }



  void build(const vector<T> &v){

    int n_=v.size();

    init(n_);

    for(int i=0;i<n_;i++) dat[n+i]=v[i];

    for(int i=n-1;i;i--)

      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);

  }



  inline T reflect(int k){

    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);

  }



  inline void propagate(int k){

    if(laz[k]==ei) return;

    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);

    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);

    dat[k]=reflect(k);

    laz[k]=ei;

  }



  inline void thrust(int k){

    for(int i=height;i;i--) propagate(k>>i);

  }



  inline void recalc(int k){

    while(k>>=1)

      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));

  }



  void update(int a,int b,E x){

    thrust(a+=n);

    thrust(b+=n-1);

    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){

      if(l&1) laz[l]=h(laz[l],x),l++;

      if(r&1) --r,laz[r]=h(laz[r],x);

    }

    recalc(a);

    recalc(b);

  }



  void set_val(int a,T x){

    thrust(a+=n);

    dat[a]=x;laz[a]=ei;

    recalc(a);

  }



  T query(int a,int b){

    thrust(a+=n);

    thrust(b+=n-1);

    T vl=ti,vr=ti;

    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {

      if(l&1) vl=f(vl,reflect(l++));

      if(r&1) vr=f(reflect(--r),vr);

    }

    return f(vl,vr);

  }



  template<typename C>

  int find(int st,C &check,T &acc,int k,int l,int r){

    if(l+1==r){

      acc=f(acc,reflect(k));

      return check(acc)?k-n:-1;

    }

    propagate(k);

    int m=(l+r)>>1;

    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);

    if(st<=l&&!check(f(acc,dat[k]))){

      acc=f(acc,dat[k]);

      return -1;

    }

    int vl=find(st,check,acc,(k<<1)|0,l,m);

    if(~vl) return vl;

    return find(st,check,acc,(k<<1)|1,m,r);

  }



  template<typename C>

  int find(int st,C &check){

    T acc=ti;

    return find(st,check,acc,1,0,n);

  }

};

struct rational {

  ll p, q;

  void normalize() { // keep q positive

    if (q < 0) p *= -1, q *= -1;

    ll d = Math::gcd(p < 0 ? -p : p, q);

    if (d == 0) p = 0,  q = 1;

    else        p /= d, q /= d;

  }

  rational(ll p, ll q = 1) : p(p), q(q) {

    normalize();

  }

  rational &operator+=(const rational &a){p = a.q * p + a.p * q; q = a.q * q; normalize();return *this;}

  rational &operator-=(const rational &a){p = a.q * p - a.p * q; q = a.q * q; normalize();return *this;}

  rational &operator*=(const rational &a){p *= a.p; q *= a.q;normalize();return *this;}

  rational &operator/=(const rational &a){p *= a.q; q *= a.p; normalize();return *this;}

  rational &operator-(){p *= -1;return *this;}

  friend rational operator+(const rational &a, const rational &b){return rational(a) += b;}

  friend rational operator*(const rational &a, const rational &b){return rational(a) *= b;}

  friend rational operator-(const rational &a, const rational &b){return rational(a)-=b;}

  friend rational operator/(const rational &a, const rational &b){return rational(a) /= b;}

  friend bool operator<(const rational &a, const rational &b){ // avoid overflow 

    return (long double) a.p * b.q < (long double) a.q * b.p;

  }

  friend bool operator<=(const rational &a, const rational &b){return !(b < a);}

  friend bool operator>(const rational &a, const rational &b){return b < a;}

  friend bool operator>=(const rational &a, const rational &b){return !(a < b);}

  friend bool operator==(const rational &a, const rational &b){return !(a < b) && !(b < a);}

  friend bool operator!=(const rational &a, const rational &b){return (a < b) || (b < a);}

  friend std::ostream& operator<<(std::ostream &os, const rational &x){ printf("%.16f",(double)x.p/(double)x.q); return os; }

  friend std::istream& operator>>(std::istream &is, rational &x){is>>x.p>>x.q; x.normalize(); return is;}

};

template<typename T>

class FFT{

  private:

    using Complex = std::complex<double>;

    std::vector<Complex> C;

    void DFT(std::vector<Complex> &F,int n,int sig=1){

        if(n==1) return;

        std::vector<Complex> f0(n/2),f1(n/2);

        for(int i=0;i<n/2;++i){

            f0[i]=F[2*i];

            f1[i]=F[2*i+1];

        }

        DFT(f0,n/2,sig);

        DFT(f1,n/2,sig);

        Complex z(cos(2.0*PI/n),sin(2.0*PI/n)*sig),zi=1;

        for(int i=0;i<n;++i){

            if(i<n/2) F[i]=f0[i]+zi*f1[i];

            else F[i]=f0[i-n/2]+zi*f1[i-n/2];

            zi*=z;

        }

        return;

    }

    void invDFT(std::vector<Complex> &f,int n){

        DFT(f,n,-1);

        for(int i=0;i<n;++i){

            f[i]/=n;

        }

        return;

    }

  public:

    FFT(const std::vector<T> &A,const std::vector<T> &B){

        int n=1;

        while(n<=A.size()+B.size()){

            n*=2;

        }

        std::vector<Complex> g(n,Complex(0));

        C.resize(n,Complex(0));

        int i_len=std::max(A.size(),B.size());

        for(int i=0;i<i_len;++i){

            if(i<A.size()) C[i]=Complex(A[i]);

            if(i<B.size()) g[i]=Complex(B[i]);

        }

        DFT(C,n);

        DFT(g,n);

        for(int i=0;i<n;++i) C[i]=C[i]*g[i];

        invDFT(C,n);

        for(int i=0;i<n;++i) if(T(C[i].real())!=C[i].real()){

            C[i]=Complex(C[i].real()+0.5);

        }

    }

    T operator[](int k)const{return T(C[k].real());}

};



int main(){

    cin.tie(nullptr);

    std::ios::sync_with_stdio(false);

    solve();

    return 0;

}





void solve(){

    int N;

    long long M;

    std::cin>>N>>M;

    std::vector<int> A(N);

    int MAX_A=0;

    for(int i=0;i<N;++i){

        std::cin>>A[i];

        MAX_A=std::max(MAX_A,A[i]);

    }

    std::vector<long long> cnt(MAX_A+1);

    for(int i=0;i<N;++i){

        cnt[A[i]]++;

    }

    FFT<long long> C(cnt,cnt);

    long long ans=0;

    for(int i=2*MAX_A;i>=0;--i){

        if(M>=C[i]){

            ans+=i*C[i];

            M-=C[i];

        }else{

            ans+=i*M;

            break;

        }

    }

    std::cout<<ans<<std::endl;

}