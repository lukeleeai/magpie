/*

 * じょえチャンネル

 * 高評価・チャンネル登録よろしくおねがいします！

 * https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ

 */



#include <algorithm>

#include <bitset>

#include <cassert>

#include <cfloat>

#include <climits>

#include <cmath>

#include <complex>

#include <ctime>

#include <deque>

#include <fstream>

#include <functional>

#include <iomanip>

#include <iostream>

#include <iterator>

#include <list>

#include <map>

#include <memory>

#include <queue>

#include <random>

#include <set>

#include <stack>

#include <string>

#include <string.h>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <vector>



//#pragma GCC target("avx2")

//#pragma GCC optimize("O3")

//#pragma GCC optimize("unroll-loops")









//here!!!

// define int long long !!!!!



#define int long long



// define int long long !!!!!





#define mod 1000000007ll

//constexpr int mod = 998244353ll;



constexpr double PI=3.141592653589793238462643383279;

//constexpr double eps = DBL_EPSILON;



typedef long long ll;



#ifdef int

#define inf (int)(3e18)

#else

#define inf (int)(5e8)

#endif



#define intt long long

#define itn long long

#define innt long long

#define P pair<long long,long long>



#define rep(i,n) for(int i=0;i<n;i++)

#define REP(i,n) for(int i=1;i<=n;i++)

#define rev_rep(i,n) for(int i=n-1;i>=0;i--)

#define REV_REP(i,n) for(int i=n;i>=1;i--)



#define ALL(v) v.begin(),v.end()



#define smallpriority_queue(T) priority_queue<T,vector<T>,greater<T>>





using namespace std;



//Library

//モッドパウ

inline int modpow(int x, int y, int m = mod) {

    int res = 1;

    while (y) {

        if (y & 1) {

            res *= x;

            res %= m;

        }

        x = x * x % m;

        y /= 2;

    }

    return res;

}



int mypow(int x, int y) {

    int res = 1;

    while (y) {

        if (y % 2) {

            res *= x;

        }

        x = x * x;

        y /= 2;

    }

    return res;

}

//is the number (x) a prime number?

//bool prime(int x) {

//    if (!x || x == 1) {

//        return false;

//    }

//    for (int i = 2; i * i <= x; i++) {

//        if (!(x % i)) {

//            return false;

//        }

//    }

//    return true;

//}

bool prime(int x) {

    if (!x || x == 1) {

        return false;

    }

    if(x == 2){

        return true;

    }

    if(!(x & 1)){

        return false;

    }

    for (int i = 3; i * i <= x; i+=2) {

        if (!(x % i)) {

            return false;

        }

    }

    return true;

}





//saidai-kouyakusuu

inline int gcd(int x, int y) {

    if (!y) {

        return x;

    }

    return gcd(y, x % y);

}





//number of keta

int keta(int x) {

    int ans = 0;

    while (x) {

        x /= 10;

        ans++;

    }

    return ans;

}



//number of 2shinsuu keta

int bitketa(int x) {

    int ans = 0;

    while (x) {

        x >>= 1;

        ans++;

    }

    return ans;

}



//sum of keta

int ketasum(int x) {

    int ans = 0;

    while (x) {

        ans += x % 10;

        x /= 10;

    }

    return ans;

}



inline int lcm(int x, int y) {

    int ans = x / gcd(x, y) * y;

    return ans;

}

int twobeki(int x) {

    int ans = 0;

    while (1) {

        if (!(x & 1)) {

            ans++;

            x >>= 1;

        }

        else {

            break;

        }

    }

    return ans;

}





template <class T, class U>

inline bool chmax(T& lhs, const U& rhs) {

    if (lhs < rhs) {

        lhs = rhs;

        return 1;

    }

    return 0;

}

template <class T, class U>

inline bool chmin(T& lhs, const U& rhs) {

    if (lhs > rhs) {

        lhs = rhs;

        return 1;

    }

    return 0;

}

void Yes(){

    cout<<"Yes"<<endl;

}

void No(){

    cout<<"No"<<endl;

}

void YES(){

    cout<<"YES"<<endl;

}

void NO(){

    cout<<"NO"<<endl;

}





#define fin(i) scanf("%lld",&i)

#define fout(i) printf("%lld",i)

#define fendl printf("\n")



int kai(int x, int y) {

    int res = 1;

    for (int i = x - y + 1; i <= x; i++) {

        res *= i; res %= mod;

    }

    return res;

}



int comb(int x, int y) {

    if (y > x)return 0;

    //    cout<<kai(x, y)<<' '<<modpow(kai(y, y), mod - 2)<<endl;

    return kai(x, y) * modpow(kai(y, y), mod - 2) % mod;

}

//Library-End



//入出力高速化時にはoff！！！！

//#define vecin(v) for(int i=0;i<v.size();i++)scanf("%lld",&v[i]);

//#define vecout(v) {if(v.size())printf("%lld",v[0]);for(int i=1;i<(int)v.size();i++)printf(" %lld",v[i]);printf("\n");}







template <class T>

class SegTree {

    int n,ookisa;

    vector<T> node;

    T def;

    function<T(T,T)> operation;

    function<T(T,T)> update;

    

public:

    SegTree(unsigned int _n, T _def, function<T(T, T)> _operation,

            function<T(T, T)> _update)

    : def(_def), operation(_operation), update(_update) {

        ookisa=n;

        n=1;

        while

            (n < _n) {

            n *= 2;

        }

        node = vector<T>(n * 2, def);

    }

    SegTree(vector<int>& initvec,T _def, function<T(T, T)> _operation,

            function<T(T, T)> _update)

    :  def(_def), operation(_operation), update(_update) {

        ookisa=initvec.size();

        n=1;

        while (n < initvec.size()) {

            n *= 2;

        }

        node = vector<T>(n * 2, def);

        for(int i=n;i<n+initvec.size();i++){

            node[i]=initvec[i-n];

        }

        for(int i=n-1;i>=1;i--){

            node[i]=operation(node[i*2],node[i*2+1]);

        }

        

        

    }

    void change(int i,T x){

        i+=n;

        node[i]=update(node[i],x);

        while (i>=1) {

            i>>=1;

            node[i]=operation(node[i*2],node[i*2+1]);

        }

    }

    T query(int l, int r){

        l+=n;

        r+=n;

        T rx=def,lx=def;

        while(l<r){

            if (l&1) {

                lx=operation(lx,node[l]);

                l++;

            }

            if (r&1) {

                r--;

                rx=operation(node[r],rx);

            }

            l>>=1; r>>=1;

        }

        return operation(lx,rx);

    }

    T operator [] (const int& x){

        return node[x+n];

    }

    void fill(T x) {

        std::fill(ALL(node), x);

    }

    void print() {

        rep(i, ookisa)std::cout << operator[](i) << " ";

        std::cout << std::endl;

    }

    T queryForALL(){

        return node[1];

    }

};



#define R_MIN ([](long long a, long long b) { return min(a, b); })

#define R_MAX ([](long long a, long long b) { return max(a, b); })

#define R_SUM ([](long long a, long long b) { return a + b; })



#define NORMAL_UPDATE ([](long long a, long long b) { return b; })

#define ADD_UPDATE ([](long long a, long long b) { return a + b; })

#define MINUS_UPDATE ([](long long a, long long b) { return a - b; }



class Union_Find {

    vector<int> par;

    vector<int> ookisa;

    

public:

    Union_Find(int size) {

        par = vector<int>(size);

        ookisa=vector<int>(size);

        for (int i = 0; i < size; i++) {

            par[i] = i;

            ookisa[i]=1;

        }

    }

    

    int find(int x) {

        if (par[x] == x) {

            return x;

        }

        return par[x] = find(par[x]);

    }

    

    void unite(int x, int y) {

        x = find(x);

        y = find(y);

        if (x == y) {

            return;

        }

        if (ookisa[x] < ookisa[y]) {

            par[x] = y;

            ookisa[y]+=ookisa[x];

            ookisa[x]=0;

        }

        else {

            par[y] = x;

            ookisa[x]+=ookisa[y];

            ookisa[y]=0;

        }

    }

    int size(int i){

        i=find(i);

        return ookisa[i];

    }

    bool same(int x, int y){

        return find(x) == find(y);

    }

    

};



class BIT {

    vector<int> data;

    int size=0;

public:

    BIT(int _size){

        data=vector<int>(_size+1);

        size=_size;

    }

    void add(int i,int x){

        while (i<=size) {

            data[i]+=x;

            i += i & -i;

        }

    }

    int sum(int i){

        assert(i<=size);

        int s=0;

        while(i>0){

            s+=data[i];

            i -= i & -i;

        }

        return s;

    }

    int lower_bound(int x){

        if(x<=0){

            return 0;

        }else{

            int i=0;int r=1;

            while(r<size) r=r<<1;

            for(int len=r;len>0;len=len>>1) {

                if(i+len<size && data[i+len]<x){

                    x-=data[i+len];

                    i+=len;

                }

            }

            return i+1;

        }

    }

};



//Union-Find-End



int perm[2000005];

void init_perm() {

    perm[0] = 1;

    REP(i, 2000004) {

        perm[i] = perm[i - 1] * i % mod;

    }

}



int nCk(int x, int y) {

    if (y>x) {

        return 0;

    }

    if (x<0) {

        return 0;

    }

    return perm[x] * modpow(perm[x - y], mod - 2) % mod * modpow(perm[y], mod - 2) % mod;

}



struct Dot {

    double x;

    double y;

    Dot(double _x=0.0, double _y=0.0){

        x=_x;

        y=_y;

    }

};



struct Dot_i {

    int x;

    int y;

    Dot_i(int _x=0, int _y=0){

        x=_x;

        y=_y;

    }

};



double kyori(pair<int, int> f, pair<int, int> s) {

    double ans = 0;

    double t = fabs(f.first - s.first);

    double y = fabs(f.second - s.second);

    ans = sqrt(t * t + y * y);

    return ans;

}



double kyori(Dot f, Dot s) {

    double ans = 0;

    double t = fabs(f.x - s.x);

    double y = fabs(f.y - s.y);

    ans = sqrt(t * t + y * y);

    return ans;

}



inline string stringmax(string& x,string& y){

    if (x.size()>y.size()) {

        return x;

    }

    if (x.size()<y.size()) {

        return y;

    }

    rep(i,x.size()){

        if (x[i]>y[i]) {

            return x;

        }

        if (x[i]<y[i]) {

            return y;

        }

    }

    return x;

}



vector<int>  RollingHash(string &s, string& t){

    vector<int> ans;

    if(s.size()<t.size())return ans;

    __int128 h=0,hamod=0,ki=0,kim=0,hikaku=0,one=0;

    one=1;

    ki=1000000007ll;

    hamod=(one<<61)-1;

    kim=1;

    rep(i,t.size()){

        hikaku*=ki;

        h*=ki;

        kim*=ki;

        hikaku+=t[i];

        h+=s[i];

        hikaku%=hamod;

        h%=hamod;

        kim%=hamod;

    }

    rep(i,(int)s.size()-(int)t.size()){

        if (h==hikaku) {

            ans.emplace_back(i);

        }

        h*=ki;

        h%=hamod;

        h+=s[i+(int)t.size()];

        h%=hamod;

        h+=hamod;

        h-=s[i]*kim%hamod;

        h%=hamod;

    }

    if(h==hikaku)ans.emplace_back((int)s.size()-(int)t.size());

    return ans;

}



int myhash(string &t){

    __int128 hamod=0,ki=0,ans=0,one=0;

    one=1;

    ki=1000000007ll;

    hamod=(one<<61)-1;

    rep(i,t.size()){

        ans*=ki;

        ans+=t[i];

        ans%=hamod;

    }

    int ta=ans;

    return ta;

}

struct edge {

    int to;

    int length;

    edge(int _to, int _length){

        to=_to;

        length=_length;

    }

};

vector<int> djkstra(vector<vector<edge>> &road,int start){

    vector<int> kyo(road.size(),inf);

    smallpriority_queue(P) q;

    q.push({0,start});

    kyo[start]=0;

    while (q.size()) {

        int x=q.top().second;

        itn now=q.top().first;

        q.pop();

        if (kyo[x]<now) {

            continue;

        }

        for(auto&i:road[x]){

            if (kyo[i.to]>now+i.length) {

                kyo[i.to]=now+i.length;

                q.push({kyo[i.to],i.to});

            }

        }

    }

    return kyo;

}



template <class T>

void change_to_unique(vector<T> &v){

    std::sort(ALL(v));

    auto k=unique(ALL(v));

    if(k!=v.end())v.erase(k,v.end());

}



double kodo_dosuu(double r){

    return 180.0*r/(double)PI;

}



double dosuu_kodo(double r){

    return r*(double)PI/180.0;

}



double kakudo(Dot a,Dot b1,Dot b2){

    double size1=kyori(a,b1),size2=kyori(a,b2);

    double nai=(b1.x-a.x)*(b2.x-a.x)+(b1.y-a.y)*(b2.y-a.y);

    nai/=size1*size2;

    return kodo_dosuu(acos(nai));

}



struct fraction {

    int shi;

    int bo;

    fraction(int bunshi,int bunbo):bo(bunbo),shi(bunshi){

        if(bunbo&&bunshi){

            int g=gcd(bo, shi);

            bo/=g;

            shi/=g;

        }

    };

    explicit inline operator double()const { return (double)shi/(double)bo; }

    explicit inline operator long double()const { return (long double)shi/(long double)bo; }

};

bool operator < (const fraction& b1, const fraction& b2){

    return b1.shi*b2.bo < b2.shi*b1.bo;

}

bool operator > (const fraction& b1, const fraction& b2){

    return b1.shi*b2.bo > b2.shi*b1.bo;

}



template <class T>

void vecout(vector<T> &v){

    if (v.size()) {

        cout<<v[0];

    }

    REP(i,(int)v.size()-1){

        cout<<' '<<v[i];

    }

    cout<<endl;

}



#define endl "\n" //interactive の時に注意！！！

#define Endl "\n" //interactive の時に注意！！！

#define cinn cin

#define printd cout<<fixed<<setprecision(10)

#define rrep(i,f,s) for(int i=f;i<s;i++)

#define RREP(i,f,s) for(int i=f;i<=s;i++)

#define REV_RREP(i,f,s) for(int i=s;i>=f;i--)

#define hen_rep(i,l,step) for(int i=0;i<l;i+=step)

#define HEN_REP(i,l,step) for(int i=1;i<=l;i+=step)





int n,ans,k,rui[200004];

vector<int> a;

bool did,f;

signed main() {

    ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    cin>>n>>k;

    

    rep(i,n){

        int k;

        cin>>k;

        a.emplace_back(k);

        if(i)if(a[i-1]>a[i])rui[i]++;

    }

    rep(i,n){

        rui[i+1]+=rui[i];

    }

    SegTree<int> small(a,inf, R_MIN, NORMAL_UPDATE);

    SegTree<int> big(a, -inf, R_MAX, NORMAL_UPDATE);

    ans=1;

    f=!(rui[k-1]-rui[0]);

    rep(i,n-k){

        if (!(rui[i+k]-rui[i+1])) {

            did=1;

            continue;

        }

        if(a[i]==small.query(i, i+k+1)&&a[i+k]==big.query(i, i+k+1)){

            continue;

        }

        ans++;

    }

    if(!f&&did)ans++;

    cout<<ans<<endl;

}

 








