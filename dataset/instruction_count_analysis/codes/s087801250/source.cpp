#include"stdc++.h"

using namespace std;

#define int long long

struct BIT{

  vector<int> bit;

  int n;

  BIT(){init();}

  BIT(int n):n(n){init();}

  void init(){

    bit.clear();

    bit.resize(n+1,0);

  }

  int sum(int i){

    int s=0;

    while(i>0){

      s+=bit[i];

      i-=i&-i;

    }

    return s;

  }

  void add(int i,int x){

    while(i<=n){

      bit[i]+=x;

      i+=i&-i;

    }

  }

};

int MOD=1000000007LL;

int s[114514],t[114514];

int fact[114514];

void init(int mod){

  fact[0]=fact[1]=1;

  for(int i=2;i<114514;i++)

    fact[i]=(fact[i-1]*i)%MOD;

}

signed main(){

  int n;

  init(MOD);

  while(cin>>n,n){

    BIT bit(n);

    for(int i=0;i<n;i++) s[i]=i+1;

    int r;

    cin>>r;

    for(int i=0;i<r;i++){

      int a,b;

      cin>>a>>b;

      a--;b--;

      swap(s[a],s[b]);

    }

    for(int i=n-1;i>=0;i--){

      t[i]=bit.sum(s[i]);

      bit.add(s[i],1);

    }

    int ans=0;

    for(int i=0;i<n;i++){

      (ans+=t[i]*fact[n-1-i])%=MOD;

    }

    cout<<ans<<endl;

  }

  return 0;

}