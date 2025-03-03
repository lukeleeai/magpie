//FIRST THINK THEN CODE.



#include "stdc++.h"

 

 

using namespace std;

 

typedef long long ll;

 

//#define MOD 998244353

#define rep(i,a,b) for(ll i=a;i<b;++i)

#define rrep(i,a,b) for(ll i=a;i>b;--i)

#define FOR(i,n)  for(ll i=0;i<n;i++)

#define vi vector<int>

#define vl vector<ll>

#define ld long double

#define vvi vector<vector<int>>

#define vvl vector<vector<long long>>

#define pii pair<int,int>

#define pll pair<long,long>

#define vpii vector<pii>

#define vpll vector<pll>

#define ff first

#define ss second

#define pb push_back

#define mp make_pair

#define lb lower_bound

#define ub upper_bound

#define bs binary_search

#define d1(x) cout<<(x)<<endl

#define d2(x,y) cout<<(x)<<" "<<(y)<<endl

#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl

#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl

#define PI 3.1415926535897932384626433832795

#define fix(f,n) fixed<<setprecision(n)<<f

#define all(x) x.begin(),x.end()

#define endl "\n"

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define popcount(x) __builtin_popcountll(x)



const int M=1000000007;

const int MM=998244353;





 

ll newmod(ll a,ll b)

 {

  return ((a%b)+b)%b;

}

 

 

ll powM(ll a,ll b,ll m )

{ 

  if(m<=1)return 0;

  a%=m;

  ll ans=1LL;

  while(b)

  {

    if(b&1)ans=ans*a%m;

    a=a*a%m;

    b>>=1;

  }

 

return ans;

}





 

ll poww(ll a,ll b)

{ 

  

  ll ans=1;

  while(b)

  {

    if(b&1)ans=ans*a;

    a=a*a;

    b>>=1;

  }

 

return ans;



}



template<typename T,typename F>

void chmax( T &a,F b){

  if(b>a)a=b;

}



template<typename T,typename F>

void chmin( T &a,F b){

  if(b<a)a=b;

}



const ll N=1e4+5;



ll vis[N];



vpll arr[N];



ll d[N];





struct cmp{



bool operator()(pll a,pll b)const{

return a.ff>b.ff;



}

};











int main()

{ 



IOS;



ll t;cin>>t;



while(t--){



ll n;cin>>n;



vl profit[n+1],loss[n+2];



vl k(n+1),l(n+1),r(n+1);



vl allot(n+1);



for(int i=1;i<=n;i++){

  cin>>k[i]>>l[i]>>r[i];

  profit[k[i]].pb(i);

  loss[k[i]+1].pb(i);

}



set<pll>s;



for(int i=n;i>=1;i--){

for(auto ind:profit[i]){

  s.insert({l[ind]-r[ind],ind});

  // kisi i ke liye we are inserting all the 

  //positions(from [i,n]) for which l>r and

  // in increasing order of (l-r).

  // agar set is not empty ,then we can place the 

  // last element in the set(currently) at the

  // i'th postion.  

}

if(!s.empty()){

  auto it=s.rbegin();

  if((*it).ff>0){

    allot[(*it).ss]=1;

    s.erase(*it);

  } 

}



}



s.clear();



for(int i=2;i<=n;i++){

  for(auto ind:loss[i]){

    s.insert({r[ind]-l[ind],ind});

  }



if(!s.empty()){

  auto it=s.rbegin();

  if((*it).ff>0){

    allot[(*it).ss]=1;

    s.erase(*it);

  }

}



}



ll ans=0;



for(int i=1;i<=n;i++){

  if(!allot[i])ans+=min(l[i],r[i]);

  else ans+=max(l[i],r[i]);

}



cout<<ans<<endl;





}







return 0;

 

}
