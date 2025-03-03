#pragma GCC optimize("O3")

#include"stdc++.h" 

using namespace std;

using ll=long long;

typedef  unsigned long long int ull;

typedef pair<ll,ll> P;

template<class T> using V=vector<T>; 

#define fi first

#define se second

#define all(v) (v).begin(),(v).end()

const ll inf=(1e18);

//const ll mod=998244353;

const ll mod=1000000007;

//ios_base::sync_with_stdio(false);

//cin.tie(NULL);

ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}

ll lcm(ll c,ll d){return c/gcd(c,d)*d;}

struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){

ll n,a,b,c,d;

cin>>n>>a>>b>>c>>d;

if(a>b)swap(a,b);

V<ll> suml1(n+1,0),suml2(n+1,0);

suml1[0]=a,suml2[0]=a;

for(int i=0;i<n-1;i++){

    suml1[i+1]+=suml1[i]+d;

    suml2[i+1]+=suml2[i]-d;

}

V<ll> sumr1(n+1,0),sumr2(n+1,0);

sumr1[n-1]=b;sumr2[n-1]=b;

for(int i=n-1;i>0;i--){

    sumr1[i-1]+=sumr1[i]+d;

    sumr2[i-1]+=sumr2[i]-d;

}

bool ch=false;

for(ll i=0;i<n;i++){

    if(!(suml1[i]<sumr1[i]-(n-1-i)*(d-c)||suml1[i]-i*(d-c)>sumr1[i]))ch=true;

    if(!(suml1[i]<sumr2[i]||suml1[i]-i*(d-c)>sumr2[i]+(n-1-i)*(d-c)))ch=true;

}

if(ch)cout<<"YES"<<"\n";

else cout<<"NO"<<"\n";

}


