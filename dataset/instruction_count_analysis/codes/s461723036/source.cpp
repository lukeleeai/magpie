#include "stdc++.h"

using namespace std;

typedef pair<int,int> P;

typedef long long ll;

const int MAX_N = 1<<17;

const ll INF = INT_MAX;



/*

  RMQ and RUQ

  ?????????????°?????????????(RMQ)

  ????????????????????´??????(RUQ)

 */



class RMQ2{

public : 

  struct data{

    bool type; //0 - empty   , 1 - update

    ll value;

  };

  ll n,dat[2*MAX_N-1];

  data td[2*MAX_N-1];

  

  RMQ2(){

    n=MAX_N;

    memset(td,0,sizeof(td));

    for(int i=0;i<2*n-1;i++)dat[i]=INF;

  }

  RMQ2(int n_){

    n=1;

    while(n<n_)n*=2;

    memset(td,0,sizeof(td));

    for(int i=0;i<2*n-1;i++)dat[i]=INF;

  }

  

  //[a,b)?????????x????????´???update(a,b,x)

  ll update(int a,int b,int x,bool flg=true,int k=0,int l=0,int r=-1){

    if(r==-1) r=n;

    if(r<=a||b<=l)return flg? dat[k]:INF;

    if(a<=l&&r<=b){

      if(flg==true){

	td[k]=(data){1,x};

	dat[k]=x;

      }

      return dat[k];

    }

    

    if(td[k].type){

      dat[k*2+1]=dat[k*2+2]=td[k].value;

      td[k*2+1]=td[k*2+2]=(data){1,td[k].value};

      td[k].type=0;

    }

    

    ll vl=update(a,b,x,flg,k*2+1,l,(l+r)/2);

    ll vr=update(a,b,x,flg,k*2+2,(l+r)/2,r);

    if(flg==true)dat[k]=min(vl,vr);

    return min(vl,vr);

  }

  

  //[a,b)???????°????????????????find(a,b);

  ll find(int a,int b){return update(a,b,0,false);};

};





int main(){

  int q,n;

  cin>>n>>q;

  RMQ2 T(n);

  while(q--){

    int cmd,s,t,x;

    scanf("%d%d%d",&cmd,&s,&t);

    if(cmd==0)cin>>x,T.update(s,t+1,x);

    else cout <<T.find(s,t+1)<<endl;

  }

  return 0;

}