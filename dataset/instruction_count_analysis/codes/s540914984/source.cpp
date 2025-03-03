#include"stdc++.h"

#define me(a,x) memset(a,x,sizeof(a))

#define IN freopen("in.txt","r",stdin);

#define OUT freopen("out.txt","w",stdout);

#define sc scanf

#define itn int

#define STR clock_t startTime = clock();

#define END clock_t endTime = clock();cout << double(endTime - startTime) / CLOCKS_PER_SEC *1000<< "ms" << endl;

using namespace std;

const int N=1e6+5;

const long long mod=1e9+7;

const long long mod2=998244353;

const int oo=0x7fffffff;

const int sup=0x80000000;

typedef long long ll;

typedef unsigned long long ull;

template <typename it>void db(it *begin,it *end){while(begin!=end)cout<<(*begin++)<<" ";puts("");}

template <typename it>

string to_str(it n){string s="";while(n)s+=n%10+'0',n/=10;reverse(s.begin(),s.end());return s;}

template <typename it>int o(it a){cout<<a<<endl;return 0;}

inline ll mul_64(ll x,ll y,ll c){return (x*y-(ll)((long double)x/c*y)*c+c)%c;}

inline ll ksm(ll a,ll b,ll c){ll ans=1;for(;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;return ans;}

inline void exgcd(ll a,ll b,ll &x,ll &y){if(!b)x=1,y=0;else exgcd(b,a%b,y,x),y-=x*(a/b);}

int n;

ll a[N];

ll dp[65];

bool vis[65]={0};

void insert(ll x){

  for(int i=60;i>=0;i--){

    if(!vis[i])continue; 

    if(x>>i&1){

      if(!dp[i]){

        dp[i]=x;

        break;

      }

      x^=dp[i];

    }

  }

}

ll Q(){

  ll ans=0;

  for(int i=60;i>=0;i--)if(vis[i]&&(ans>>i&1)==0)ans^=dp[i];

  return ans;

}

int main(){

  cin>>n;

  ll sum=0;

  for(int i=1;i<=n;i++){

    sc("%lld",&a[i]);

    sum^=a[i];

  }

  for(int i=0;i<=60;i++){

    if(sum>>i&1)continue;

    vis[i]=1;

  }

  for(int i=1;i<=n;i++)insert(a[i]);

  ll g=Q();

  o((sum^g)+g);

}