#include "stdc++.h"

#include <vector>

#include <numeric>

#define PI 3.14159265358979323846

#define MAXINF (1e18L)

#define INF (1e9L)

#define EPS (1e-9)

#define MOD ((ll)(1e9+7))

#define REP(i, n) for(int i=0;i<int(n);++i)

#define Rep(i,sta,n) for(int i=sta;i<n;i++)

#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)

#define ALL(v) v.begin(),v.end()

#define FIND(v,x) (binary_search(ALL(v),(x)))

#define SORT(v) sort(ALL(v))

#define RSORT(v) sort(ALL(v));reverse(ALL(v))

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;

#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

#define Yes(n) cout<<((n)?"Yes":"No")<<endl

#define YES(n) cout<<((n)?"YES":"NO")<<endl

#define pb push_back

#define fi first

#define se second

using namespace std;

template<class A>void pr(A a){cout << (a) << endl;}

template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}

template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}

template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll,ll> pll;



// ll c[2001][2001];

// ll comb(int a, int b){

//     if(a<b||b<0) return 0;

//     if(c[a][b] != 0) return c[a][b];

//     if(a == b || b == 0) return c[a][b] = 1;

//     return c[a][b] = (comb(a-1, b-1) + comb(a-1, b)) % MOD;

// }





vector<ll> inv,fact,invfact;

void mod_build(int n=101010){

    fact.resize(n+1);

    inv.resize(n+1);

    invfact.resize(n+1);

    fact[0]=inv[0]=invfact[0]=1;

    inv[1]=1;

    REP(i,n){

        fact[i+1]=fact[i]*(i+1)%MOD;

        if(i>0)inv[i+1]=MOD-inv[MOD%(i+1)]*(MOD/(i+1))%MOD;

        invfact[i+1]=invfact[i]*inv[i+1]%MOD;

    }

}

ll perm(int n,int k){

    if(n<0||k<0||k>n)return 0;

    return fact[n]*invfact[n-k]%MOD;

}

ll comb(int n,int k){

    if(n<0||k<0||k>n)return 0;

    return (fact[n]*invfact[n-k]%MOD)*invfact[k]%MOD;

}





int main(void)

{

    int n,k;

    cin >> n >> k;

    mod_build(n);

    REP(i, k){

        pr((comb(n-k+1,i+1)*comb(k-1, i))%MOD);

    }

}