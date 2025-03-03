#include"stdc++.h"



#define rep(i,n) for(int i = 0; i < (n); i++)

#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)

#define rep1(i,n) for(int i = 1; i <= (n); i++)

#define rrep1(i,n) for(int i = (n); i > 0; i--)



#define ll long long

#define pi pair<int, int>

#define pll pair<ll, ll>



#define MOD 1000000007

#define INF 1000000000000000LL



using namespace std;



#define MAXKN 100001



bool is_prime[MAXKN];



// x^n in mod

ll modpow(ll x, ll n, ll mod){

  if(n==0) return 1;



  if(n%2==0){

    return modpow(x*x%mod, n/2, mod) % mod;

  }else{

    return x * modpow(x, (n-1), mod) % mod;

  }

}



int main(){

  ll n, k;cin>>n>>k;

  rep(i, MAXKN)is_prime[i]=true;

  is_prime[0]=is_prime[1]=false;

  for(int i=2; i<MAXKN; i++){

    for(int j=i*2; j<MAXKN; j+=i)is_prime[j]=false;

  }



  ll no1_count = 0;

  ll result = 0;



  ll one_count = modpow(k, n, MOD);

  vector<ll> counts;

  counts.push_back(0);

  rep1(a, k) counts.push_back( modpow(k/a, n, MOD) );



  rrep1(a, k){

    for(int i=a*2; i<=k; i+=a) counts[a]=(counts[a]-counts[i]+MOD)%MOD;

    result += a*counts[a];

    result %= MOD;

  }



  cout<<result<<endl;



  return 0;

}


