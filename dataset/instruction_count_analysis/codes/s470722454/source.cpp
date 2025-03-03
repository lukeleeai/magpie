/*

* じょえチャンネル

* 高評価・チャンネル登録よろしくおねがいします！

* https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ

*/



#include "stdc++.h"





#define f(i,n) for(int i=0;i<(n);i++)





#define inf (int)(3e18)

#define int long long

#define mod (int)(1000000007)



#define intt long long

#define itn long long

#define P pair<int,int>



#define rep(i,n) for(int i=0;i<n;i++)

#define REP(i,n) for(int i=1;i<=n;i++)



#define ALL(v) v.begin(),v.end()



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

//Library-End



class modInt {

    int value, modulo;

public:

    modInt() : value(0), modulo(mod) { value = 0; }

    template<typename T>

    modInt(T value = 0, int modulo = mod) : value(value), modulo(modulo) {

        if (value < 0) {

            value = -value;

            value %= modulo;

            value = -value;

            value += modulo;

        }

        this->value = value % modulo;

    }

    inline operator int()const { return value; }

    inline modInt& operator+=(modInt x) {

        value += x.value;

        if (value >= modulo)value -= modulo;

        return *this;

    }

    inline modInt& operator++() {

        if (value == modulo - 1)value = 0;

        else value++;

        return *this;

    }

    inline modInt& operator-()const {

        return modInt(0) -= *this;

    }

    inline modInt& operator-=(modInt x) {

        value -= x.value;

        if (value < 0)value += modulo;

        return *this;

    }

    inline modInt& operator--() {

        if (value == 0)value = modulo - 1;

        else value--;

        return *this;

    }

    inline modInt& operator*=(modInt x) {

        value = value * x.value % modulo;

        return *this;

    }

    inline modInt& operator/=(modInt x) {

        return operator*=(x.inv());

    }

    inline modInt inv() {

        return modpow(*this, modulo - 2);

    }

    template<typename T> modInt operator+(T x) { return modInt(*this) += x; }

    template<typename T> modInt& operator+=(T x) { return operator+=(modInt(x, modulo)); }

    template<typename T> modInt operator-(T x) { return modInt(*this) -= x; }

    template<typename T> modInt& operator-=(T x) { return operator-=(modInt(x, modulo)); }

    template<typename T> modInt operator*(T x) { return modInt(*this) *= x; }

    template<typename T> modInt& operator*=(T x) { return operator*=(modInt(x, modulo)); }

    template<typename T> modInt operator/(T x) { return modInt(*this) /= x; }

    template<typename T> modInt& operator/=(T x) { return operator/=(modInt(x, modulo)); }

};

istream& operator>>(istream& ist, modInt& x) {

    int a;

    ist >> a;

    x = a;

    return ist;

}

struct edge{

    P root;

    int cost;

};

int n,m,s,t,u[100004],v[100004],a[100004],b[100004],now;

vector<edge> sunuke[100004],yen[100004];

int kyos[100004],kyoy[100004],ans[100004];



signed main(){

    cin>>n>>m>>s>>t;

    rep(i,m){

        fin(u[i]);fin(v[i]);fin(a[i]);fin(b[i]);

        sunuke[u[i]].push_back({{u[i],v[i]},b[i]});

        sunuke[v[i]].push_back({{v[i],u[i]},b[i]});

        yen[u[i]].push_back({{u[i],v[i]},a[i]});

        yen[v[i]].push_back({{v[i],u[i]},a[i]});

    }

    priority_queue<P,vector<P>,greater<P>> sup;

    sup.push({0,t});

    fill(kyos, kyos+100003, inf);

    kyos[t]=0;

    while (!sup.empty()) {

        P p=sup.top();

        sup.pop();

        int v=p.second;

        rep(i,sunuke[v].size()){

            edge e = sunuke[v][i];

            if (kyos[e.root.second] > kyos[v] + e.cost) {

                kyos[e.root.second] = kyos[v] + e.cost;

                sup.push(P(kyos[e.root.second], e.root.second));

            }

        }

    }



    sup.push({0,s});

    fill(kyoy, kyoy+100003, inf);

    kyoy[s]=0;

    while (!sup.empty()) {

        P p=sup.top();

        sup.pop();

        int v=p.second;

        rep(i,yen[v].size()){

            edge e = yen[v][i];

            if (kyoy[e.root.second] > kyoy[v] + e.cost) {

                kyoy[e.root.second] = kyoy[v] + e.cost;

                sup.push(P(kyoy[e.root.second], e.root.second));

            }

        }

    }

    fill(ans, ans+100003, inf);

    for (int i=n; i>=0; i--) {

        chmin(ans[i], ans[i+1]);

        chmin(ans[i], kyoy[i]+kyos[i]);

    }

    int l=mypow(10, 15);

    rep(i,n){

        fout(l-ans[i+1]);fendl;

    }

}








