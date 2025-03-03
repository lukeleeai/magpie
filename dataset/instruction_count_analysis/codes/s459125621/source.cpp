/*

 * じょえチャンネル

 * 高評価・チャンネル登録よろしくおねがいします！

 * https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ

 */



#include "stdc++.h"



//#pragma GCC target("avx2")

//#pragma GCC optimize("O3")

//#pragma GCC optimize("unroll-loops")



#define f(i,n) for(int i=0;i<(n);i++)





#define inf (int)(3e18)



//here!!!

// define int long long !!!!!



#define int long long



// define int long long !!!!!





#define mod (int)((1e9)+7)

//constexpr int mod = 998244353ll;



#define intt long long

#define itn long long

#define P pair<int,int>



#define rep(i,n) for(int i=0;i<n;i++)

#define REP(i,n) for(int i=1;i<=n;i++)



#define ALL(v) v.begin(),v.end()



using namespace std;



//Library

//モッドパウ

inline int modpow(int x, int y, int m = mod) {

    int res = 1;

    while (y) {

        if (y % 2) {

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

bool prime(int x) {

    for (int i = 2; i * i <= x; i++) {

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

            x /= 2;

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





#define vecin(v) for(int i=0;i<v.size();i++)scanf("%lld",&v[i]);

#define vecout(v) {for(int i=0;i<(int)v.size();i++)printf("%lld ",v[i]);printf("\n");}



//SegTree

template <class T>

class SegTree {

    int n;                       // 葉の数

    vector<T> data;              // データを格納するvector

    T def;                       // 初期値かつ単位元

    function<T(T, T)> operation; // 区間クエリで使う処理

    function<T(T, T)> update;    // 点更新で使う処理

    

    // 区間[a,b)の総和。ノードk=[l,r)に着目している。

    T _query(int a, int b, int k, int l, int r) {

        if (r <= a || b <= l) return def; // 交差しない

        if (a <= l && r <= b)

            return data[k]; // a,l,r,bの順で完全に含まれる

        else {

            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子

            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子

            return operation(c1, c2);

        }

    }

    

public:

    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,

    // _update:更新関数

    SegTree(size_t _n, T _def, function<T(T, T)> _operation,

            function<T(T, T)> _update)

    : def(_def), operation(_operation), update(_update) {

        n = 1;

        while (n < _n) {

            n *= 2;

        }

        data = vector<T>(2 * n - 1, def);

    }

    

    // 場所i(0-indexed)の値をxで更新

    void change(int i, T x) {

        i += n - 1;

        data[i] = update(data[i], x);

        while (i > 0) {

            i = (i - 1) / 2;

            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);

        }

    }

    

    // [a, b)の区間クエリを実行

    T query(int a, int b) {

        return _query(a, b, 0, 0, n);

    }

    

    // 添字でアクセス

    T operator[](int i) {

        return data[i + n - 1];

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

    vector<int> rankmy;

    vector<int> ookisa;

    

public:

    Union_Find(int size) {

        par = vector<int>(size);

        rankmy = vector<int>(size);

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

        if (rankmy[x] < rankmy[y]) {

            par[x] = y;

            ookisa[y]+=ookisa[x];

            ookisa[x]=0;

        }

        else {

            par[y] = x;

            ookisa[x]+=ookisa[y];

            ookisa[y]=0;

            if (rankmy[x] == rankmy[y]) {

                rankmy[x]++;

            }

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



//Union-Find-End

#define endl "\n" //interactive の時に注意！！！

int perm[1000005];

void init_perm() {

    perm[0] = 1;

    REP(i, 1000000) {

        perm[i] = perm[i - 1] * i % mod;

    }

}



int nCk(int x, int y) {

    return perm[x] * modpow(perm[x - y], mod - 2) % mod * modpow(perm[y], mod - 2) % mod;

}



double kyori(pair<int, int> f, pair<int, int> s) {

    double ans = 0;

    double t = fabs(f.first - s.first);

    double y = fabs(f.second - s.second);

    ans = sqrt(t * t + y * y);

    return ans;

}





int a,b,c,ans;

signed main() {

    ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    cin>>a>>b>>c;

    ans=inf;

    rep(i,a+1){

        rep(j,b+1){

            if (i*b+j*a-i*j>=c) {

                chmin(ans, i+j);

            }

        }

    }

    cout<<ans<<endl;

}










