#include"stdc++.h" 

using namespace std;

typedef long long ll;

template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}

template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}

// URLD

long double dx[4]={0,1,-1,0};

long double dy[4]={1,0,0,-1};

long double eps = 1e-6;

long double pi = acos(-1);



template< int mod = 1000000007 >

struct ModInt {

    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {

        if((x += p.x) >= mod) x -= mod;

        return *this;

    }

    ModInt &operator-=(const ModInt &p) {

        if((x += mod - p.x) >= mod) x -= mod;

        return *this;

    }

    ModInt &operator*=(const ModInt &p) {

        x = (int) (1LL * x * p.x % mod);

        return *this;

    }

    ModInt &operator/=(const ModInt &p) {

        *this *= p.inverse();

        return *this;

    }



    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }



    ModInt inverse() const {

        int a = x, b = mod, u = 1, v = 0, t;

        while(b > 0) {

            t = a / b;

            swap(a -= t * b, b);

            swap(u -= t * v, v);

        }

        return ModInt(u);

    }



    ModInt pow(int64_t n) const {

        ModInt ret(1), mul(x);

        while(n > 0) {

            if(n & 1) ret *= mul;

            mul *= mul;

            n >>= 1;

        }

        return ret;

    }



    friend ostream &operator<<(ostream &os, const ModInt &p) {

        return os << p.x;

    }



    friend istream &operator>>(istream &is, ModInt &a) {

        int64_t t;

        is >> t;

        a = ModInt< mod >(t);

        return (is);

    }



    static int get_mod() { return mod; }

};



const int mod1 = 1000000103;

const int mod2 = 1000000483;

using mint1 = ModInt<mod1>;

using mint2 = ModInt<mod2>;



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout << fixed << setprecision(30);



    int n;

    cin>>n;

    ll x[n];

    ll y[n];

    ll a[n],b[n];

    for(int i=0;i<n;i++){

        cin>>x[i];

        y[i] = x[i];

        if(i)a[i-1] = x[i]^x[i-1];

    }

    a[n-1] = x[n-1]^x[0];



    ModInt<1000000103> ret1=0,mul1=10009;

    ModInt<1000000483> ret2=0,mul2=10007;

    for(int i=0;i<n;i++){

        cin>>x[i];

        if(i)b[i-1] = x[i]^x[i-1];

    }

    b[n-1] = x[n-1]^x[0];

    for(int i=0;i<n;i++){

        ret1 = ret1*mul1 + mint1(b[i]);

        ret2 = ret2*mul2 + mint2(b[i]);

    }

    mint1 h1=0;

    mint2 h2=0;

    vector<array<ll,2>> v;

    for(int i=0;i<n;i++){

        h1 = h1*mul1 + mint1(a[i]);

        h2 = h2*mul2 + mint2(a[i]);

    }

    mint1 p1 = mint1(mul1).pow(n-1);

    mint2 p2 = mint2(mul2).pow(n-1);

    for(int i=0;i<n;i++){

        if(h1 == ret1 && h2 == ret2){

            v.push_back({i,x[0]^y[i]});

        }

        h1 -= mint1(a[i])*p1;

        h2 -= mint2(a[i])*p2;

        h1 = h1 * mul1 + mint1(a[i]);

        h2 = h2 * mul2 + mint2(a[i]);

    }

    for(auto i:v){

        cout << i[0] << " " << i[1] << "\n";

    }



    



}