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









//here!!!

// define int long long !!!!!



#define int long long



// define int long long !!!!!





#define mod (int)((1e9)+7)

//constexpr int mod = 998244353ll;





#ifdef int

#define inf (int)(3e18)

#else

#define inf (int)(5e8)

#endif



#define intt long long

#define itn long long

#define P pair<long long,long long>



#define rep(i,n) for(int i=0;i<n;i++)

#define REP(i,n) for(int i=1;i<=n;i++)



#define ALL(v) v.begin(),v.end()



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





template<typename T, typename U>

class SegTree {

protected:

    unsigned int n = 1, rank = 0;

    std::vector<T> node;

    T nodee;

    virtual T nodef(const T&, const T&)const = 0;

public:

    SegTree(unsigned int m, T init, T nodee):nodee(nodee) {

        while (n < m) {

            n *= 2;

            rank++;

        }

        node.resize(2 * n);

        for (unsigned int i = n; i < 2 * n; i++)node[i] = init;

    }

    SegTree(const std::vector<T>& initvec, T nodee):nodee(nodee) {

        unsigned int m = initvec.size();

        while (n < m) {

            n *= 2;

            rank++;

        }

        node.resize(2 * n);

        for (unsigned int i = n; i < 2 * n; i++) {

            if (i - n < m)node[i] = initvec[i - n];

        }

    }

    virtual void update(int i, U x) {

        i += n;

        node[i] = x;

        while (i != 1) {

            i >>= 1;

            node[i] = nodef(node[2 * i], node[2 * i + 1]);

        }

    }

    virtual T query(int l, int r) {

        l += n; r += n;

        int ls = nodee, rs = nodee;

        while (l < r) {

            if (l & 1) {

                ls = nodef(ls, node[l]);

                l++;

            }

            if (r & 1) {

                r--;

                rs = nodef(node[r], rs);

            }

            l >>= 1; r >>= 1;

        }

        return nodef(ls, rs);

    }

    virtual T operator[](const int& x) {

        return node[n + x];

    }

    void fill(T x) {

        std::fill(all(node), x);

    }

    void print() {

        rep(i, n)std::cout << operator[](i) << " ";

        std::cout << std::endl;

    }

};

class RSQ :public SegTree<int, int> {

    int nodef(const int& lhs,const int& rhs){return lhs+rhs;}

public:

    RSQ(int size, const int& def = 0) :SegTree<int, int>(size, def, 0) {}

    RSQ(const std::vector<int>& initvec) :SegTree<int, int>(initvec, 0) {}

};

class RMiQ :public SegTree<int, int> {

    int nodef(const int& lhs,const int& rhs){return std::min(lhs,rhs);}

public:

    RMiQ(int size, const int& def = 0) :SegTree<int, int>(size, def, 0) {}

    RMiQ(const std::vector<int>& initvec) :SegTree<int, int>(initvec, 0) {}

};

class RMaQ :public SegTree<int, int> {

    int nodef(const int& lhs,const int& rhs){return std::max(lhs,rhs);}

public:

    RMaQ(int size, const int& def = 0) :SegTree<int, int>(size, def, 0) {}

    RMaQ(const std::vector<int>& initvec) :SegTree<int, int>(initvec, 0) {}

};

template<typename T, typename U>

class IntervalSegTree :public SegTree<T, U> {

protected:

    using SegTree<T, U>::n;

    using SegTree<T, U>::rank;

    using SegTree<T, U>::node;

    using SegTree<T, U>::nodef;

    using SegTree<T, U>::nodee;

    std::vector<U> lazy;

    std::vector<bool> lazyflag;

    std::vector<int> width;

    virtual void lazyf(U&, const U&) = 0;

    virtual void updf(T&, const U&, const unsigned int&) = 0;

    void eval(int k) {

        for (int i = rank; i > 0; i--) {

            int nk = k >> i;

            if (lazyflag[nk]) {

                updf(node[2 * nk], lazy[nk], width[2 * nk]);

                updf(node[2 * nk + 1], lazy[nk], width[2 * nk + 1]);

                if (lazyflag[2 * nk])lazyf(lazy[2 * nk], lazy[nk]);

                else lazy[2 * nk] = lazy[nk];

                if (lazyflag[2 * nk + 1])lazyf(lazy[2 * nk + 1], lazy[nk]);

                else lazy[2 * nk + 1] = lazy[nk];

                lazyflag[2 * nk] = lazyflag[2 * nk + 1] = true;

                lazyflag[nk] = false;

            }

        }

    }

public:

    IntervalSegTree(unsigned int m, T init, T nodee) :SegTree<T, U>(m, init, nodee) {

        lazy.resize(2 * n); lazyflag.resize(2 * n); width.resize(2 * n);

        width[1] = n;

        for (unsigned int i = 2; i < 2 * n; i++) {

            width[i] = width[i >> 1] >> 1;

        }

    }

    IntervalSegTree(T nodee, const std::vector<T>& initvec) :SegTree<T, U>(initvec, nodee) {

        lazy.resize(2 * n); lazyflag.resize(2 * n); width.resize(2 * n);

        width[1] = n;

        for (unsigned int i = 2; i < 2 * n; i++) {

            width[i] = width[i >> 1] >> 1;

        }

    }

    void update(int i, U x) {

        i += n;

        eval(i);

        updf(node[i], x, width[i]);

        if (lazyflag[i])lazyf(lazy[i], x);

        else {

            lazyflag[i] = true;

            lazy[i] = x;

        }

        while (i /= 2)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

    void update(int l, int r, U x) {

        l += n; r += n;

        int nl = l, nr = r;

        while (!(nl & 1))nl >>= 1;

        while (!(nr & 1))nr >>= 1;

        nr--;

        eval(nl); eval(nr);

        while (l < r) {

            if (l & 1) {

                updf(node[l], x, width[l]);

                if (lazyflag[l])lazyf(lazy[l], x);

                else {

                    lazyflag[l] = true;

                    lazy[l] = x;

                }

                l++;

            }

            if (r & 1) {

                r--;

                updf(node[r], x, width[r]);

                if (lazyflag[r])lazyf(lazy[r], x);

                else {

                    lazyflag[r] = true;

                    lazy[r] = x;

                }

            }

            l >>= 1; r >>= 1;

        }

        while (nl >>= 1)node[nl] = nodef(node[2 * nl], node[2 * nl + 1]);

        while (nr >>= 1)node[nr] = nodef(node[2 * nr], node[2 * nr + 1]);

    }

    T query(int l, int r) {

        l += n; r += n;

        eval(l); eval(r - 1);

        int ls = nodee, rs = nodee;

        while (l < r) {

            if (l & 1) {

                ls = nodef(ls, node[l]);

                l++;

            }

            if (r & 1) {

                r--;

                rs = nodef(node[r], rs);

            }

            l >>= 1; r >>= 1;

        }

        return nodef(ls, rs);

    }

    T operator[](const int& x) {

        eval(n + x);

        return node[n + x];

    }

    T queryForAll() {

        return node[1];

    }

};

class RAQRSQ :public IntervalSegTree<int, int> {

    int nodef(const int& a, const int& b)const { return a + b; }

    void lazyf(int& a, const int& b) { a += b; }

    void updf(int& a, const int& b, const unsigned int& width) { a += width * b; }

public:

    RAQRSQ(int size, const int& def = 0) :IntervalSegTree<int, int>(size, def, 0) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

    RAQRSQ(const std::vector<int>& initvec) :IntervalSegTree<int, int>((int)0, initvec) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

};

class RAQRMiQ :public IntervalSegTree<int, int> {

    int nodef(const int& a, const int& b)const { return std::min(a, b); }

    void lazyf(int& a, const int& b) { a += b; }

    void updf(int& a, const int& b, const unsigned int& width) { a += b; }

public:

    RAQRMiQ(int size, const int& def = 0) :IntervalSegTree<int, int>(size, def, inf) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

    RAQRMiQ(const std::vector<int>& initvec) :IntervalSegTree<int, int>(inf, initvec) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

};

class RAQRMaQ :public IntervalSegTree<int, int> {

    int nodef(const int& a, const int& b)const { return std::max(a, b); }

    void lazyf(int& a, const int& b) { a += b; }

    void updf(int& a, const int& b, const unsigned int& width) { a += b; }

public:

    RAQRMaQ(unsigned int size, const int& def = 0) :IntervalSegTree<int, int>(size, def, -inf) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

    RAQRMaQ(const std::vector<int>& initvec) :IntervalSegTree<int, int>(-inf, initvec) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

};

class RUQRSQ :public IntervalSegTree<int, int> {

    int nodef(const int& a, const int& b)const { return a + b; }

    void lazyf(int& a, const int& b) { a = b; }

    void updf(int& a, const int& b, const unsigned int& width) { a = width * b; }

public:

    RUQRSQ(int size, const int& def = 0) :IntervalSegTree<int, int>(size, def, 0) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

    RUQRSQ(const std::vector<int>& initvec) :IntervalSegTree<int, int>((int)0, initvec) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

};

class RUQRMiQ :public IntervalSegTree<int, int> {

    int nodef(const int& a, const int& b)const { return std::min(a, b); }

    void lazyf(int& a, const int& b) { a = b; }

    void updf(int& a, const int& b, const unsigned int& width) { a = b; }

public:

    RUQRMiQ(int size, const int& def = 0) :IntervalSegTree<int, int>(size, def, inf) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

    RUQRMiQ(const std::vector<int>& initvec) :IntervalSegTree<int, int>(inf, initvec) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

};

class RUQRMaQ :public IntervalSegTree<int, int> {

    int nodef(const int& a, const int& b)const { return std::max(a, b); }

    void lazyf(int& a, const int& b) { a = b; }

    void updf(int& a, const int& b, const unsigned int& width) { a = b; }

public:

    RUQRMaQ(int size, const int& def = 0) :IntervalSegTree<int, int>(size, def, -inf) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

    }

    RUQRMaQ(const std::vector<int>& initvec) :IntervalSegTree<int, int>(-inf, initvec) {

        for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);

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



#define endl "\n" //interactive の時に注意！！！

#define printd cout<<fixed<<setprecision(10)



int n,m,a[100004],b[100004],ans;

vector<P> v;

signed main(){

    ios::sync_with_stdio(false);

    std::cin.tie(nullptr);

    cin>>n>>m;

    

    rep(i,n){

        cin>>a[i]>>b[i];

        v.emplace_back(a[i],b[i]);

    }

    sort(ALL(v),greater<P>());

    while (m) {

        int s=min(m,v.back().second);

        m-=s;

        ans+=s*v.back().first;

        v.pop_back();

    }

    cout<<ans<<endl;

}












