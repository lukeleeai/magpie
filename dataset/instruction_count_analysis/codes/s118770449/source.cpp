#include "stdc++.h"

#pragma GCC optimize("Ofast", "unroll-loops")

#define ll long long 

#define pii pair<int, int>

#define ull unsigned ll

#define f first

#define s second

#define FOR(i,a,b) for (int i=(a); i<(b); i++)

#define REP(i,n) for (int i=0; i<(n); i++)

#define RREP(i,n) for (int i=(n-1); i>=0; i--)

#define ALL(x) x.begin(),x.end()

#define SZ(x) x.size()

#define SQ(x) (x)*(x)

#define MNTO(a,b) a = min(a,(__typeof__(a))(b))

#define MXTO(a,b) a = max(a,(__typeof__(a))(b))

#define pb push_back

#define debug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;



// #define int ll



const int maxn = 1e5+5;

const int iinf = 1<<29;

const ll inf = 1ll<<60;

const ll mod = 1e9+7;





void GG(){cout<<"No\n"; exit(0);}



ll pow(ll a, ll n){ // a^n % mod

    ll re=1;

    while (n>0){

        if (n&1) re = re*a %mod;

        a = a*a %mod;

        n>>=1;

    }

    return re;

}



ll inv (ll b){

    if (b==1) return b;

    return (mod-mod/b) * inv(mod%b) % mod;

}



int n; 



int id (int x){

    if (x>n) return x-n;

    return x;

}



main(){

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin>>n;

    if (1<<((int)log2(n))==n) {

        GG();

    }

    cout<<"Yes\n";

    cout<<1+n<<' '<<2+n<<'\n';

    for (int i = 2; i<=n-1; i+=2){

        cout<<i<<' '<<1<<'\n';

        cout<<i+1<<' '<<1<<'\n';

        cout<<i+1+n<<' '<<i<<'\n';

        cout<<i+n<<' '<<i+1<<'\n';

    }

    if (n%2==0){

        int lb = n&(-n);

        int cp = n-lb;

        cout<<n<<' '<<lb+1<<'\n';

        cout<<n+n<<' '<<cp<<'\n';

    }

}