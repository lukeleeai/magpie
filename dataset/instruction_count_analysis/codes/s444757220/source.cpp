#include <iostream>

#include <cstdio>

#include <vector>

#include <algorithm>

#include <cmath>

#include <numeric>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <time.h>

#include <list>

#include <bitset>



using namespace std;

typedef long long ll;

template<class T=ll> 

T in(){T x;cin>>x;return (x);}

template<class T> 

void print(T &x){cout<<x<<"\n";}

#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define reps(x,c) for(auto x:c)

#define all(x) begin(x), end(x)

#define pb(a) emplace_back(a) 

#define mp(a,b) make_pair((a),(b))

#define pl pair<ll,ll>

#define INF 2147483600

#define MOD 1000000007

#define fi first

#define se second

#define dbg(x) cerr << #x"="<< (x) << "\n"

#define dbgv(x) cerr<<#x<<"\n";reps(y,x){cerr<<y<<" ";}cerr<<"\n"



int main(){

  ll n=in(),a=in(),b=in(),ans=1e9;

  vector<ll> h(n);

  rep(i,n){

    scanf("%lld",&h[i]);

  }

  sort(all(h));

  ll left=1,right=1e9,mid,cnt=0;

  while (right!=left+1) {

    mid =(right+left)/2;

    cnt=0;

    rep(i,n){

      ll temp=h[i]-b*mid;

      if(temp>0){

        cnt+=ceil(1.0*temp/(a-b));

      }

    }

    bool flg=cnt<mid;

    if(flg){

      right=mid;

    }else left=mid;

  }

  cnt=0;

  rep(i,n){

    ll temp=h[i]-b*left;

    if(temp>0){

      cnt+=ceil(1.0*temp/(a-b));

    }

  }

  ans=min(ans,max(cnt,left));

  cnt=0;

  rep(i,n){

    ll temp=h[i]-b*right;

    if(temp>0){

      cnt+=ceil(1.0*temp/(a-b));

    }

  }

  ans=min(ans,max(cnt,right));

  cout<<ans<<endl;

  return 0;

}