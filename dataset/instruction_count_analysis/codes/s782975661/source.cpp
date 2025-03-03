#include"stdc++.h"

#define N (1<<17)

#define INF 0

using namespace std;

typedef long long ll;



class RMQ{

public:

  ll n,dat[2*N-1];



  //?????????

  RMQ(){

    n=N;

    for(int i=0;i<n;i++) dat[i]=INF;

  }

  

  //k???????????????a????????´

  void update(int k,ll a){

    k+=n-1;

    dat[k]=a;

    while(k>0){

      k=(k-1)/2;

      dat[k]=min(dat[k*2+1],dat[k*2+2]);

    }

  }



  //[a,b)???????°????????±??????? query(a,b,0,0,n)

  ll query(int a,int b,int k=0,int l=0,int r=N){

    if(r<=a||b<=l)return INF;

    if(a<=l&&r<=b)return dat[k];

    ll vl=query(a,b,k*2+1,l,(l+r)/2);

    ll vr=query(a,b,k*2+2,(l+r)/2,r);

    return min(vl,vr);

  }

};





int main(){  

  ll n,x[N];

  cin>>n;

  RMQ rmq;

  for(int i=0;i<n;i++) cin>>x[i];



  ll sum=n*(1+n)/2,ans=sum;

  for(int i=0;i<n;i++){

    ll mx=-rmq.query(1,x[i])+x[i];

    ans=min(ans,sum-mx);

    rmq.update(x[i],-mx);

  }

  cout <<ans<<endl;

  return 0;

}