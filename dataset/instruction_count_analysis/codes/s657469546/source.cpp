#include"stdc++.h"

using namespace std;

typedef long long ll;

#define MAX_N 100005

ll mod=1e9+7;



ll mul(ll a,ll b){

  return (a*b)%mod;

}



int bit[MAX_N];

void add(int i,int x){

  i++;



  while(i<MAX_N){

    bit[i]+=x;

    i+=(i&-i);

  }

}



int sum(int i){

  i++;



  int res=0;

  while(i){

    res+=bit[i];

    i-=(i&-i);

  }

  return res;

}



ll N,R,a,b;

ll fact[MAX_N];

int t[MAX_N];



int main(){

  fact[0]=1;

  for(int i=1;i<MAX_N;i++)

    fact[i]=mul(fact[i-1],i);



  while(1){

    scanf("%lld",&N);

    if(N==0)break;

    scanf("%lld",&R);

    memset(bit,0,sizeof(bit));

    for(int i=0;i<N;i++)t[i]=i;



    for(int i=0;i<R;i++){

      scanf("%lld %lld",&a,&b);

      a--,b--;

      swap(t[a],t[b]);

    }



    ll ans=0;

    for(int i=0;i<N;i++){

      ll num=t[i];

      ll cnt=num-sum(num);

      ans+= mul(fact[N-1-i],cnt);

      ans%=mod;

      add(t[i],1);

    }



    printf("%lld\n",ans);

  }

  return 0;

}