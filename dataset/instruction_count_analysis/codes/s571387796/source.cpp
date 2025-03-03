//

/*==========================================================*/

/*    Template ver 2017-0720    |    Created by JollyBee    */

/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */

/*==========================================================*/

#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

typedef vector<pii> vii;

const double EPS=(double)1e-9;

const double PI=(double)acos(-1.0);

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define pob pop_back

#define pf push_front

#define pof pop_front

#define FOR(i,n) for(int i=0;i<n;i++)

#define REPP(i,l,r,c) for(int i=l;i<=r;i+=c)

#define REP(i,l,r) REPP(i,l,r,1)

#define FORD(i,n) for(int i=n-1;i>=0;i--)

#define REVV(i,l,r,c) for(int i=l;i>=r;i-=c)

#define REV(i,l,r) REVV(i,l,r,1)

//random

int irand(int lo, int hi){

    return (((double)rand())/(RAND_MAX+1.0)) * (hi-lo+1) + lo;

}

//ll to string

string toString(ll x) {

    stringstream ss;

    ss << x;

    return ss.str();

}

//string to ll

ll toNumber(string S) {

    ll ret;

    sscanf(S.c_str(),"%lld",&ret);

    return ret;

}

// std::fill(start, end, value);

// for(auto it: DS){}



const int INF=(int)2e9;

const ll MOD=(ll)1e9+7;

/*==========================================================*/

/*                     END OF TEMPLATE                      */

/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */

/*==========================================================*/



ll f(ll n, ll mult){

    return n / mult;

}



int main(){

    ll a,b,c,d; scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    ll lcm = c * d / __gcd(c,d);

    ll range = b - a + 1;

    ll mult_c = f(b,c) - f(a-1,c);

    ll mult_d = f(b,d) - f(a-1,d);

    ll mult_cd = f(b,lcm) - f(a-1,lcm);

    printf("%lld\n", range - mult_c - mult_d + mult_cd);

    return 0;

}
