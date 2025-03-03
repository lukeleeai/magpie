// #pragma GCC optimize("Ofast","unroll-loops")

// #pragma GCC push_options

// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// #include"stdc++.h"

// #include <xmmintrin.h>

// #include <immintrin.h>

// using namespace::std;

// __attribute__((constructor))void init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}

// #include<ext/pb_ds/assoc_container.hpp>

// #include<ext/pb_ds/tree_policy.hpp>

// #include <ext/pb_ds/priority_queue.hpp>

// #include<ext/pb_ds/tag_and_trait.hpp>

// template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

// template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

// template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;

// template<typename T>using pqueue =__gnu_pbds::priority_queue<T, less<T>,__gnu_pbds::rc_binomial_heap_tag>;

// typedef long long lint;

// #define INF (1LL<<60)

// #define IINF (1<<30)

// #define EPS (1e-10)

// #define MOD 1000000007

// typedef vector<lint> vec;

// typedef vector<vector<lint>> mat;

// template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}

// template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}

// template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}

// template<typename T>inline void output2(T t){for(auto i:t)output(i);}

// template<typename T>inline void _output(T t){bool f=0;for(int i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}

// template<typename T>inline void _output2(T t){for(int i=0;i<t.size();i++)output(t[i]);}

// #define rep(i,n) for(lint i=0;i<lint(n);++i)

// #define repi(i,a,b) for(int i=int(a);i<(int)(b);++i)

// #define rrep(i,n) for(int i=int(n)-1;i>=0;--i)

// #define rrepi(i,a,b) for(int i=int(b)-1;i>=int(a);--i)

// #define irep(i) for(int i=0;;++i)

// #define all(n) begin(n),end(n)

// inline lint gcd(lint A,lint B){return B?gcd(B,A%B):A;}

// inline lint lcm(lint A,lint B){return A/gcd(A,B)*B;}

// inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}

// inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}

// const vector<lint> dx={-1,1,0,0,1,1,-1,-1};

// const vector<lint> dy={0,0,-1,1,1,-1,1,-1};

// #define SUM(v) accumulate(all(v),0LL)

// auto call=[](auto f,auto... args){return f(f,args...);};



// class mint {

//   using u64 = std::uint_fast64_t;

//     public:

//     u64 a;

//     constexpr mint(const u64 x = 0)noexcept:a(x % MOD){}

//     constexpr u64 &value()noexcept{return a;}

//     constexpr const u64 &value() const noexcept {return a;}

//     constexpr mint operator+(const mint rhs)const noexcept{return mint(*this) += rhs;}

//     constexpr mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}

//     constexpr mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}

//     constexpr mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}

//     constexpr mint &operator+=(const mint rhs) noexcept {

//         a += rhs.a;

//         if (a >= MOD)a -= MOD;

//         return *this;

//     }

//     constexpr mint &operator-=(const mint rhs) noexcept {

//         if (a<rhs.a)a += MOD;

//         a -= rhs.a;

//         return *this;

//     }

//     constexpr mint &operator*=(const mint rhs) noexcept {

//         a = a * rhs.a % MOD;

//         return *this;

//     }

//     constexpr mint operator++(int n) const noexcept {

//         return mint(*this) +=1;

//     }

//     constexpr mint operator--(int n) const noexcept {

//         return mint(*this) -=1;

//     }

//     constexpr mint &operator/=(mint rhs) noexcept {

//         u64 exp=MOD-2;

//         while (exp) {

//             if (exp % 2) {

//                 *this *= rhs;

//             }

//             rhs *= rhs;

//             exp /= 2;

//         }

//         return *this;

//     }

//     mint pow(long long n){

//         long long x=a;

//         mint ret = 1;

//         while(n>0) {

//             if(n&1)(ret*=x);

//             (x*=x)%=MOD;

//             n>>=1;

//         }

//         return ret;

//     }

//     mint inv()const{

//         int _a=a,b=MOD,u=1,v=0,t;

//         while(b>0) {

//             t=_a/b;

//             swap(_a-=t*b,b);

//             swap(u-=t*v,v);

//         }

//         return mint(u);

//     }

//     mint comb(auto b){

//         using lint=long long;

//         static bool init=1;

//         static lint fac[1000001],ifac[1000001];

//         if(init){

//             init=0;

//             fac[0]=1;

//             ifac[0]=1;

//             auto mod_pow=[&](lint x,lint n){

//                 lint ans = 1;

//                 while(n != 0){

//                     if(n&1)ans=ans*x%MOD;

//                     x=x*x%MOD;

//                     n=n>>1;

//                 }

//                 return ans;

//             };

//             for(int i=0;i<1000000;i++){

//                 fac[i+1]=fac[i]*(i+1)%MOD;

//                 ifac[i+1]=ifac[i]*mod_pow(i+1, MOD-2)%MOD;

//             }

//         }

//         if(a==0&&b==0)return 1;

//         if((lint)a<b||a<0)return 0;

//         lint tmp=ifac[a-b]*ifac[b]%MOD;

//         return tmp*fac[a]%MOD;

//     }

    

//     friend ostream& operator<<(ostream& lhs, const mint& rhs) noexcept {

//         lhs << rhs.a;

//         return lhs;

//     }

//     friend istream& operator>>(istream& lhs,mint& rhs) noexcept {

//         lhs >> rhs.a;

//         return lhs;

//     }

// };

// inline mint fact(lint a){return a?fact(a-1)*a:1;}



#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<string.h>

#include <time.h>



int main(void){

    long n,i,a=1;

    scanf("%ld",&n);

    char s[n+1];

    scanf("%s",s);

    // printf("%s",s);

    for(i=1;i<n;i++){

        if(s[i]!=s[i-1]) a++;

    }   



    printf("%ld\n",a);

    return 0;

}