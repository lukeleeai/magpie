#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp>

#define sz(v)   ((int)(v).size())

#define  all(v)    ((v).begin()),((v).end())

#define  allr(v)    ((v).rbegin()),((v).rend())

#define   pb         push_back

#define   mp         make_pair

#define    Lcm(a,b)  ((a*b)/(__gcd(a,b)))

#define    clr(v,d)      memset( v, d ,sizeof(v))

#define    PI            acos(-1)

typedef  long long     ll ;

typedef  unsigned long long     ull ;

const long double eps= (1e-9);

using namespace std;

using namespace __gnu_pbds;

int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}

void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const int N=200000+9,mod=1e9+7;

map< pair<ll,ll> ,pair<ll,ll> > mb;

ll P[N];

pair<ll,ll> get_slope(ll a,ll b){



  ll gg=__gcd(a,b);

  a/=gg;

  b/=gg;



  if(b<0){

    a*=-1;

    b*=-1;

  }



  return mp(a,b);

}

int main(){

    GO();

    int n;

    cin>>n;

    P[0]=1;

    for(int i=1;i<=n;i++) P[i]=(P[i-1]*2)%mod;

    int Z=0;

    for(int i=0;i<n;i++){

        ll a,b;

        cin>>a>>b;

        if(a==0&&b==0){

            Z++;

            continue;

        }

        pair<ll,ll> p=get_slope(a,b);

        a=p.first;

        b=p.second;

        if(a<=0){

            mb[mp(b,-a)].second++;

        }

        else{

            mb[mp(a,b)].first++;

        }

    }

    ll ans=1;

    for(auto it=mb.begin();it!=mb.end();it++){

        ans*=(((P[(*it).second.first])+(P[(*it).second.second])-1)+mod)%mod;

        ans%=mod;

    }

    cout<<((ans-1+Z)%mod+mod)%mod<<"\n";



}












































































