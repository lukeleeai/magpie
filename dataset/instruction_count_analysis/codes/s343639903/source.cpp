#include "stdc++.h"





#define f(i,n) for(int i=0;i<(n);i++)





#define inf (int)(3e18)

#define int long long

#define mod (int)(1000000007)



#define intt long long

#define P pair<int,int>



using namespace std;



//Library

//モッドパウ

int modpow(int x, int y, int m = mod) {

    int res = 1;

    while (y) {

        if (y % 2) {

            res *= x;

            res %= m;

        }

        x = x * x % mod;

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



double kyori(pair<int, int> f, pair<int, int> s) {

    double ans = 0;

    double t = fabs(f.first - s.first);

    double y = fabs(f.second - s.second);

    ans = sqrt(t * t + y * y);

    return ans;

}



//saidai-kouyakusuu

inline int gcd(int x, int y) {

    if (!y) {

        return x;

    }

    return gcd(y, x % y);

}



//Union-Find Tree



class Union_Find {

    vector<int> par;

    vector<int> rankmy;

public:

    Union_Find(int size) {

        par = vector<int>(size);

        rankmy = vector<int>(size);

        for (int i = 0; i < size; i++) {

            par[i] = i;

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

        }

        else {

            par[y] = x;

            if (rankmy[x] == rankmy[y]) {

                rankmy[x]++;

            }

        }

    }



    bool same(int x, int y) {

        return find(x) == find(y);

    }



};



//Union-Find-End



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

//Seg-Tree-End



//dfs

//vector<int> v[100004];

//bool went[100004];

//void dfs(int x) {

//    went[x] = true;

//    for (int i = 0; i < (int)v[x].size(); i++) {

//        if (!went[v[x][i]]) {

//            dfs(v[x][i]);

//        }

//    }

//}



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



int kai(int x, int y) {

    int res = 1;

    for (int i = x - y + 1; i <= x; i++) {

        res *= i; res %= mod;

    }

    return res;

}



int comb(int x, int y) {

    if (y > x)return 0;

    return kai(x, y) * modpow(kai(y, y), mod - 2) % mod;

}



int fukugen(vector<int> l) {

    int ans = 0;

    for (int i = 0; i < (int)l.size(); i++) {

        ans *= 10;

        ans += l[i];

    }

    return ans;

}

int nanjyo(int n){

    int ans=0;

    while (n>1) {

        ans++;

        n/=2;

    }

    return ans;

}

bool intersect(pair<pair<int,int>, pair<int,int>>p1 ,pair<pair<int,int>,pair<int,int>>p2){

    int men11=(p2.first.first-p1.first.first)*(p2.second.second-p1.first.second)-(p2.second.first-p1.first.first)*(p2.first.second-p1.first.second);

    int men12=(p2.first.first-p1.second.first)*(p2.second.second-p1.second.second)-(p2.second.first-p1.second.first)*(p2.first.second-p1.second.second);

    int men21=(p1.first.first-p2.first.first)*(p1.second.second-p2.first.second)-(p1.second.first-p2.first.first)*(p1.first.second-p2.first.second);

    int men22=(p1.first.first-p2.second.first)*(p1.second.second-p2.second.second)-(p1.second.first-p2.second.first)*(p1.first.second-p2.second.second);

    

    return ((signbit(men11)) ^ (signbit(men12))) && ((signbit(men21)) ^ (signbit(men22)));

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

int yakusuu(int x){

    int ans=0;

    for (int i=1; i*i<=x; i++) {

        if (!(x%i)) {

            if (i*i==x) {

                ans++;

            }

            else ans+=2;

        }

    }

    return ans;

}

#define rep(i,n) for(int i=0;i<n;i++)

#define REP(i,n) for(int i=1;i<=n;i++)

//Library-End



int n,m,k[14],s[14][14],p[14],ans;

signed main(){

    cin>>n>>m;

    rep(i, m){

        cin>>k[i];

        rep(j, k[i]){

            cin>>s[i][j];

            s[i][j]--;

        }

    }

//    cout<<s[3][0]<<' '<<s[3][1]<<' '<<s[3][2]<<endl;

    rep(i, m)cin>>p[i];

    rep(i, mypow(2, n)){

        bitset<20> bits(i);

        bool ok=1;

        rep(j, m){

            int cnt=0;

            rep(l, k[j]){

                if(bits[s[j][l]])cnt++;

//                if (i==3) {

//                    cout<<'p'<<s[i][l]<<' '<<i<<' '<<l<<endl;

//                }

            }

            if ((cnt&1)!=p[j]) {

                ok=0;

                break;

            }

//            if (i==3) {

//                cout<<cnt<<endl;

//            }

        }

        if (ok) {

            ans++;

        }

    }

    cout<<ans<<endl;

}


