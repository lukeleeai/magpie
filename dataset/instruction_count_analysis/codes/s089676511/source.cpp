#include"stdc++.h"

using namespace std;

typedef long long ll;



struct query{

  int type;//0=empty, 1=add

  ll value;

  query(int a=0,ll b=0):type(a),value(b) {}

};



query s[(1<<18)];

ll t[(1<<18)];



void compute(int k,int l,int r){

  query q=s[k];

  s[k].type=s[k].value=0;

  if(q.type==0||r-l==1)return;

  

  int m=(l+r)/2;

  

  s[k*2+1].type=1;

  s[k*2+1].value+=q.value;

  t[k*2+1]+=q.value*(m-l);

  

  s[k*2+2].type=1;

  s[k*2+2].value+=q.value;

  t[k*2+2]+=q.value*(r-m);

}



void Add(int a,int b,ll x,int k=0,int l=0,int r=(1<<17)){

  if(b<=l || r<=a)return;

  compute(k,l,r);

  if(a<=l && r<=b){

    s[k]=query(1,x);

    t[k]+=x*(r-l);

  }else{

    int m=(l+r)/2;

    Add(a,b,x,k*2+1,l,m);

    Add(a,b,x,k*2+2,m,r);

    t[k]=t[k*2+1]+t[k*2+2];

  }

}



ll Get(int a,int b,int k=0,int l=0,int r=(1<<17)){

  if(b<=l || r<=a)return 0;

  compute(k,l,r);

  if(a<=l && r<=b){

    return t[k];

  }else{

    int m=(l+r)/2;

    ll lv=Get(a,b,k*2+1,l,m);

    ll rv=Get(a,b,k*2+2,m,r);

    return lv+rv;

  }

}







int main(){



  int n,q,type,a,b,x;

  scanf("%d %d",&n,&q);

  

  while(q--){

    scanf("%d",&type);

    if(type==0){

      scanf("%d %d %d",&a,&b,&x);

      b++;

      Add(a,b,x);

    }else{

      scanf("%d %d",&a,&b);

      b++;

      printf("%lld\n",Get(a,b));

    }

  }

  return 0;

}