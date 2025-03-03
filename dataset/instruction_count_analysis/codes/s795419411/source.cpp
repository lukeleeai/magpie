#include"stdc++.h"

using namespace std;

typedef long long ll;

#define MAX 100005

struct BIT{

  void init(){  memset(bit,0,sizeof(bit));  }

  ll bit[MAX];

  void set(int r,ll x){

    r=MAX-r-1;

    while(r){

      bit[r]=max(bit[r],x);

      r-=(r&-r);

    }

  }

  ll get(int i){

    i=MAX-i-1;

    ll res=0;

    while(i<MAX){

      res=max(res,bit[i]);

      i+=(i&-i);

    }

    return res;

  }

};



int n;

ll sum,ans,a[MAX];

BIT A;



int main(){

  A.init();

  cin>>n;

  for(int i=1;i<=n;i++){

    cin>>a[i];

    sum+=a[i];

    ll k=A.get(a[i]);

    ans=max(ans,k+a[i]);

    A.set(a[i],k+a[i]);

  }

  cout<<sum-ans<<endl;

  return 0;

}