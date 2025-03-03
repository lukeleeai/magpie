#include"stdc++.h"

using namespace std;

#define int long long



#define MOD 1000000007

#define MAX_N 100000

#define MAX_P 200005

int fact[MAX_P];

int extgcd(int a,int b,int& x,int& y){

  int d=a;

  if(b!=0){

    d=extgcd(b,a%b,y,x);

    y-=(a/b)*x;

  }else{

    x=1;y=0;

  }

  return d;

}

int mod_inverse(int a,int m){

  int x,y;

  extgcd(a,m,x,y);

  return (m+x%m)%m;

}



int euler_phi(int n){

  int res=n;

  for(int i=2;i*i<=n;i++){

    if(n%i==0){

      res=res/i*(i-1);

      for(;n%i==0;n/=i);

    }

  }

  if(n!=1) res=res/n*(n-1);

  return res;

}



int euler[MAX_N];



void euler_phi2(){

  for(int i=0;i<MAX_N;i++) euler[i]=i;

  for(int i=2;i<MAX_N;i++){

    if(euler[i]==i){

      for(int j=i;j<MAX_N;j+=i) euler[j]=euler[j]/i*(i-1);

    }

  }

}



int mod_pow(int x,int n,int mod){

  int res=1;

  while(n>0){

    if(n&1) (res*=x)%=mod;

    (x*=x)%=mod;

    n>>=1;

  }

  return res;

}



void init(int p){

  fact[0]=1;

  for(int i=1;i<MAX_P;i++) fact[i]=(fact[i-1]*i)%p;

}



int mod_fact(int n,int p,int& e){

  e=0;

  if(n==0) return 1;

  int res=mod_fact(n/p,p,e);

  e+=n/p;

  if(n/p%2!=0)return res*(p-fact[n%p]) %p;

  return res*fact[n%p]%p;

} 

int mod_comb(int n,int k,int p){

  if(n==k||k==0) return 1;

  int e1,e2,e3;

  int a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);

  if(e1>e2+e3) return 0;

  return a1*mod_inverse(a2*a3%p,p)%p;

}





int lcm(int x,int y){

  return x/__gcd(x,y)*y;

}





struct RLQ{

  int n;

  vector<int> dat;

  const int def=1;

  RLQ(){}

  RLQ(int n_){init(n_);}

  RLQ(int n_,int* a){init(n_);construct(n_,a);}

  void init(int n_){

    n=1;

    while(n<n_) n*=2;

    dat.clear();

    dat.resize(2*n-1,def);

  }

  void construct(int n_, int* a){

    for(int i=0;i<n_;i++) dat[i+n-1]=a[i];

    for(int i=n-2;i>=0;i--)

      dat[i]=lcm(dat[i*2+1],dat[i*2+2]);

  }

  void update(int k,int a){

    k+=n-1;

    dat[k]=a;

    while(k>0){

      k=(k-1)/2;

      dat[k]=lcm(dat[k*2+1],dat[k*2+2]);

    }

  }

  int query(int a,int b,int k,int l,int r){

    if(r<=a||b<=l) return def;

    if(a<=l&&r<=b) return dat[k];

    int vl=query(a,b,k*2+1,l,(l+r)/2);

    int vr=query(a,b,k*2+2,(l+r)/2,r);

    return lcm(vl,vr);

  }

  int query(int a,int b){

    return query(a,b,0,0,n);

  }

};



struct RSQ{

  int n;

  vector<int> dat;

  const int def=0;

  RSQ(){}

  RSQ(int n_){init(n_);}

  RSQ(vector<int> v){init(v);}

  void init(int n_){

    n=1;

    while(n<n_) n*=2;

    dat.clear();

    dat.resize(2*n-1,def);

  }

  void init(vector<int> v){

    int n_=v.size();

    init(n_);

    for(int i=0;i<n_;i++)

      dat[i+n-1]=v[i];

    for(int i=n-2;i>=0;i--)

      dat[i]=(dat[i*2+1]+dat[i*2+2])%MOD;

  }

  void update(int k,int a){

    k+=n-1;

    dat[k]=a;

    while(k>0){

      k=(k-1)/2;

      dat[k]=(dat[k*2+1]+dat[k*2+2])%MOD;

    }

  }

  int query(int a,int b,int k,int l,int r){

    if(r<=a||b<=l) return def;

    if(a<=l&&r<=b) return dat[k]%MOD;

    int vl=query(a,b,k*2+1,l,(l+r)/2);

    int vr=query(a,b,k*2+2,(l+r)/2,r);

    return (vl+vr)%MOD;

  }

  int query(int a,int b){

    return query(a,b,0,0,n);

  }

};





signed main(){

  int n,q;

  cin>>n>>q;

  int p[n];

  for(int i=0;i<n;i++) cin>>p[i];

  for(int i=0;i<n;i++) p[i]--;

  vector<int> a(n,0);

  int c[n];

  int x=1;

  for(int i=0;i<n;i++){

    int k=i;

    a[i]=i+1;

    c[i]=1;

    while(p[k]!=i){

      k=p[k];

      (a[i]+=k+1)%=MOD;

      c[i]++;

    }

    //cout<<c[i]<<":"<<a[i]<<endl;

    x=lcm(x,c[i]);

  }

  //cout<<x<<endl;

  for(int i=0;i<n;i++)

    (a[i]*=(x/c[i])%MOD)%=MOD;

  RLQ rlq(n,c);

  RSQ rsq(a);

  init(MOD);

  for(int i=0;i<q;i++){

    int l,r;

    cin>>l>>r;

    l--;

    //cout<<l<<" "<<r<<endl;

    int k=rlq.query(l,r);

    int ans=rsq.query(l,r);

    //cout<<k<<" "<<ans<<endl;

    (ans*=mod_inverse((x/k)%MOD,MOD))%=MOD;

    cout<<ans<<endl;

  }

  

  return 0;

}